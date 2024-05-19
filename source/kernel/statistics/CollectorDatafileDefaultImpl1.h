/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDatafileDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 1 de Agosto de 2018, 20:58
 */

#ifndef COLLECTORDATAFILEDEFAULTIMPL1_H
#define COLLECTORDATAFILEDEFAULTIMPL1_H

#include <string>

#include "CollectorDatafile_if.h"

class CollectorDatafileDefaultImpl1 : public CollectorDatafile_if {
public:
	CollectorDatafileDefaultImpl1();
	virtual ~CollectorDatafileDefaultImpl1() = default;
public: // inherited from Collector_if
	virtual void clear() override;
	virtual void addValue(double value, double weight=1) override;
	virtual double getLastValue() override;
	virtual unsigned long numElements() override;
public:
	virtual double getValue(unsigned int num) override;
	virtual double getNextValue() override;
	virtual void seekFirstValue() override;
	virtual std::string getDataFilename() override;
	virtual void setDataFilename(std::string filename) override;
public:
	virtual void setAddValueHandler(CollectorAddValueHandler addValueHandler) override;
	virtual void setClearHandler(CollectorClearHandler clearHandler) override;
private:
	std::string _filename;
	double _lastValue;
	unsigned int _numElements;
};

#endif /* COLLECTORDATAFILEDEFAULTIMPL1_H */

