#include "Math.h"

#include <bits/stdc++.h>

#include "Reader_if.h"

#define MAX_DEGREES_OF_FREEDOM 3200

using namespace std;

double Math::average(vector<double>::iterator begin, vector<double>::iterator end) {
    double sum = 0;
    size_t count = 0;
    for (auto it = begin; begin != end; it++) {
        sum += *it;
        count++;
    }

    return sum / count;
}

double Math::average(Reader_if::DataFileIterator begin, Reader_if::DataFileIterator end) {
    double sum = 0;
    size_t count = 0;
    for (auto it = begin; it != end; it++) {
        sum += (*it).value;
        count++;
    }

    return sum / count;
}

double Math::average(vector<Reader_if::Data>::iterator begin, vector<Reader_if::Data>::iterator end) {
    double sum = 0;
    size_t count = 0;
    for (auto it = begin; it != end; it++) {
        sum += it->value;
        count++;
    }

    return sum / count;
}

double Math::weightedAverage(Reader_if::DataFileIterator begin, Reader_if::DataFileIterator end) {
    Reader_if::Data last = *begin;
    double sum = 0;
    auto i = begin;
    while (i != end) {
        Reader_if::Data data = *i;

        sum += last.value * (data.time - last.time);
        last = data;

        i++;
    }
    return sum / last.time;
}

double Math::weightedVariance(std::vector<Reader_if::Data>::iterator begin, std::vector<Reader_if::Data>::iterator end) {
    Reader_if::Data last = *begin;
    double sum = 0;
    double weight_sum = 0;
    std::vector<double> weight_vector;
    auto i = begin;
    while (i != end) {
        Reader_if::Data data = *i;

        double weight = (data.time - last.time);
        sum += last.value * weight;
        weight_sum += weight;
        weight_vector.push_back(weight);
        last = data;

        i++;
    }

    double weighted_average = sum / last.time;
    double sumVariance = 0;
    for (size_t i = 0; i < weight_vector.size(); i++) {
        double xi = (begin + i)->value;
        sumVariance += weight_vector[i] * pow(xi - weighted_average, 2);
    }

    return sumVariance / ((weight_vector.size() - 1) * weight_sum / weight_vector.size());
}

double Math::weightedStddeviation(std::vector<Reader_if::Data>::iterator begin, std::vector<Reader_if::Data>::iterator end) {
    double variance = weightedVariance(begin, end);
    return sqrt(variance);
}

double Math::sum(vector<Reader_if::Data>::iterator begin, vector<Reader_if::Data>::iterator end) {
    double sum = 0;
    for (auto it = begin; begin != end; it++) {
        sum += it->value;
    }
    return sum;
}

double Math::variance(vector<Reader_if::Data>::iterator begin, vector<Reader_if::Data>::iterator end, double avg) {
    double sum = 0;
    size_t count = 0;
    for (auto it = begin; it != end; it++) {
        sum += pow(it->value - avg, 2);
        count++;
    }
    double _variance = sum / (count - 1);
    return _variance;
}


double Math::variance(Reader_if::DataFileIterator begin, Reader_if::DataFileIterator end, double avg) {
    double sum = 0;
    size_t count = 0;
    for (auto it = begin; it != end; it++) {
        sum += pow((*it).value - avg, 2);
        count++;
    }
    double _variance = sum / (count - 1);
    return _variance;
}

double Math::getZ(double probability) {
    const double step = 0.0001;
    double x_min = 0;
    double startIntervalCount = 0;
    double y = 0;
    double halfGaussianaArea = 0.5;
    double gaussianaArea = 0;
    double z = 0;
    bool stopCondition = false;

    while (!stopCondition) {
        y = (exp(-0.5 * pow((x_min), 2))) / (sqrt(2 * M_PI));
        gaussianaArea += std::abs(y * step);

        if ((gaussianaArea / halfGaussianaArea) >= probability) {
            z = x_min;
            stopCondition = true;
        }

        startIntervalCount += step;
        x_min += step;
    }

    return z;
}

double Math::getChi2(long double confidenceLevel, int degreesOfFreedom) {
    if (degreesOfFreedom > MAX_DEGREES_OF_FREEDOM) throw invalid_argument("Cannot calculate chi squared with more then" + to_string(MAX_DEGREES_OF_FREEDOM) + " degrees of freedom, asked for " + to_string(degreesOfFreedom));
    bool stopCondition = false;
    long double  x = 0;
    long double  y = 0;
    long double  step = 0.001;
    long double  chi2TotalArea = 0;
    long double  chi2Critic = 0;        // Valor crítico para aceitar o teste
    long double  k = degreesOfFreedom;  // grau de liberdade

    while (!stopCondition) {
        y = (pow(x, (k / 2) - 1) * exp(-x / 2)) / (pow(2, (k / 2)) * tgamma(k / 2));

        chi2TotalArea += y * step;

        if (chi2TotalArea > (1 - confidenceLevel)) {
            chi2Critic = x;  // Encontra o valor x critico para a aceitação da hipótese
            stopCondition = true;
        }

        x += step;
    }

    return chi2Critic;
}
