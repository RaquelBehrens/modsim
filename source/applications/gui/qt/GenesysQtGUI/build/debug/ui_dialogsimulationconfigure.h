/********************************************************************************
** Form generated from reading UI file 'dialogsimulationconfigure.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSIMULATIONCONFIGURE_H
#define UI_DIALOGSIMULATIONCONFIGURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSimulationConfigure
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox_3;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox_2;
    QComboBox *comboBox_2;
    QLabel *label_6;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox;
    QCheckBox *checkBox_4;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QHBoxLayout *horizontalLayout_5;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogSimulationConfigure)
    {
        if (DialogSimulationConfigure->objectName().isEmpty())
            DialogSimulationConfigure->setObjectName(QString::fromUtf8("DialogSimulationConfigure"));
        DialogSimulationConfigure->setWindowModality(Qt::WindowModal);
        DialogSimulationConfigure->resize(534, 416);
        verticalLayout = new QVBoxLayout(DialogSimulationConfigure);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, -1, -1, 2);
        label = new QLabel(DialogSimulationConfigure);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(DialogSimulationConfigure);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(DialogSimulationConfigure);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(DialogSimulationConfigure);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(DialogSimulationConfigure);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        plainTextEdit = new QPlainTextEdit(DialogSimulationConfigure);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);
        plainTextEdit->setMaximumSize(QSize(16777215, 32));

        formLayout->setWidget(0, QFormLayout::FieldRole, plainTextEdit);

        plainTextEdit_2 = new QPlainTextEdit(DialogSimulationConfigure);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        sizePolicy.setHeightForWidth(plainTextEdit_2->sizePolicy().hasHeightForWidth());
        plainTextEdit_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(5, QFormLayout::FieldRole, plainTextEdit_2);

        spinBox = new QSpinBox(DialogSimulationConfigure);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(5000);
        spinBox->setValue(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spinBox_3 = new QSpinBox(DialogSimulationConfigure);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setMinimum(1);
        spinBox_3->setMaximum(100000);

        horizontalLayout->addWidget(spinBox_3);

        comboBox = new QComboBox(DialogSimulationConfigure);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        spinBox_2 = new QSpinBox(DialogSimulationConfigure);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(100000);

        horizontalLayout_2->addWidget(spinBox_2);

        comboBox_2 = new QComboBox(DialogSimulationConfigure);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_2->addWidget(comboBox_2);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_2);

        label_6 = new QLabel(DialogSimulationConfigure);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        comboBox_3 = new QComboBox(DialogSimulationConfigure);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBox_3);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkBox = new QCheckBox(DialogSimulationConfigure);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_4->addWidget(checkBox);

        checkBox_4 = new QCheckBox(DialogSimulationConfigure);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        horizontalLayout_4->addWidget(checkBox_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBox_3 = new QCheckBox(DialogSimulationConfigure);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_3->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(DialogSimulationConfigure);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_3->addWidget(checkBox_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 10, -1, 0);

        verticalLayout->addLayout(horizontalLayout_5);

        buttonBox = new QDialogButtonBox(DialogSimulationConfigure);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#if QT_CONFIG(shortcut)
        label->setBuddy(plainTextEdit);
        label_2->setBuddy(spinBox);
        label_3->setBuddy(spinBox_3);
        label_4->setBuddy(spinBox_2);
        label_5->setBuddy(plainTextEdit_2);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(plainTextEdit, spinBox);
        QWidget::setTabOrder(spinBox, spinBox_3);
        QWidget::setTabOrder(spinBox_3, comboBox);
        QWidget::setTabOrder(comboBox, spinBox_2);
        QWidget::setTabOrder(spinBox_2, comboBox_2);
        QWidget::setTabOrder(comboBox_2, plainTextEdit_2);
        QWidget::setTabOrder(plainTextEdit_2, checkBox);
        QWidget::setTabOrder(checkBox, checkBox_4);
        QWidget::setTabOrder(checkBox_4, checkBox_3);
        QWidget::setTabOrder(checkBox_3, checkBox_2);

        retranslateUi(DialogSimulationConfigure);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSimulationConfigure, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSimulationConfigure, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogSimulationConfigure);
    } // setupUi

    void retranslateUi(QDialog *DialogSimulationConfigure)
    {
        DialogSimulationConfigure->setWindowTitle(QCoreApplication::translate("DialogSimulationConfigure", "Configure Simulation", nullptr));
        label->setText(QCoreApplication::translate("DialogSimulationConfigure", "Experiment Name:", nullptr));
        label_2->setText(QCoreApplication::translate("DialogSimulationConfigure", "Number of Replications:", nullptr));
        label_3->setText(QCoreApplication::translate("DialogSimulationConfigure", "Replication Length", nullptr));
        label_4->setText(QCoreApplication::translate("DialogSimulationConfigure", "Warmup Period:", nullptr));
        label_5->setText(QCoreApplication::translate("DialogSimulationConfigure", "Terminating Condition:", nullptr));
        label_6->setText(QCoreApplication::translate("DialogSimulationConfigure", "Trace Level:", nullptr));
        checkBox->setText(QCoreApplication::translate("DialogSimulationConfigure", "Initialize system", nullptr));
        checkBox_4->setText(QCoreApplication::translate("DialogSimulationConfigure", "Initialize statistics between replications", nullptr));
        checkBox_3->setText(QCoreApplication::translate("DialogSimulationConfigure", "Show reports after replication", nullptr));
        checkBox_2->setText(QCoreApplication::translate("DialogSimulationConfigure", "Show reports after simulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSimulationConfigure: public Ui_DialogSimulationConfigure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSIMULATIONCONFIGURE_H
