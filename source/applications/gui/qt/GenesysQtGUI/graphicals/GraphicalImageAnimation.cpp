#include "GraphicalImageAnimation.h"

GraphicalImageAnimation::GraphicalImageAnimation(const QPointF startPoint, unsigned int width, unsigned int height, const QString imageName) :
    _startPoint(startPoint), _width(width), _height(height), _imageName(imageName){

    // Carrega as informações da imagem
    this->updateImage();
}

GraphicalImageAnimation::~GraphicalImageAnimation(){}

// Getters
QString GraphicalImageAnimation::getImagePath() const {
    return _imagePath;
}

QString GraphicalImageAnimation::getImageName() const {
    return _imageName;
}

QPointF GraphicalImageAnimation::getStartPoint() const {
    return _startPoint;
}

unsigned int GraphicalImageAnimation::getWidth() const {
    return _width;
}

unsigned int GraphicalImageAnimation::getHeight() const {
    return _height;
}

// Setters
void GraphicalImageAnimation::setImageName(const QString &imageName) {
    this->_imageName = imageName;

    updateImage();
}

void GraphicalImageAnimation::setStartPoint(const QPointF &startPoint) {
    this->_startPoint = startPoint;

    updateImage();
}

void GraphicalImageAnimation::setWidth(unsigned int width) {
    this->_width = width;

    updateImage();
}

void GraphicalImageAnimation::setHeight(unsigned int height) {
    this->_height = height;

    updateImage();
}

// Outros
void GraphicalImageAnimation::updateImage() {
    // Forma o caminho completo para a imagem
    _imagePath = _defaultPath + _imageName;

    // Carrega a imagem
    QPixmap source(_imagePath);
    // Redimensiona a imagem
    QPixmap resizedImage = source.scaled(_width, _height);

    // Define a imagem do item atual
    setPixmap(resizedImage);

    // Define a posição inicial da imagem
    setPos(_startPoint);
}
