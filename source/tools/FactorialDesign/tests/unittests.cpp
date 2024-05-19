#include <iostream>
#include <cassert>
#include <cmath>
#include "../FactorialDesign.h"

// Helper function to compare two doubles assuming a certain tolerance to avoid rounding errors
bool areEqual(const double x1, const double x2, double tolerance) {
    return abs(x1 - x2) <= tolerance;
}

// Helper function to compare two vectors of doubles assuming a certain tolerance to avoid rounding errors
bool areEqualVectors(const std::vector<double>& v1, const std::vector<double>& v2, double tolerance) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (size_t i = 0; i < v1.size(); ++i) {
        // Use std::fabs for absolute value comparison
        if (std::fabs(v1[i] - v2[i]) > tolerance) {
            return false;
        }
    }
    return true;
}

// Structure of expected test parameters
struct TestParameters {
    int k;
    int p;
    int r;
    std::vector<std::vector<int>> resultsMatrix;
    std::vector<double> resultsMean;
    std::vector<double> effectSums;
    std::vector<double> effectAverages;
    std::vector<int> squareSums;
    double squareSumError;
    double squareSumTotal;
    std::vector<double> factorVariations;
    double errorVariation;
};

// Function to test the FactorialDesign class with given parameters
void testFactorialDesign(const TestParameters& parameters) {
    const int TOLERANCE = 1e-6; // To avoid rounding errors of floating point numbers

    // Create FactorialDesign instance with specified parameters
    FactorialDesign factorialDesign = FactorialDesign(parameters.k, parameters.p, parameters.r);
    factorialDesign.setResultsMatrix(parameters.resultsMatrix);

    // Test the design feasibility
    assert(factorialDesign.checkFeasibility());
    std::cout << " 1) Test passed! - Design feasibility check" << std::endl;

    // Test the generation of index combinations
    factorialDesign.generateIndexCombinations();
    // There should be 2^(k-p) - 1 index combinations
    assert(factorialDesign.getIndexCombinations().size() == pow(2, parameters.k-parameters.p) - 1);
    std::cout << " 2) Test passed! - Generation of index combinations" << std::endl;

    // Test the creation of column labels
    factorialDesign.createColumnLabels();
    // There should be 2^(k-p) + r + 2 column labels
    assert(factorialDesign.getColumnLabels().size() == pow(2, parameters.k-parameters.p) + parameters.r + 2);
    std::cout << " 3) Test passed! - Creation of column labels" << std::endl;

    // Test the generation of inputs
    factorialDesign.generateInputs();
    // There should be 2^(k-p) inputs
    assert(factorialDesign.getInputs().size() == pow(2, parameters.k-parameters.p));
    std::cout << " 4) Test passed! - Generation of inputs" << std::endl;

    // Test the calculation of results mean
    factorialDesign.calculateResultsMean();
    assert(areEqualVectors(factorialDesign.getResultsMean(), parameters.resultsMean, TOLERANCE));
    std::cout << " 5) Test passed! - Calculation of mean of the experimental results" << std::endl;

    // Test the creation of the sign table
    factorialDesign.createSignTable();
    assert((int) factorialDesign.getSignTable().size() == factorialDesign.NUM_ROWS);
    std::cout << " 6) Test passed! - Creation of sign table" << std::endl;

    // Perform calculation of statistics for the following tests
    factorialDesign.calculateStatistics();

    // Test the calculation of effect sums
    assert(areEqualVectors(factorialDesign.getEffectSums(), parameters.effectSums, TOLERANCE));
    std::cout << " 7) Test passed! - Calculation of effect sums" << std::endl;

    // Test the calculation of effect averages
    assert(areEqualVectors(factorialDesign.getEffectAverages(), parameters.effectAverages, TOLERANCE));
    std::cout << " 8) Test passed! - Calculation of effect averages" << std::endl;

    // Test the calculation of square sums
    assert(factorialDesign.getSquareSums() == parameters.squareSums);
    std::cout << " 9) Test passed! - Calculation of square sums" << std::endl;

    // Test the calculation of square sum of experimental error
    assert(areEqual(factorialDesign.getSquareSumError(), parameters.squareSumError, TOLERANCE));
    std::cout << "10) Test passed! - Calculation of square sum of experimental error" << std::endl;

    // Test the calculation of square sum total
    assert(areEqual(factorialDesign.getSquareSumTotal(), parameters.squareSumTotal, TOLERANCE));
    std::cout << "11) Test passed! - Calculation of square sum total" << std::endl;

    // Test the calculation of factor variations (impacts)
    assert(areEqualVectors(factorialDesign.getFactorVariations(), parameters.factorVariations, TOLERANCE));
    std::cout << "12) Test passed! - Calculation of factor variations (impacts)" << std::endl;

    // Test the calculation of error variation (impact)
    assert(areEqual(factorialDesign.getErrorVariation(), parameters.errorVariation, TOLERANCE));
    std::cout << "13) Test passed! - Calculation of error variation (impact)" << std::endl;

    // Test the coefficients of linear regression model (same as effect averages)
    assert(areEqualVectors(factorialDesign.getEffectAverages(), parameters.effectAverages, TOLERANCE));
    std::cout << "14) Test passed! - Coefficients of linear regression model" << std::endl;

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    // Expected results for the tests are defined below

    // Example 8.4 from Montgomery (2001) - Design and Analysis of Experiments, 5th edition    
    int k = 6;
    int p = 2;
    int r = 1;

    std::vector<std::vector<int>> resultsMatrix {
        {6, 10, 32, 60, 4, 15, 26, 60, 8, 12, 34, 60, 16, 5, 37, 52}
    };

    std::vector<double> resultsMean {
        6.0, 10.0, 32.0, 60.0, 4.0, 15.0, 26.0, 60.0,
        8.0, 12.0, 34.0, 60.0, 16.0, 5.0, 37.0, 52.0
    };

    std::vector<double> effectSums {
        437.0, 111.0, 285.0, -7.0, 11.0, 95.0, -13.0, -43.0,
        -15.0, -1.0, -1.0, 3.0, 1.0, -39.0, 3.0, 5.0
    };

    std::vector<double> effectAverages {
        27.3125,  6.9375, 17.8125, -0.4375,  0.6875, 5.9375,
        -0.8125, -2.6875, -0.9375, -0.0625, -0.0625, 0.1875,
        0.0625, -2.4375,  0.1875,  0.3125
    };

    std::vector<int> squareSums {
        770, 5076, 3, 7, 564, 10, 115, 14, 0, 0, 0, 0, 95, 0, 1
    };

    double squareSumError = 0.0;
    double squareSumTotal = 6655.0;

    std::vector<double> factorVariations {
        11.57, 76.27, 0.05, 0.11, 8.47, 0.15,
        1.73, 0.21, 0, 0, 0, 0, 1.43, 0, 0.02
    };

    double errorVariation = 0.0;

    // Structure of expected test parameters
    TestParameters parameters {
        k, p, r, resultsMatrix, resultsMean, effectSums, effectAverages,
        squareSums, squareSumError, squareSumTotal, factorVariations, errorVariation
    };

    // Perform the test with the specified parameters
    testFactorialDesign(parameters);

    return 0;
}
