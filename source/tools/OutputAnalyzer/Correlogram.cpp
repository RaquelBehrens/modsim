#include<iostream>
#include <cmath>
#include"Correlogram.h"

using namespace std;

Correlogram::Correlogram(CollectorOutputAnalyser& collector, int start, int end) {

    getTimeVector(collector);
    if (end == -1 || end > int(_timeVector.size())) {
        end = _timeVector.size();
    }
    if (start < _startTime) {
        start = _startTime;
    }

    double mean = getWeightedMean(getBeginPosition(collector.begin(), collector.end(), start), getEndTimePosition(collector.begin(), collector.end(), end));

    int size = end - start;
    int half_size = ceil(double(size)/2);

    _autocorrelation = std::vector<double>();
    for (int t = 0; t < half_size; t ++)
    {
        double n = 0; // Numerator
        double d = 0; // Denominator

        for (int i = 0; i < size; i ++)
        {
            int ind = i + start - _startTime;
            double xim = _timeVector[ind] - mean;
            n += xim * (_timeVector[(ind + t) % size] - mean);
            d += xim * xim;
        }

        _autocorrelation.push_back(n / d);
    }
}

std::string Correlogram::toString() const {
 std::stringstream oss;
    std::stringstream line;
    line << "[ ";
    for (auto &&i : _autocorrelation)
    {
        line << i << " ";
    }
    line << "]" << std::endl;
    oss << line.str();
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Correlogram& o) {
    os << o.toString();
    return os;
}

std::vector<CollectorOutputAnalyser::Data>::iterator Correlogram::getBeginPosition(std::vector<CollectorOutputAnalyser::Data>::iterator begin, std::vector<CollectorOutputAnalyser::Data>::iterator end, int start) {
    auto i = begin;
    auto last = i;
    while(i!=end) {
        CollectorOutputAnalyser::Data data =  CollectorOutputAnalyser::Data(*i);
    
        if (data.time >= start) {
            break;
        }
        last = i++;
    }

    return last;
}

std::vector<CollectorOutputAnalyser::Data>::iterator Correlogram::getEndTimePosition(std::vector<CollectorOutputAnalyser::Data>::iterator begin, std::vector<CollectorOutputAnalyser::Data>::iterator end, int endtime) {
    auto i = begin;
    auto last = i;
    while(i!=end) {
        CollectorOutputAnalyser::Data data =  CollectorOutputAnalyser::Data(*i);
    
        if (data.time >= endtime) {
            break;
        }
        last = i++;
    }

    return last;
}

void Correlogram::getTimeVector(CollectorOutputAnalyser& reader ) {
    auto i = reader.begin();
    CollectorOutputAnalyser::Data last = *i;
    int time = last.time;
    _startTime = time;
    _timeVector.push_back(last.value);
    while(i!=reader.end()) {
        CollectorOutputAnalyser::Data data = CollectorOutputAnalyser::Data(*i);

        for (size_t i = 0; i < size_t(data.time - time); i++)
        {
            _timeVector.push_back(last.value);

        }
        last = data;

        time = data.time;
        i++;
    }
    _timeVector.push_back(last.value);

}

double Correlogram::getWeightedMean(std::vector<CollectorOutputAnalyser::Data>::iterator begin, std::vector<CollectorOutputAnalyser::Data>::iterator end) {

    CollectorOutputAnalyser::Data last = *begin;
    double sum = 0;
    auto i = begin;
    while (i != end) {
        CollectorOutputAnalyser::Data data = *i;

        sum += last.value * (data.time - last.time);
        last = data;

        i++;
    }
    return sum / last.time;
}
