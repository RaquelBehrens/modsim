#ifndef DIALOGSIMULATIONCONFIGURE_H
#define DIALOGSIMULATIONCONFIGURE_H

#include "../../../../../kernel/simulator/Simulator.h"

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
    void setSimulator(Simulator * sim);
    void previousConfiguration();


private slots:
    // Experiment Name
    void on_plainTextEdit_textChanged();
    // Number of replication
    void on_spinBox_valueChanged(int arg1);
    // Replication Length time unit
    void on_comboBox_currentIndexChanged(int index);
    // Warm up Period
    void on_spinBox_2_textChanged(const QString &arg1);
    // Replication Length
    void on_spinBox_3_textChanged(const QString &arg1);
    // Warm up Period time unit
    void on_comboBox_2_currentIndexChanged(int index);
    // Terminating Codition
    void on_plainTextEdit_2_textChanged();
    // Trace Level
    void on_comboBox_3_currentIndexChanged(int index);
    // Initialize System
    void on_checkBox_stateChanged(int arg1);
    // initialize Statistics
    void on_checkBox_4_stateChanged(int arg1);
    // Show Reports after Replication
    void on_checkBox_3_stateChanged(int arg1);
    // Show Reports after Simulation
    void on_checkBox_2_stateChanged(int arg1);
    // OK button
    void on_buttonBox_accepted();
    // Cancel button
    void on_buttonBox_rejected();



private:

    // Attributes required to save in Model
    Ui::DialogSimulationConfigure *ui;
    ModelSimulation * ms;
    TraceManager * trace;
    ModelInfo * infos;
    Model * model;


    std::string experimentName;
    unsigned int numberOfReplication;
    double replicationLength;
    Util::TimeUnit replicationLengthtimeUnit;
    double warmUpPeriod;
    Util::TimeUnit warmUpPeriodTimeUnit;
    std::string terminatingCondition;
    TraceManager::Level traceLevel;
    bool initializeSystem;
    bool initializeStatistics;
    bool showReportsAfterReplication;
    bool showReportsAfterSimulation;


};

#endif // DIALOGSIMULATIONCONFIGURE_H
