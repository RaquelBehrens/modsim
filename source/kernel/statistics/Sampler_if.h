/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Sampler_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 14 de Agosto de 2018, 13:20
 */

#ifndef Sampler_IF_H
#define Sampler_IF_H

/*!
 * Interface that describes the methods to be implemented by classes that generate random values ​​that follow a specific probability distribution.
 */
class Sampler_if {
public:

	/*!
	 * class that encapsulates attributes required to generate random numbers, which depends on the generation method used.
	 */
	struct RNG_Parameters {
		virtual ~RNG_Parameters() = default;
	};
public: // RNG
	virtual double random() = 0;
public: // continuous probability distributions
	virtual double sampleBeta(double alpha, double beta, double infLimit, double supLimit) = 0;
	virtual double sampleBeta(double alpha, double beta) = 0;
	virtual double sampleErlang(double mean, int M, double offset = 0.0) = 0;
	virtual double sampleExponential(double mean, double offset = 0.0) = 0;
	//virtual double sampleGamma(double mean, double alpha, double offset=0.0) = 0;
	virtual double sampleGamma(double alpha, double beta, double offset = 0.0) = 0;
	virtual double sampleGumbell(double mode, double scale) = 0;
	virtual double sampleLogNormal(double mean, double stddev, double offset = 0.0) = 0;
	virtual double sampleNormal(double mean, double stddev) = 0;
	virtual double sampleTriangular(double min, double mode, double max) = 0;
	virtual double sampleUniform(double min, double max) = 0;
	virtual double sampleWeibull(double alpha, double scale) = 0;
public: // discrete probability distributions
	//TODO: Poisson, si vous plait!!!!
	virtual double sampleBinomial(int trials, double p) = 0;
	virtual double sampleBernoulli(double p) = 0;
	virtual double sampleDiscrete(double prob, double value, ...) = 0;
	virtual double sampleDiscrete(double *prob, double *value, int size) = 0;
	virtual double sampleGeometric(double p) = 0;
public:
	virtual void setRNGparameters(RNG_Parameters* param) = 0;
	virtual RNG_Parameters* getRNGparameters() const = 0;
};

#endif /* Sampler_IF_H */

