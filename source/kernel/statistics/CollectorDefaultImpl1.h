/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 1 de Agosto de 2018, 20:43
 */

#ifndef COLLECTORDEFAULTIMPL1_H
#define COLLECTORDEFAULTIMPL1_H

#include "Collector_if.h"
//namespace GenesysKernel {

class CollectorDefaultImpl1 : public Collector_if {
public:
	CollectorDefaultImpl1();
	virtual ~CollectorDefaultImpl1() = default;
public:
	virtual void clear() override;
	virtual void addValue(double value, double weight=1) override;
	virtual double getLastValue() override;
	virtual unsigned long numElements() override;
public:
	virtual void setAddValueHandler(CollectorAddValueHandler addValueHandler) override;
	virtual void setClearHandler(CollectorClearHandler clearHandler) override;
private:
	double _lastValue;
	unsigned long _numElements = 0;
	CollectorAddValueHandler _addValueHandler = nullptr;
	CollectorClearHandler _clearHandler = nullptr;
};
//namespace\\}
#endif /* COLLECTORDEFAULTIMPL1_H */

