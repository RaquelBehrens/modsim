/*
 * The MIT License
 *
 * Copyright 2022 rlcancian.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * File:   ModelGraphicsScene.h
 * Author: rlcancian
 *
 * Created on 16 de fevereiro de 2022, 09:52
 */

#ifndef MODELGRAPHICSSCENE_H
#define MODELGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsRectItem>
#include <QTreeWidgetItem>
#include <QUndoStack>
#include <QAction>
#include "graphicals/GraphicalModelComponent.h"
#include "graphicals/GraphicalComponentPort.h"
#include "TraitsGUI.h"
#include "../../../../kernel/simulator/ModelComponent.h"
#include "../../../../kernel/simulator/Simulator.h"
#include "../../../../kernel/simulator/PropertyGenesys.h"
#include "../../../../kernel/simulator/Plugin.h"
#include "AnimationTransition.h"

class GraphicalModelEvent {
public:

	enum class EventType : int {
		CREATE = 1, REMOVE = 2, EDIT = 3, CLONE = 4, OTHER = 5
	};

	enum class EventObjectType : int {
        COMPONENT = 1, DATADEFINITION = 2, CONNECTION = 3, DRAWING = 4, ANIMATION = 5, OTHER = 6
	};

public:

	GraphicalModelEvent(GraphicalModelEvent::EventType eventType, GraphicalModelEvent::EventObjectType eventObjectType, QGraphicsItem* item) {
		this->eventType = eventType;
		this->eventObjectType = eventObjectType;
		this->item = item;
	}
	GraphicalModelEvent::EventType eventType;
	GraphicalModelEvent::EventObjectType eventObjectType;
	QGraphicsItem* item;
};

class ModelGraphicsScene : public QGraphicsScene {
public:
	ModelGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
	ModelGraphicsScene(const ModelGraphicsScene& orig);
    virtual ~ModelGraphicsScene();
public: // editing graphic model
    enum DrawingMode{
        NONE, LINE, TEXT, RECTANGLE, ELLIPSE, POLYGON,  POLYGON_POINTS, POLYGON_FINISHED
    };
    GraphicalModelComponent* addGraphicalModelComponent(Plugin* plugin, ModelComponent* component, QPointF position, QColor color = Qt::blue, bool notify = false);
    GraphicalConnection* addGraphicalConnection(GraphicalComponentPort* sourcePort, GraphicalComponentPort* destinationPort, unsigned int portSourceConnection, unsigned int portDestinationConnection, bool notify = false);
	GraphicalModelDataDefinition* addGraphicalModelDataDefinition(Plugin* plugin, ModelDataDefinition* element, QPointF position, QColor color = Qt::blue);
    void addDrawing(QPointF endPoint, bool moving, bool notify = false);
	void addAnimation();
    void startTextEditing();
    void removeComponent(GraphicalModelComponent* gmc, bool notify = false);
    void clearConnectionsComponent(GraphicalModelComponent* gmc);
    void clearInputConnectionsComponent(GraphicalModelComponent* graphicalComponent);
    void clearOutputConnectionsComponent(GraphicalModelComponent* graphicalComponent);
    void clearPorts(GraphicalConnection* connection, GraphicalModelComponent *source, GraphicalModelComponent *destination);
    void connectComponents(GraphicalConnection* connection, GraphicalModelComponent *source = nullptr, GraphicalModelComponent *destination = nullptr, bool notify = false);
    bool connectSource(GraphicalConnection* connection, GraphicalModelComponent *source = nullptr);
    bool connectDestination(GraphicalConnection* connection, GraphicalModelComponent *destination = nullptr);
    void redoConnections(GraphicalModelComponent *graphicalComponent, QList<GraphicalConnection *> *inputConnections, QList<GraphicalConnection *> *outputConnections);
    void removeComponentInModel(GraphicalModelComponent* gmc);
    void removeGraphicalConnection(GraphicalConnection* graphicalConnection, GraphicalModelComponent *source, GraphicalModelComponent *destination, bool notify = false);
    void removeConnectionInModel(GraphicalConnection* graphicalConnection, GraphicalModelComponent *source);
	void removeGraphicalModelDataDefinition(GraphicalModelDataDefinition* gmdd);
    void removeDrawing(QGraphicsItem * item, bool notify = false);
	void removeAnimation();
    void removeGroup(QGraphicsItemGroup* group, bool notify = false);
    void clearGraphicalModelComponents();
    void clearGraphicalModelConnections();
    void groupComponents(bool notify = false); // tenta agrupar (verifica se sao ModelGraphicalComponents)
    void groupModelComponents(QList<GraphicalModelComponent *> *graphicalComponents, QGraphicsItemGroup *group); // agrupa componentes
    void ungroupComponents(bool notify = false);
    void ungroupModelComponents(QGraphicsItemGroup *group);
    void notifyGraphicalModelChange(GraphicalModelEvent::EventType eventType, GraphicalModelEvent::EventObjectType eventObjectType, QGraphicsItem *item);
    QList<GraphicalModelComponent*>* graphicalModelComponentItems();
    GraphicalModelComponent* findGraphicalModelComponent(Util::identification id);
public:
    struct GRID {
        unsigned int interval;
        QPen pen;
        std::list<QGraphicsLineItem *> *lines;
        bool visible;
        void clear();
    };
    GRID *grid();
    void showGrid();
    void snapItemsToGrid();
    QUndoStack* getUndoStack();
    Simulator* getSimulator();
    void setUndoStack(QUndoStack* undo);
	void beginConnection();
	void setSimulator(Simulator *simulator);
	void setPropertyEditor(PropertyEditorGenesys *propEditor);
	void setObjectBeingDragged(QTreeWidgetItem* objectBeingDragged);
	void setParentWidget(QWidget *parentWidget);
	unsigned short connectingStep() const;
	void setConnectingStep(unsigned short connectingStep);
    void setSnapToGrid(bool activated);
    bool getSnapToGrid();
    void arranjeModels(int direction);
    void setDrawingMode(DrawingMode drawingMode);
    void setGraphicalComponentPort(GraphicalComponentPort * in);
    DrawingMode getDrawingMode();
    void setAction(QAction* action);
    QList<GraphicalModelComponent*> *getAllComponents();
    QMap<QGraphicsItemGroup *, QList<GraphicalModelComponent *>> getListComponentsGroup();
    void insertComponentGroup(QGraphicsItemGroup *group, QList<GraphicalModelComponent *> componentsGroup);
    void insertOldPositionItem(QGraphicsItem *item, QPointF position);
    QPointF getOldPositionItem(QGraphicsItem *item) const;
    QList<AnimationTransition *> *getAnimationsTransition();
    void clearAnimations();
    void clearAnimationsTransition();
    QList<QString> *getImagesAnimation();

public:
	QList<QGraphicsItem*>*getGraphicalModelDataDefinitions() const;
	QList<QGraphicsItem*>*getGraphicalModelComponents() const;
	QList<QGraphicsItem*>*getGraphicalConnections() const;
	QList<QGraphicsItem*>*getGraphicalDrawings() const;
	QList<QGraphicsItem*>*getGraphicalAnimations() const;
	QList<QGraphicsItem*>*getGraphicalEntities() const;
    QList<QGraphicsItemGroup*>*getGraphicalGroups() const;
    QList<AnimationTransition *> getAnimationsTransition() const;

protected: // virtual functions
	virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent);
	virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
	virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
	virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
	//virtual void	drawBackground(QPainter *painter, const QRectF &rect);
	//virtual void	drawForeground(QPainter *painter, const QRectF &rect);
	virtual void dropEvent(QGraphicsSceneDragDropEvent *event);
	virtual void focusInEvent(QFocusEvent *focusEvent);
	virtual void focusOutEvent(QFocusEvent *focusEvent);
	//virtual void	helpEvent(QGraphicsSceneHelpEvent *helpEvent);
	//virtual void	inputMethodEvent(QInputMethodEvent *event);
	virtual void keyPressEvent(QKeyEvent *keyEvent);
	virtual void keyReleaseEvent(QKeyEvent *keyEvent);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent);
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
	virtual void wheelEvent(QGraphicsSceneWheelEvent *wheelEvent);

