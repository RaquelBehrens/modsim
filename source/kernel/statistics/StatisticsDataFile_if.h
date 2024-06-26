/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsDataFile.h
 * Author: rafael.luiz.cancian
 *
 * Created on 22 de Novembro de 2018, 01:16
 */

#ifndef STATISTICSDATAFILE_IF_H
#define STATISTICSDATAFILE_IF_H

#include "CollectorDatafile_if.h"
#include "Statistics_if.h"

class StatisticsDatafile_if : public Statistics_if {
	//public:
	//    virtual CollectorDatafile_if* getCollector() = 0;
	//    virtual void setCollector(Collector_if* collector) = 0;
public:
	/*!
	 * \brief mode
	 * \return
	 */
	virtual double mode() = 0;
	/*!
	 * \brief mediane
	 * \return
	 */
	virtual double mediane() = 0;
	/*!
	 * \brief quartil
	 * \param num
	 * \return
	 */
	virtual double quartil(unsigned short num) = 0;
	/*!
	 * \brief decil
	 * \param num
	 * \return
	 */
	virtual double decil(unsigned short num) = 0;
	/*!
	 * \brief centil
	 * \param num
	 * \return
	 */
	virtual double centil(unsigned short num) = 0;
	/*!
	 * \brief setHistogramNumClasses
	 * \param num
	 */
	virtual void setHistogramNumClasses(unsigned short num) = 0;
	/*!
	 * \brief histogramNumClasses
	 * \return
	 */
	virtual unsigned short histogramNumClasses() = 0;
	/*!
	 * \brief histogramClassLowerLimit
	 * \param classNum
	 * \return
	 */
	virtual double histogramClassLowerLimit(unsigned short classNum) = 0;
	/*!
	 * \brief histogramClassFrequency
	 * \param classNum
	 * \return
	 */
	virtual unsigned int histogramClassFrequency(unsigned short classNum) = 0;

};

#endif /* STATISTICSDATAFILE_IF_H */

