#include "PasteUndoCommand.h"

PasteUndoCommand::PasteUndoCommand(QList<GraphicalModelComponent *> *graphicalComponents, QList<GraphicalConnection *> *connections, QList<QGraphicsItemGroup *> *groups, QList<QGraphicsItem *> *drawing, ModelGraphicsScene *scene, QUndoCommand *parent)
    : QUndoCommand(parent), _myComponentItems(new QList<ComponentItem>()), _myConnectionItems(new QList<GraphicalConnection *>()), _myDrawingItems(new QList<DrawingItem>()), _myGroupItems(new QList<GroupItem>()), _myGraphicsScene(scene) {

    for (int i = 0; i < connections->size(); i++) {
        _myConnectionItems->append(connections->at(i));
    }

    for (int i = 0; i < drawing->size(); i++) {
        drawing->at(i)->setX(drawing->at(i)->pos().x() + drawing->at(i)->boundingRect().width()/2);
        drawing->at(i)->setY(drawing->at(i)->pos().y() - drawing->at(i)->boundingRect().height()/2);
        _myGraphicsScene->insertOldPositionItem(drawing->at(i), drawing->at(i)->pos());

        DrawingItem drawingItem;
        drawingItem.myDrawingItem = drawing->at(i);
        drawingItem.initialPosition = drawingItem.myDrawingItem->pos();
        _myDrawingItems->append(drawingItem);
    }

    for (int i = 0; i < graphicalComponents->size(); i++) {
        GraphicalModelComponent *component = graphicalComponents->at(i);
        ComponentItem componentItem;

        componentItem.graphicalComponent = component;
        componentItem.graphicalComponent->setX(componentItem.graphicalComponent->pos().x() + componentItem.graphicalComponent->boundingRect().width()/2);
        componentItem.graphicalComponent->setY(componentItem.graphicalComponent->pos().y() - componentItem.graphicalComponent->boundingRect().height()/2);
        componentItem.graphicalComponent->setOldPosition(componentItem.graphicalComponent->pos());
        componentItem.initialPosition = component->pos();

        if (!component->getGraphicalInputPorts().empty() && !component->getGraphicalInputPorts().at(0)->getConnections()->empty()) {
            for (int j = 0; j < component->getGraphicalInputPorts().at(0)->getConnections()->size(); ++j) {
                componentItem.inputConnections.append(component->getGraphicalInputPorts().at(0)->getConnections()->at(j));
            }
        }

        for (int j = 0; j < component->getGraphicalOutputPorts().size(); ++j) {
            GraphicalComponentPort *port = component->getGraphicalOutputPorts().at(j);

            if (!port->getConnections()->empty())
                componentItem.outputConnections.append(port->getConnections()->at(0));
        }

        _myComponentItems->append(componentItem);
    }

    if (groups != nullptr) {
        for (int i = 0; i < groups->size(); i++) {
            QGraphicsItemGroup *group = groups->at(i);
            GroupItem groupItem;

            groupItem.group = group;

            QList<GraphicalModelComponent *> components = _myGraphicsScene->getListComponentsGroup()[group];
            for (int j = 0; j < components.size(); j++) {
                GraphicalModelComponent * component = dynamic_cast<GraphicalModelComponent *>(components.at(j));

                ComponentItem componentItem;

                componentItem.graphicalComponent = component;
                componentItem.initialPosition = component->pos();

                if (!component->getGraphicalInputPorts().empty() && !component->getGraphicalInputPorts().at(0)->getConnections()->empty()) {
                    for (int j = 0; j < component->getGraphicalInputPorts().at(0)->getConnections()->size(); ++j) {
                        componentItem.inputConnections.append(component->getGraphicalInputPorts().at(0)->getConnections()->at(j));
                    }
                }

                for (int j = 0; j < component->getGraphicalOutputPorts().size(); ++j) {
                    GraphicalComponentPort *port = component->getGraphicalOutputPorts().at(j);

                    if (!port->getConnections()->empty())
                        componentItem.outputConnections.append(port->getConnections()->at(0));
                }

                groupItem.myComponentItems.append(componentItem);
            }
            _myGroupItems->append(groupItem);
        }
    }

    setText(QObject::tr("Paste"));
}

PasteUndoCommand::~PasteUndoCommand() {}

