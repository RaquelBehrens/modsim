#include "MoveUndoCommand.h"
#include "ModelGraphicsScene.h"

MoveUndoCommand::MoveUndoCommand(QList<QGraphicsItem*> gmc, ModelGraphicsScene *scene, QList<QPointF> &oldPos, QList<QPointF> &newPos, QUndoCommand *parent)
    : QUndoCommand(parent), _myGraphicalModelComponent(gmc), _myGraphicsScene(scene), _myOldPos(oldPos), _myNewPos(newPos), _firstExecution(true) {
    setText(QObject::tr("Move"));
}

MoveUndoCommand::~MoveUndoCommand() {}

void MoveUndoCommand::undo() {

    for (int i = 0; i < _myGraphicalModelComponent.size(); i++) {
        if (GraphicalModelComponent *item = dynamic_cast<GraphicalModelComponent *> (_myGraphicalModelComponent[i])) {
            QPointF oldPos = _myOldPos[i];
            item->setPos(oldPos);
            item->setOldPosition(oldPos);
        } else {
            QPointF oldPos = _myOldPos[i];
            _myGraphicalModelComponent[i]->setPos(oldPos);
            _myGraphicsScene->insertOldPositionItem(_myGraphicalModelComponent[i], oldPos);
        }
    }

    _myGraphicsScene->update();
}

void MoveUndoCommand::redo() {
    if (!_firstExecution) {
        for (int i = 0; i < _myGraphicalModelComponent.size(); i++) {
            if (GraphicalModelComponent *component = dynamic_cast<GraphicalModelComponent *> (_myGraphicalModelComponent[i])) {
                QPointF newPos = _myNewPos[i];
                component->setPos(newPos);
            } else {
                QPointF newPos = _myNewPos[i];
                _myGraphicalModelComponent[i]->setPos(newPos);
            }
        }
    }
    _firstExecution = false;

    _myGraphicsScene->update();
}
