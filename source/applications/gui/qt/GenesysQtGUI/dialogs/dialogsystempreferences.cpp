#include "dialogsystempreferences.h"
#include "ui_dialogsystempreferences.h"

DialogSystemPreferences::DialogSystemPreferences(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogSystemPreferences)
{
	ui->setupUi(this);
}

DialogSystemPreferences::~DialogSystemPreferences()
{
	delete ui;
}
