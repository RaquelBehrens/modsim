// MyClass.h (Header File)

#ifndef CORRELOGRAM_H
#define CORRELOGRAM_H
#include <vector>
#include "../../kernel/statistics/CollectorOutputAnalyser.cpp"
class Correlogram {
   public:
    // Constructor
    Correlogram(CollectorOutputAnalyser& collector, int start, int end);
    ~Correlogram()=default;
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Correlogram& o);
    std::vector<double> getAutoCorrelation() {return _autocorrelation;}

   private:
    double getWeightedMean(std::vector<CollectorOutputAnalyser::Data>::iterator begin, std::vector<CollectorOutputAnalyser::Data>::iterator end);
    void getTimeVector(CollectorOutputAnalyser& reader);
    std::vector<CollectorOutputAnalyser::Data>::iterator getBeginPosition(std::vector<CollectorOutputAnalyser::Data>::iterator begin, std::vector<CollectorOutputAnalyser::Data>::iterator end, int start);
    std::vector<CollectorOutputAnalyser::Data>::iterator getEndTimePosition(std::vector<CollectorOutputAnalyser::Data>::iterator begin, std::vector<CollectorOutputAnalyser::Data>::iterator, int endtime);
    std::vector<double> _timeVector;
    std::vector<double> _autocorrelation;
    int _startTime;
};

#endif
