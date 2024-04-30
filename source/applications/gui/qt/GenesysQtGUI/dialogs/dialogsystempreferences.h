#ifndef DIALOGSYSTEMPREFERENCES_H
#define DIALOGSYSTEMPREFERENCES_H

#include <QDialog>

namespace Ui {
	class DialogSystemPreferences;
}

class DialogSystemPreferences : public QDialog
{
	Q_OBJECT

public:
	explicit DialogSystemPreferences(QWidget *parent = nullptr);
	~DialogSystemPreferences();

private:
	Ui::DialogSystemPreferences *ui;
};

#endif // DIALOGSYSTEMPREFERENCES_H
