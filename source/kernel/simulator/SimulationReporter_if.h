/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationReporter_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 8 de Agosto de 2018, 10:56
 */

#ifndef SIMULATIONREPORTER_IF_H
#define SIMULATIONREPORTER_IF_H

#include "../util/List.h"
//#include "StatisticsCollector.h"

class SimulationReporter_if {
public:
	/*!
	 * \brief showReplicationStatistics
	 */
	virtual void showReplicationStatistics() = 0;
	/*!
	 * \brief showSimulationStatistics
	 */
	virtual void showSimulationStatistics() = 0;
	/*!
	 * \brief showSimulationResponses
	 */
	virtual void showSimulationResponses() = 0;
	/*!
	 * \brief showSimulationControls
	 */
	virtual void showSimulationControls() = 0;
	//virtual void setFormat(std::string format)=0;
};

#endif /* SIMULATIONREPORTER_IF_H */

