#include "Dialogmodelinformation.h"
#include "ui_Dialogmodelinformation.h"

DialogModelInformation::DialogModelInformation(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogModelInformation)
{
	ui->setupUi(this);
}

DialogModelInformation::~DialogModelInformation()
{
	delete ui;
}
