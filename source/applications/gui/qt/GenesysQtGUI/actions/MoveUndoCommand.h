#ifndef MOVEUNDOCOMMAND_H
#define MOVEUNDOCOMMAND_H

#include <QUndoCommand>
#include "ModelGraphicsScene.h"
#include "graphicals/GraphicalModelComponent.h"

class MoveUndoCommand : public QUndoCommand
{
public:
    MoveUndoCommand(QList<QGraphicsItem *> gmc, ModelGraphicsScene *scene, QList<QPointF> &oldPos, QList<QPointF> &newPos, QUndoCommand *parent = nullptr);
    ~MoveUndoCommand();

    void undo() override;
    void redo() override;

    //bool mergeWith(const QUndoCommand *command) override;

private:
    QList<QGraphicsItem*> _myGraphicalModelComponent;
    ModelGraphicsScene *_myGraphicsScene;
    QList<QPointF> _myOldPos;
    QList<QPointF> _myNewPos;
    bool _firstExecution;
};

#endif // MOVEUNDOCOMMAND_H
