#include "OutputAnalyser.h"
#include "../../kernel/statistics/CollectorOutputAnalyser.h"
#include "../../kernel/statistics/StatisticsDataFileDefaultImpl.h"
#include "../../kernel/statistics/SamplerDefaultImpl1.h"
#include "../../kernel/simulator/ExperimentManagerDefaultImpl1.h"
#include "../HypothesisTesterDefaultImpl1.h"
#include "Statistics.h"
#include <cstddef>

using namespace std;

OutputAnalyser::OutputAnalyser(string filename) {
    _collector = CollectorOutputAnalyser();
    _collector.setDataFilename(filename);

    // TODO: Use traits to set which implementation of statisticsDataFile to use.
    _statisticsDataFile = new Statistics();
    _statisticsDataFile->setCollector(&_collector);

    _hypothesisTester = new HypothesisTesterDefaultImpl1();
    _fitter = new Fitter(_collector, _statisticsDataFile);

    _experimentManager = new ExperimentManagerDefaultImpl1();
    _sampler = new SamplerDefaultImpl1();
}

OutputAnalyser::~OutputAnalyser() {
    delete _statisticsDataFile;
    delete _hypothesisTester;
    delete _experimentManager;
    delete _sampler;
    delete _fitter;
}

HypothesisTester_if* OutputAnalyser::tester() {
    return _hypothesisTester;
}

// Correlogram OutputAnalyser::getCorrelogram(int start, int end) {
//     return Correlogram(_collector, start, end);
// }

void OutputAnalyser::_resetDependencies() {
    _fitter->setCollector(_collector);
    _fitter->setStatistics(_statisticsDataFile);
    _statisticsDataFile->clearCache();
}

bool OutputAnalyser::loadDataSet(std::string datafilename){
    _collector.setDataFilename(datafilename);
    _resetDependencies();
}

bool OutputAnalyser::saveDataSet(std::string datafilename){
    // TODO
}

void OutputAnalyser::newDataSet(std::string datasetname, std::string datafilename){
    // TODO
}

void OutputAnalyser::setReplication(int replicationNumber) {
    _collector.setReplicationNumber(replicationNumber);
    _resetDependencies();
}

CollectorOutputAnalyser* OutputAnalyser::collector() {
    return &_collector;
}

Statistics* OutputAnalyser::statisticsDataFile() const {
    return _statisticsDataFile;
}

Fitter_if* OutputAnalyser::fitter() {
    return _fitter;
}

Sampler_if* OutputAnalyser::sampler() {
    return _sampler;
}

ExperimentManager_if* OutputAnalyser::experimenter() {
    return _experimentManager;
}
