/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   StatisticsDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 1 de Agosto de 2018, 21:03
 */

#ifndef STATISTICSDEFAULTIMPL1_H
#define STATISTICSDEFAULTIMPL1_H

#include "Statistics_if.h"
#include "Collector_if.h"
//namespace GenesysKernel {

class StatisticsDefaultImpl1 : public Statistics_if {
public:
	StatisticsDefaultImpl1(); ///< When constructor is invoked without a Collector, it is taken from Traits<Statistics_if>::CollectorImplementation configuration
	StatisticsDefaultImpl1(Collector_if* collector);
	virtual ~StatisticsDefaultImpl1() = default;
public:
	virtual Collector_if* getCollector() const override;
	virtual void setCollector(Collector_if* collector) override;
public:
	virtual unsigned int numElements() override;
	virtual double min() override;
	virtual double max() override;
	virtual double average() override;
	virtual double variance() override;
	virtual double stddeviation() override;
	virtual double variationCoef() override;
	virtual double halfWidthConfidenceInterval() override;
	virtual double confidenceLevel() override;
	virtual unsigned int newSampleSize(double halfWidth) override;
	virtual void setConfidenceLevel(double confidencelevel) override;
private:
	void collectorAddHandler(double newValue, double newWeight);
	void collectorClearHandler();
	void initStatistics();
private:
	Collector_if* _collector;
	unsigned long _elems;
	double _sumData;
	double _sumDataSquare;
	double _sumWeight;
	double _sumWeightSquare;
	double _min;
	double _max;
	double _average;
	double _variance;
	double _unweightedvariance;
	double _unbiasedVariance;
	double _stddeviation;
	double _variationCoef;
	double _confidenceLevel = 0.95;
	double _criticalTn_1 = 1.96;
	double _halfWidth;
};
//namespace\\}
#endif /* STATISTICSDEFAULTIMPL1_H */

