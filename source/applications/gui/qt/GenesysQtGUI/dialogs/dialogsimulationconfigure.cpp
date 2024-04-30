#include "dialogsimulationconfigure.h"
#include "ui_dialogsimulationconfigure.h"

DialogSimulationConfigure::DialogSimulationConfigure(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogSimulationConfigure)
{
	ui->setupUi(this);
}

DialogSimulationConfigure::~DialogSimulationConfigure()
{
	delete ui;
}
