#include "dialogpluginmanager.h"
#include "ui_dialogpluginmanager.h"

DialogPluginManager::DialogPluginManager(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogPluginManager)
{
	ui->setupUi(this);
}

DialogPluginManager::~DialogPluginManager()
{
	delete ui;
}
