#ifndef GENESYS_SIMULATOR_STATISTICSDATAFILEOUTPUTANALYSER_H
#define GENESYS_SIMULATOR_STATISTICSDATAFILEOUTPUTANALYSER_H

#include "../../kernel/statistics/StatisticsDataFileDefaultImpl.h"
#include <vector>

class Statistics : public StatisticsDatafileDefaultImpl1 {
  public:
    std::vector<double> movingAverage(int dataPoints);
};

#endif // GENESYS_SIMULATOR_STATISTICSDATAFILEOUTPUTANALYSER_H