void PasteUndoCommand::undo() {
    // remove as conexoes selecionadas individualmente
    for (int i = 0; i < _myConnectionItems->size(); ++i) {
        GraphicalConnection *connection = _myConnectionItems->at(i);
        _myGraphicsScene->removeItem(connection);
    }

    // remove tudo que e grafico
    // comeca removendo os componentes e suas conexoes
    for (int i = 0; i < _myComponentItems->size(); ++i) {
        ComponentItem componentItem = _myComponentItems->at(i);

        if (!componentItem.graphicalComponent->group())
            _myGraphicsScene->removeItem(componentItem.graphicalComponent);

        for (int j = 0; j < _myComponentItems->at(i).inputConnections.size(); ++j) {
            GraphicalConnection *connection = componentItem.inputConnections.at(j);
            _myGraphicsScene->removeItem(connection);
        }

        for (int j = 0; j < _myComponentItems->at(i).outputConnections.size(); ++j) {
            GraphicalConnection *connection = componentItem.outputConnections.at(j);
            _myGraphicsScene->removeItem(connection);
        }
    }

    // varre todos os outros itens simples do tipo QGraphicsItem e remove da tela
    for (int i = 0; i < _myDrawingItems->size(); ++i) {      
        DrawingItem drawingItem = _myDrawingItems->at(i);

        //remove graphically
        _myGraphicsScene->removeDrawing(drawingItem.myDrawingItem);
    }

    // agora remove o que deve ser removido do modelo
    // varre todos os GraphicalModelComponent
    for (int i = 0; i < _myComponentItems->size(); ++i) {
        ComponentItem componentItem = _myComponentItems->at(i);

        if (!componentItem.graphicalComponent->group())
            _myGraphicsScene->removeComponent(componentItem.graphicalComponent);
    }

    // varre todos os GraphicalConnection
    for (int i = 0; i < _myConnectionItems->size(); ++i) {
        GraphicalConnection *connection = _myConnectionItems->at(i);
        GraphicalModelComponent *source = _myGraphicsScene->findGraphicalModelComponent(connection->getSource()->component->getId());
        GraphicalModelComponent *destination = _myGraphicsScene->findGraphicalModelComponent(connection->getDestination()->component->getId());

        _myGraphicsScene->removeGraphicalConnection(connection, source, destination);
    }

    for (int i = 0; i < _myGroupItems->size(); ++i) {
        QGraphicsItemGroup *group = _myGroupItems->at(i).group;
        _myGraphicsScene->removeGroup(group);
    }


    GraphicalModelEvent::EventType eventType = GraphicalModelEvent::EventType::REMOVE;
    GraphicalModelEvent::EventObjectType eventObjectType = GraphicalModelEvent::EventObjectType::OTHER;

    _myGraphicsScene->notifyGraphicalModelChange(eventType, eventObjectType, nullptr);

    _myGraphicsScene->update();
}

void PasteUndoCommand::redo() {
    // adiciona tudo que e grafico
    // comeca adicionando os componentes e suas conexoes
    for (int i = 0; i < _myComponentItems->size(); ++i) {
        ComponentItem componentItem = _myComponentItems->at(i);

        componentItem.graphicalComponent->setPos(componentItem.initialPosition);
        _myGraphicsScene->addItem(componentItem.graphicalComponent);

        for (int j = 0; j < _myComponentItems->at(i).inputConnections.size(); ++j) {
            GraphicalConnection *connection = componentItem.inputConnections.at(j);
            _myGraphicsScene->addItem(connection);
        }

        for (int j = 0; j < _myComponentItems->at(i).outputConnections.size(); ++j) {
            GraphicalConnection *connection = componentItem.outputConnections.at(j);
            _myGraphicsScene->addItem(connection);
        }

        componentItem.graphicalComponent->setSelected(true);
    }

    // adiciona as conexoes selecionadas individualmente
    for (int i = 0; i < _myConnectionItems->size(); ++i) {
        GraphicalConnection *connection = _myConnectionItems->at(i);
        _myGraphicsScene->addItem(connection);
        connection->setSelected(true);
    }

    // varre todos os outros itens simples do tipo QGraphicsItem e adiciona da tela
    for (int i = 0; i < _myDrawingItems->size(); ++i) {
        DrawingItem drawingItem = _myDrawingItems->at(i);
        _myGraphicsScene->getGraphicalDrawings()->append(drawingItem.myDrawingItem);
        drawingItem.myDrawingItem->setPos(drawingItem.initialPosition);
        _myGraphicsScene->addItem(drawingItem.myDrawingItem);
        drawingItem.myDrawingItem->setSelected(true);
    }

    // agora comeca a adicionar o que se deve no modelo
    // varre todos os GraphicalModelComponent
    for (int i = 0; i < _myComponentItems->size(); ++i) {
        ComponentItem componentItem = _myComponentItems->at(i);

        //add in model (apenas para delete)
        _myGraphicsScene->getSimulator()->getModels()->current()->insert(componentItem.graphicalComponent->getComponent());

        _myGraphicsScene->getAllComponents()->append(componentItem.graphicalComponent);
        //add graphically
        _myGraphicsScene->getGraphicalModelComponents()->append(componentItem.graphicalComponent);

        //refaz as conexões
        _myGraphicsScene->redoConnections(componentItem.graphicalComponent, &componentItem.inputConnections, &componentItem.outputConnections);
    }

    // varre todos os GraphicalConnection e realiza a conexao
    for (int i = 0; i < _myConnectionItems->size(); ++i) {
        GraphicalConnection *connection = _myConnectionItems->at(i);

        _myGraphicsScene->connectComponents(connection, nullptr, nullptr);

    }

    // volta os grupos no modelo
    for (int i = 0; i < _myGroupItems->size(); ++i) {
        GroupItem groupItem = _myGroupItems->at(i);
        QList<GraphicalModelComponent *> *componentsGroup = new QList<GraphicalModelComponent *>();

        for (int j = 0; j < groupItem.myComponentItems.size(); ++j) {
            ComponentItem componentItem = groupItem.myComponentItems.at(j);

            if (componentItem.graphicalComponent->group())
                groupItem.group->removeFromGroup(componentItem.graphicalComponent);
            componentsGroup->append(componentItem.graphicalComponent);
        }

        _myGraphicsScene->groupModelComponents(componentsGroup, groupItem.group);
        groupItem.group->update();

        delete componentsGroup;
    }

    _myGraphicsScene->notifyGraphicalModelChange(GraphicalModelEvent::EventType::CREATE, GraphicalModelEvent::EventObjectType::OTHER, nullptr);


    // atualiza a cena
    _myGraphicsScene->update();
}
