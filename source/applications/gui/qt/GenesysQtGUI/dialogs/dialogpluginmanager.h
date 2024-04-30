#ifndef DIALOGPLUGINMANAGER_H
#define DIALOGPLUGINMANAGER_H

#include <QDialog>

namespace Ui {
	class DialogPluginManager;
}

class DialogPluginManager : public QDialog
{
	Q_OBJECT

public:
	explicit DialogPluginManager(QWidget *parent = nullptr);
	~DialogPluginManager();

private:
	Ui::DialogPluginManager *ui;
};

#endif // DIALOGPLUGINMANAGER_H
