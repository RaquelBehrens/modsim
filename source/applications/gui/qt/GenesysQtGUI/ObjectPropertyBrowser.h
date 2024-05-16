#ifndef OBJECTPROPERTYBROWSER_H
#define OBJECTPROPERTYBROWSER_H


#include <QObject>
#include <QPushButton>
#include <QMap>
#include <QMetaProperty>
#include "QPropertyBrowser/qttreepropertybrowser.h"
#include "QPropertyBrowser/qtvariantproperty.h"

#include "../../../../kernel/simulator/ModelDataDefinition.h"

class ObjectPropertyBrowser : public QtTreePropertyBrowser
{
	Q_OBJECT

public:
    ObjectPropertyBrowser(QWidget* parent);
    void setActiveObject(QObject *obj, ModelDataDefinition* mdd = nullptr);
    void clearCurrentlyConnectedObject();
private:
	QtVariantPropertyManager *variantManager;
	QObject *currentlyConnectedObject = nullptr;
	QMap<QtProperty *, const char*> propertyMap;

private slots:
	void valueChanged(QtProperty *property, const QVariant &value);

public slots:
	void objectUpdated();
};

#endif // OBJECTPROPERTYBROWSER_H
