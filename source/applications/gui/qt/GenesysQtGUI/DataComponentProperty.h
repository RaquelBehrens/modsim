#ifndef DATACOMPONENTPROPERTY_H
#define DATACOMPONENTPROPERTY_H

#include <QWidget>


class DataComponentProperty {
public:
    DataComponentProperty();
    ~DataComponentProperty();

public:
    void open_window();

private:
    QWidget* _window;
};

#endif // DATACOMPONENTPROPERTY_H