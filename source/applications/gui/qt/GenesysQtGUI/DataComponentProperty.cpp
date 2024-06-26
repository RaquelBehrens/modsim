#include "DataComponentProperty.h"

DataComponentProperty::DataComponentProperty() {
    _window = new QWidget;
};

DataComponentProperty::~DataComponentProperty() {
    delete _window;
};

void DataComponentProperty::open_window() {
    _window->show();
}
