#ifndef DIALOGSIMULATIONCONFIGURE_H
#define DIALOGSIMULATIONCONFIGURE_H

#include <QDialog>

namespace Ui {
	class DialogSimulationConfigure;
}

class DialogSimulationConfigure : public QDialog
{
	Q_OBJECT

public:
	explicit DialogSimulationConfigure(QWidget *parent = nullptr);
	~DialogSimulationConfigure();

private:
	Ui::DialogSimulationConfigure *ui;
};

#endif // DIALOGSIMULATIONCONFIGURE_H
