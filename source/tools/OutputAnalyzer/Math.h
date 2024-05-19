#pragma once

#include <vector>
#include <numeric>    
#include "Reader_if.h"

namespace Math
{
    double weightedVariance(std::vector<Reader_if::Data>::iterator begin, std::vector<Reader_if::Data>::iterator end);
    double weightedAverage(Reader_if::DataFileIterator begin, Reader_if::DataFileIterator end);
    double weightedStddeviation(std::vector<Reader_if::Data>::iterator begin, std::vector<Reader_if::Data>::iterator end);
    double average(std::vector<double>::iterator begin, std::vector<double>::iterator end);
    double average(std::vector<Reader_if::Data>::iterator begin, std::vector<Reader_if::Data>::iterator end);
    double average(Reader_if::DataFileIterator begin, Reader_if::DataFileIterator end);
    double sum(std::vector<Reader_if::Data>::iterator begin, std::vector<Reader_if::Data>::iterator end);
    double variance(std::vector<Reader_if::Data>::iterator begin, std::vector<Reader_if::Data>::iterator end, double avg);
    double variance(Reader_if::DataFileIterator begin, Reader_if::DataFileIterator end, double avg);
    double getZ(double probability);
    double getChi2(long double confidenceLevel, int degreesOfFreedom);
}
