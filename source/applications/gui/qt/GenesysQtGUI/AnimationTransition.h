#ifndef ANIMATIONTRANSITION_H
#define ANIMATIONTRANSITION_H

#include <QList>
#include <QPointF>
#include <QTimer>
#include <QVariantAnimation>
#include <QElapsedTimer>

#include "graphicals/GraphicalModelComponent.h"
#include "graphicals/GraphicalConnection.h"
#include "graphicals/GraphicalImageAnimation.h"

// Em segundos
#define TEMPO_EXECUCAO_ANIMACAO 1

class ModelGraphicsScene;

class AnimationTransition : public QVariantAnimation
{
public:
    // Construtor
    AnimationTransition(ModelGraphicsScene* myScene, ModelComponent* graphicalStartComponent, ModelComponent* graphicalEndComponent, const QString imageName = "default.png");
    // Destrutor
    ~AnimationTransition();

    // Getters
    GraphicalModelComponent* getGraphicalStartComponent() const;
    GraphicalModelComponent* getGraphicalEndComponent() const;
    GraphicalConnection* getGraphicalConnection() const;
    static int getTimeExecution();
    QList<QPointF> getPointsForAnimation() const;
    GraphicalImageAnimation* getImageAnimation() const;
    unsigned int getPortNumber() const;

    // Setters
    void setImageAnimation(GraphicalImageAnimation* imageAnimation);
    static void setTimeExecution(int timeExecution);

    // Inicia a animação
    void startAnimation();
    // Finaliza a animação
    void stopAnimation();
    // Reinicia a animação
    void restartAnimation();
    // Configuração informações para a animação
    void configureAnimation();
    // Atualiza a duração da animação se ela for alterada em tempo de execução
    void updateDurationIfNeeded();
    // Conecta o sinal valueChanged da animação ao slot onAnimationValueChanged
    void connectValueChangedSignal();
    // Conecta o sinal finished da animação ao slot onAnimationFinished
    void connectFinishedSignal();
    // Função a ser chamada ao término da execução da animação

public slots:
    // Slot para ser conectado ao sinal valueChanged
    void onAnimationValueChanged(const QVariant& value);
    // Slot que será conectado a um sinal
    void onAnimationFinished();

private:
    ModelGraphicsScene* _myScene;
    GraphicalModelComponent* _graphicalStartComponent;
    GraphicalModelComponent* _graphicalEndComponent;
    GraphicalConnection* _graphicalConnection;
    static int *_timeExecution;
    static int _oldTimeExecution;
    QList<QPointF> _pointsForAnimation;
    GraphicalImageAnimation* _imageAnimation;
    unsigned int _portNumber;
    qreal _currentProgress;
};

#endif // ANIMATIONTRANSITION_H
