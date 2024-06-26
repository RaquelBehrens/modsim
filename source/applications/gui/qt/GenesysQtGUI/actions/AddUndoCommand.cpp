#include "AddUndoCommand.h"
#include <QDebug>

AddUndoCommand::AddUndoCommand(QGraphicsItem *item, ModelGraphicsScene *scene, QUndoCommand *parent)
    : QUndoCommand(parent), _myGraphicsScene(scene), _firstExecution(true) {

    _myComponentItem.graphicalComponent = nullptr;
    _myConnectionItem = nullptr;
    _myDrawingItem = nullptr;

    // filtra o tipo do item
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

        _myComponentItem = componentItem;
    } else if (GraphicalConnection *connection = dynamic_cast<GraphicalConnection *>(item)) {
        _myConnectionItem = connection;
    } else {
        _myDrawingItem = item;
    }


    setText(QObject::tr("Add"));
}

AddUndoCommand::~AddUndoCommand() {}

void AddUndoCommand::undo() {
    // remove as conexoes individuais
    if (_myConnectionItem != nullptr)
        _myGraphicsScene->removeItem(_myConnectionItem);

    // remove o que e grafico
    if (_myComponentItem.graphicalComponent != nullptr) {
        for (int j = 0; j < _myComponentItem.inputConnections.size(); ++j) {
            GraphicalConnection *connection = _myComponentItem.inputConnections.at(j);
            _myGraphicsScene->removeItem(connection);
        }

        for (int j = 0; j < _myComponentItem.outputConnections.size(); ++j) {
            GraphicalConnection *connection = _myComponentItem.outputConnections.at(j);
            _myGraphicsScene->removeItem(connection);
        }

        _myGraphicsScene->removeItem(_myComponentItem.graphicalComponent);
    }

    // remove os itens simples da tela
    if (_myDrawingItem != nullptr)
        _myGraphicsScene->removeDrawing(_myDrawingItem);


    // agora remove o que deve ser removido do modelo
    if (_myComponentItem.graphicalComponent != nullptr)
        _myGraphicsScene->removeComponent(_myComponentItem.graphicalComponent, true);

    // varre todos os GraphicalConnection
    if (_myConnectionItem != nullptr) {
        GraphicalModelComponent *source = _myGraphicsScene->findGraphicalModelComponent(_myConnectionItem->getSource()->component->getId());
        GraphicalModelComponent *destination = _myGraphicsScene->findGraphicalModelComponent(_myConnectionItem->getDestination()->component->getId());

        // verifica se a conexao ainda existe, pois ela pode ja ter sido removida caso fizesse parte de um componente que foi removido
        if (_myGraphicsScene->getGraphicalConnections()->contains(_myConnectionItem)) {
            // se ela existe, a remove
            _myGraphicsScene->removeGraphicalConnection(_myConnectionItem, source, destination, true);
        } else {
            // se nao existe, quer dizer que a conexao faz parte de um componente que foi removido, e portando ela ja foi removida
            // entao a limpa sua referencia
            _myConnectionItem = nullptr;
        }
    }

    // atualiza a cena
    _myGraphicsScene->update();
}

void AddUndoCommand::redo() {
    // adiciona tudo que e grafico
    // comeca adicionando o componente e suas conexoes
    if (_myComponentItem.graphicalComponent != nullptr) {
        _myGraphicsScene->addItem(_myComponentItem.graphicalComponent);

        for (int j = 0; j < _myComponentItem.inputConnections.size(); ++j) {
            GraphicalConnection *connection = _myComponentItem.inputConnections.at(j);
            _myGraphicsScene->addItem(connection);
        }

        for (int j = 0; j < _myComponentItem.outputConnections.size(); ++j) {
            GraphicalConnection *connection = _myComponentItem.outputConnections.at(j);
            _myGraphicsScene->addItem(connection);
        }
    }

    // add as conexoes individuais
    if (_myConnectionItem != nullptr) {
        _myGraphicsScene->addItem(_myConnectionItem);
    }

    // remove os itens simples da tela
    if (_myDrawingItem != nullptr) {
        _myGraphicsScene->addItem(_myDrawingItem);
    }

    // agora comeca a adicionar o que se deve no modelo
    if (_myComponentItem.graphicalComponent != nullptr) {
        //add graphically
        _myGraphicsScene->getGraphicalModelComponents()->append(_myComponentItem.graphicalComponent);

        if (!_firstExecution) {
            //add in model (apenas para delete)
            _myGraphicsScene->getSimulator()->getModels()->current()->insert(_myComponentItem.graphicalComponent->getComponent());

            //refaz as conexões
            _myGraphicsScene->redoConnections(_myComponentItem.graphicalComponent, &_myComponentItem.inputConnections, &_myComponentItem.outputConnections);

            _myGraphicsScene->notifyGraphicalModelChange(GraphicalModelEvent::EventType::CREATE, GraphicalModelEvent::EventObjectType::COMPONENT, _myComponentItem.graphicalComponent);

        } else {
            _firstExecution = false;
        }
    }

    // realiza a conexao do objeto GraphicalConnection
    if (_myConnectionItem != nullptr) {
        // verifico se a conexao ainda nao existe (ela pode ser uma conexao que foi refeita no connectComponents)
        // por exemplo, pode ter uma conexao selecionada que foi eliminada anteriormente pois ela fazia parte de um componente
        // entao ao refazer as conexoes do componente, ela ja foi religada
        if (!_myGraphicsScene->getGraphicalConnections()->contains(_myConnectionItem)) {
            GraphicalModelComponent* sourceComp = _myGraphicsScene->findGraphicalModelComponent(_myConnectionItem->getSource()->component->getId());
            GraphicalModelComponent* destComp = _myGraphicsScene->findGraphicalModelComponent(_myConnectionItem->getDestination()->component->getId());

            _myGraphicsScene->clearPorts(_myConnectionItem, sourceComp, destComp);

            _myGraphicsScene->connectComponents(_myConnectionItem, sourceComp, destComp, true);
        }
    }

    // atualiza a cena
    _myGraphicsScene->update();
}
