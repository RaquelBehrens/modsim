#include "GroupUndoCommand.h"
#include "ModelGraphicsScene.h"

GroupUndoCommand::GroupUndoCommand(QList<GraphicalModelComponent *> graphicalComponents, ModelGraphicsScene *scene, QUndoCommand *parent)
    :QUndoCommand(parent), _myGraphicalComponents(graphicalComponents), _group(new QGraphicsItemGroup()), _myGraphicsScene(scene){

    setText(QObject::tr("Group"));
}

GroupUndoCommand::~GroupUndoCommand() {}

void GroupUndoCommand::undo() {
    _myGraphicsScene->ungroupModelComponents(_group);

    _myGraphicsScene->update();
}

void GroupUndoCommand::redo() {
    _myGraphicsScene->groupModelComponents(&_myGraphicalComponents, _group);

    _myGraphicsScene->update();
}
