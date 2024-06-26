#include "DeleteUndoCommand.h"

DeleteUndoCommand::DeleteUndoCommand(QList<QGraphicsItem *> items, ModelGraphicsScene *scene, QUndoCommand *parent)
    : QUndoCommand(parent), _myComponentItems(new QList<ComponentItem>()), _myConnectionItems(new QList<GraphicalConnection *>()), _myDrawingItems(new QList<DrawingItem>()), _myGroupItems(new QList<GroupItem>()), _myGraphicsScene(scene) {

    // filtra cada tipo de item possivel em sua respectiva lista
    for (QGraphicsItem *item : items) {
        if (GraphicalModelComponent *component = dynamic_cast<GraphicalModelComponent *>(item)) {
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

            _myComponentItems->append(componentItem);
        } else if (GraphicalConnection *connection = dynamic_cast<GraphicalConnection *>(item)) {
            _myConnectionItems->append(connection);
        } else if (QGraphicsItemGroup *group = dynamic_cast<QGraphicsItemGroup *> (item)){
            GroupItem groupItem;

            groupItem.group = group;
            groupItem.initialPosition = group->pos();

            for (int i = 0; i < group->childItems().size(); i++) {
                GraphicalModelComponent * component = dynamic_cast<GraphicalModelComponent *>(groupItem.group->childItems().at(i));

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
        } else {
            DrawingItem drawingItem;

            drawingItem.myDrawingItem = item;
            drawingItem.initialPosition = item->pos();

            _myDrawingItems->append(drawingItem);
        }
    }

    setText(QObject::tr("Delete"));
}

DeleteUndoCommand::~DeleteUndoCommand() {
    delete _myComponentItems;
    delete _myConnectionItems;
    delete _myDrawingItems;
    delete _myGroupItems;
}

void DeleteUndoCommand::undo() {
    // adiciona tudo que e grafico
    // comeca adicionando os componentes e suas conexoes
    for (int i = 0; i < _myComponentItems->size(); ++i) {
        ComponentItem componentItem = _myComponentItems->at(i);

        _myGraphicsScene->addItem(componentItem.graphicalComponent);
        componentItem.graphicalComponent->setPos(componentItem.initialPosition);

        for (int j = 0; j < _myComponentItems->at(i).inputConnections.size(); ++j) {
            GraphicalConnection *connection = componentItem.inputConnections.at(j);
            _myGraphicsScene->addItem(connection);
        }

        for (int j = 0; j < _myComponentItems->at(i).outputConnections.size(); ++j) {
            GraphicalConnection *connection = componentItem.outputConnections.at(j);
            _myGraphicsScene->addItem(connection);
        }
    }

    // adiciona as conexoes selecionadas individualmente
    for (int i = 0; i < _myConnectionItems->size(); ++i) {
        GraphicalConnection *connection = _myConnectionItems->at(i);
        _myGraphicsScene->addItem(connection);
    }

    // varre todos os outros itens simples do tipo QGraphicsItem e adiciona da tela
    for (int i = 0; i < _myDrawingItems->size(); ++i) {
        DrawingItem drawingItem = _myDrawingItems->at(i);
        drawingItem.myDrawingItem->setPos(drawingItem.initialPosition);
        _myGraphicsScene->addItem(drawingItem.myDrawingItem);
    }

    // volta os itens do grupo e o grupo na tela
    for (int i = 0; i < _myGroupItems->size(); ++i) {
        GroupItem groupItem = _myGroupItems->at(i);

        for (int j = 0; j < groupItem.myComponentItems.size(); ++j) {
            ComponentItem componentItem = groupItem.myComponentItems.at(j);
            componentItem.graphicalComponent->setPos(componentItem.initialPosition);

            _myGraphicsScene->addItem(componentItem.graphicalComponent);

            for (int j = 0; j < componentItem.inputConnections.size(); ++j) {
                GraphicalConnection *connection = componentItem.inputConnections.at(j);
                _myGraphicsScene->addItem(connection);
            }

            for (int j = 0; j < componentItem.outputConnections.size(); ++j) {
                GraphicalConnection *connection = componentItem.outputConnections.at(j);
                _myGraphicsScene->addItem(connection);
            }
        }
    }

    // agora comeca a adicionar o que se deve no modelo
    // varre todos os GraphicalModelComponent
    for (int i = 0; i < _myComponentItems->size(); ++i) {
        ComponentItem componentItem = _myComponentItems->at(i);

        //add in model (apenas para delete)
        _myGraphicsScene->getSimulator()->getModels()->current()->insert(componentItem.graphicalComponent->getComponent());

        //add graphically
        _myGraphicsScene->getGraphicalModelComponents()->append(componentItem.graphicalComponent);

        //refaz as conexões
        _myGraphicsScene->redoConnections(componentItem.graphicalComponent, &componentItem.inputConnections, &componentItem.outputConnections);
    }

    // varre todos os GraphicalConnection e realiza a conexao
    for (int i = 0; i < _myConnectionItems->size(); ++i) {
        GraphicalConnection *connection = _myConnectionItems->at(i);

        // verifico se a conexao ainda nao existe (ela pode ser uma conexao que foi refeita no connectComponents)
        // por exemplo, pode ter uma conexao selecionada que foi eliminada anteriormente pois ela fazia parte de um componente
        // entao ao refazer as conexoes do componente, ela ja foi religada
        if (!_myGraphicsScene->getGraphicalConnections()->contains(connection)) {
            _myGraphicsScene->connectComponents(connection, nullptr, nullptr);
        }
    }

    // volta os grupos no modelo
    for (int i = 0; i < _myGroupItems->size(); ++i) {
        GroupItem groupItem = _myGroupItems->at(i);
        QList<GraphicalModelComponent *> *componentsGroup = new QList<GraphicalModelComponent *>();

        for (int j = 0; j < groupItem.myComponentItems.size(); ++j) {
            ComponentItem componentItem = groupItem.myComponentItems.at(j);

            //add in model (apenas para delete)
            _myGraphicsScene->getSimulator()->getModels()->current()->insert(componentItem.graphicalComponent->getComponent());

            //add graphically
            _myGraphicsScene->getGraphicalModelComponents()->append(componentItem.graphicalComponent);

            //refaz as conexões
            _myGraphicsScene->redoConnections(componentItem.graphicalComponent, &componentItem.inputConnections, &componentItem.outputConnections);

            componentsGroup->append(componentItem.graphicalComponent);
        }

        groupItem.group->update();

        _myGraphicsScene->groupModelComponents(componentsGroup, groupItem.group);

        groupItem.group->setPos(groupItem.initialPosition);

        delete componentsGroup;
    }

    _myGraphicsScene->notifyGraphicalModelChange(GraphicalModelEvent::EventType::CREATE, GraphicalModelEvent::EventObjectType::OTHER, nullptr);

    // atualiza a cena
    _myGraphicsScene->update();
}

void DeleteUndoCommand::redo() {
    // remove as conexoes selecionadas individualmente
    for (int i = 0; i < _myConnectionItems->size(); ++i) {
        GraphicalConnection *connection = _myConnectionItems->at(i);
        _myGraphicsScene->removeItem(connection);
    }

    // remove tudo que e grafico
    // comeca removendo os componentes e suas conexoes
    for (int i = 0; i < _myComponentItems->size(); ++i) {
        ComponentItem componentItem = _myComponentItems->at(i);

        componentItem.graphicalComponent->setOldPosition(componentItem.graphicalComponent->pos());

        for (int j = 0; j < _myComponentItems->at(i).inputConnections.size(); ++j) {
            GraphicalConnection *connection = componentItem.inputConnections.at(j);
            _myGraphicsScene->removeItem(connection);
        }

        for (int j = 0; j < _myComponentItems->at(i).outputConnections.size(); ++j) {
            GraphicalConnection *connection = componentItem.outputConnections.at(j);
            _myGraphicsScene->removeItem(connection);
        }

        _myGraphicsScene->removeItem(componentItem.graphicalComponent);
    }

    // varre todos os outros itens simples do tipo QGraphicsItem e remove da tela
    for (int i = 0; i < _myDrawingItems->size(); ++i) {
        DrawingItem drawingItem = _myDrawingItems->at(i);

        //add graphically
        _myGraphicsScene->removeDrawing(drawingItem.myDrawingItem);
    }

    // agora remove o que deve ser removido do modelo
    // varre todos os GraphicalModelComponent
    for (int i = 0; i < _myComponentItems->size(); ++i) {
        ComponentItem componentItem = _myComponentItems->at(i);

        _myGraphicsScene->removeComponent(componentItem.graphicalComponent);
    }

    // varre todos os GraphicalConnection
    for (int i = 0; i < _myConnectionItems->size(); ++i) {
        GraphicalConnection *connection = _myConnectionItems->at(i);
        GraphicalModelComponent *source = _myGraphicsScene->findGraphicalModelComponent(connection->getSource()->component->getId());
        GraphicalModelComponent *destination = _myGraphicsScene->findGraphicalModelComponent(connection->getDestination()->component->getId());

        // verifica se a conexao ainda existe, pois ela pode ja ter sido removida caso fizesse parte de um componente que foi removido
        if (_myGraphicsScene->getGraphicalConnections()->contains(connection)) {
            // se ela existe, a remove
            _myGraphicsScene->removeGraphicalConnection(connection, source, destination);
        } else {
            // se nao existe, quer dizer que a conexao faz parte de um componente que foi removido, e portando ela ja foi removida
            // entao a remove da lista
            _myConnectionItems->removeOne(connection);
        }
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
