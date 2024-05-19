//
// Created by enzo on 19/11/23.
//

#include "Statistics.h"
#include "../ProbabilityDistribution.h"
#include <math.h>
#include <vector>

using namespace std;

vector<double> Statistics::movingAverage(int dataPoints) {
    vector<double> _movingAverage(_collector->numElements());
    double currSum = 0;

    int prevLeftIndex = 0, prevRightIndex = -1;
    for (int i = 0; i < int(_movingAverage.size()); i++) {
        int leftIndex = std::max(0, i - (dataPoints / 2));
        int rightIndex = std::min(int(_movingAverage.size()) - 1, i + (dataPoints / 2));

        while (prevLeftIndex < leftIndex) {
            currSum -= _collector->getValue(prevLeftIndex);
            prevLeftIndex++;
        }
        while (prevRightIndex < rightIndex) {
            prevRightIndex++;
            currSum += _collector->getValue(prevRightIndex);
        }

        _movingAverage[i] = currSum / (rightIndex - leftIndex + 1);
    }

    return _movingAverage;
}