private:
    GRID _grid;
	Simulator* _simulator = nullptr;
	PropertyEditorGenesys* _propertyEditor = nullptr;
	QTreeWidgetItem* _objectBeingDragged = nullptr;
	QWidget* _parentWidget;
    QList<GraphicalModelComponent*> _allGraphicalModelComponents;
    QList<GraphicalConnection*> _allGraphicalConnections;
    QUndoStack *_undoStack = nullptr;
    QMap<QGraphicsItemGroup *, QList<GraphicalModelComponent *> > _listComponentsGroup;
    QMap<QGraphicsItem *, QPointF> _oldPositionsItems;
private:
    DrawingMode _drawingMode = NONE;
    QGraphicsRectItem* _currentRectangle = nullptr;
    QGraphicsLineItem* _currentLine = nullptr;
    QGraphicsPolygonItem* _currentPolygon = nullptr;
    QGraphicsEllipseItem* _currentEllipse = nullptr;
    QPolygonF _currentPolygonPoints;
    QPointF _drawingStartPoint;
    QAction* _currentAction = nullptr;
    bool _drawing = false;
    unsigned short _connectingStep = 0; //0:nothing, 1:waiting click on source or destination, 2: click on source, 3: click on destination
	bool _controlIsPressed = false;
    bool _snapToGrid = false;
    GraphicalComponentPort* _sourceGraphicalComponentPort;
    GraphicalComponentPort* _destinationGraphicalComponentPort;

private:
	// IMPORTANT. MUST BE CONSISTENT WITH SIMULATOR->MODEL
	QList<QGraphicsItem*>* _graphicalModelComponents = new QList<QGraphicsItem*>();
	QList<QGraphicsItem*>* _graphicalModelDataDefinitions = new QList<QGraphicsItem*>();
	QList<QGraphicsItem*>* _graphicalConnections = new QList<QGraphicsItem*>();
	QList<QGraphicsItem*>* _graphicalAssociations = new QList<QGraphicsItem*>();
	QList<QGraphicsItem*>* _graphicalDrawings = new QList<QGraphicsItem*>();
	QList<QGraphicsItem*>* _graphicalAnimations = new QList<QGraphicsItem*>();
	QList<QGraphicsItem*>* _graphicalEntities = new QList<QGraphicsItem*>();
    QList<QGraphicsItemGroup*>* _graphicalGroups = new QList<QGraphicsItemGroup*>();
    QList<AnimationTransition *> *_animationsTransition = new QList<AnimationTransition*>();
    QList<QString> *_imagesAnimation = new QList<QString>;
};

#endif /* MODELGRAPHICSSCENE_H */

