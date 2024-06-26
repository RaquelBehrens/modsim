#include "UngroupUndoCommand.h"
#include "ModelGraphicsScene.h"

UngroupUndoCommand::UngroupUndoCommand(QGraphicsItemGroup *group, ModelGraphicsScene *scene, QUndoCommand *parent)
    :QUndoCommand(parent), _group(group), _myComponentsGroup(new QList<GraphicalModelComponent *>()), _myGraphicsScene(scene){

    for (int i = 0; i < _group->childItems().size(); i++) {
        GraphicalModelComponent * item = dynamic_cast<GraphicalModelComponent *>(_group->childItems().at(i));
        _myComponentsGroup->append(item);
    }

    setText(QObject::tr("Ungroup"));
}

UngroupUndoCommand::~UngroupUndoCommand() {}

void UngroupUndoCommand::undo() {
    if (_myComponentsGroup)
        _myGraphicsScene->groupModelComponents(_myComponentsGroup, _group);

    _myGraphicsScene->update();
}

void UngroupUndoCommand::redo() {
    _myGraphicsScene->ungroupModelComponents(_group);

    _myGraphicsScene->update();
}
