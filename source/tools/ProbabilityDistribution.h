/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ProbabilityDistribution.h
 * Author: rlcancian
 *
 * Created on 22 de novembro de 2021, 17:24
 */

#ifndef PROBABILITYDISTRIBUTION_H
#define PROBABILITYDISTRIBUTION_H

#include "ProbabilityDistributionBase.h"

class ProbabilityDistribution : public ProbabilityDistributionBase {
public:
	static double inverseChi2(double cumulativeProbability, double degreeFreedom);
	static double inverseFFisherSnedecor(double cumulativeProbability, double d1, double d2);
	static double inverseNormal(double cumulativeProbability, double mean, double stddev);
	static double inverseTStudent(double cumulativeProbability, double mean, double stddev, double degreeFreedom);
private:
	static double _findInverseChi2(double a, double fa, double b, double fb, unsigned int recursions, double cumulativeProbability, double degreeFreedom);
	static double _findInverseFFisherSnedecor(double a, double fa, double b, double fb, unsigned int recursions, double cumulativeProbability, double d1, double d2);
	static double _findInverseNormal(double a, double fa, double b, double fb, unsigned int recursions, double cumulativeProbability, double mean, double stddev);
	static double _findInverseTStudent(double a, double fa, double b, double fb, unsigned int recursions, double cumulativeProbability, double mean, double stddev, double degreeFreedom);
private:
	static std::map<std::string, double>* memory; // = std::map<std::string, double>();
	static Solver_if* integrator;
};
#endif /* PROBABILITYDISTRIBUTION_H */

