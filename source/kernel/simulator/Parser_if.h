/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 23 de Agosto de 2018, 15:57
 */

#ifndef PARSER_IF_H
#define PARSER_IF_H

#include <string>
#include "../statistics/Sampler_if.h"

class genesyspp_driver;

class Parser_if {
public:
	/*!
	 * \brief parse
	 * \param expression
	 * \return
	 */
	virtual double parse(const std::string expression) = 0; // may throw exception
	/*!
	 * \brief parse
	 * \param expression
	 * \param success
	 * \param errorMessage
	 * \return
	 */
	virtual double parse(const std::string expression, bool* success, std::string* errorMessage) = 0; // does not throw exceptions
	/*!
	 * \brief getErrorMessage
	 * \return
	 */
	virtual std::string* getErrorMessage() = 0; // to get error message in the case of thrown exception
	/*!
	 * \brief setSampler
	 * \param sampler
	 */
	virtual void setSampler(Sampler_if* sampler) = 0;
	/*!
	 * \brief getSampler
	 * \return
	 */
	virtual Sampler_if* getSampler() const = 0;
	// ...? // TODO: Implement a method to get the TOKENS parsed. Example: If parsing "nq(queue1) < var1" return a list containing something like "fNQ tLPAR eQUEUE tRPAR tLESS eVARIABLE"
	/*!
	 * \brief getParser
	 * \return
	 */
	virtual genesyspp_driver getParser() const = 0;
};

#endif /* PARSER_IF_H */

