#include "DialogSelectVariable.h"
#include <QVBoxLayout>

DialogSelectVariable::DialogSelectVariable(QWidget *parent)
    : QDialog(parent), comboBox(new QComboBox(this)), okButton(new QPushButton("OK", this)),
    cancelButton(new QPushButton("Cancel", this)) {

    setWindowTitle("Select a Variable");

    // Layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(comboBox);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(okButton);
    mainLayout->addLayout(buttonLayout);

    // Conecta os sinais aos slots
    connect(okButton, &QPushButton::clicked, this, &DialogSelectVariable::onOkClicked);
    connect(cancelButton, &QPushButton::clicked, this, &DialogSelectVariable::onCancelClicked);
}

Variable* DialogSelectVariable::selectedIndex() const {
    int currentIndex = comboBox->currentIndex();
    return indexToVariable.value(currentIndex);
}

void DialogSelectVariable::onOkClicked() {
    accept();
}

void DialogSelectVariable::onCancelClicked() {
    reject();
}

void DialogSelectVariable::setVariableItems(QList<Variable *> *variables, Variable *variable) {
    comboBox->clear();

    QString standardInput = "None";

    comboBox->addItem(standardInput);
    indexToVariable[0] = nullptr;

    for (unsigned int i = 0; i < (unsigned int) variables->size(); i++) {
        // Adiciona entradas ao mapeamento ponteiro-nome
        QString entryName = QString::fromStdString(variables->at(i)->getName());
        indexToVariable[i+1] = variables->at(i);
        comboBox->addItem(entryName);
    }

    comboBox->setCurrentIndex(indexToVariable.key(variable, 0));
}
