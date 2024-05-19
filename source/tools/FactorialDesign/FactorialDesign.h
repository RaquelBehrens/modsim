#ifndef FACTORIAL_DESIGN_H
#define FACTORIAL_DESIGN_H

#include <vector>
#include <string>
#include <tuple>

// Class representing a Fractional Factorial Design of Experiments
class FactorialDesign {
public:
    // Design parameters
    int k; // Number of factors investigated
    int p; // Size of the fraction of the full factorial
    int r; // Number of replications
    int NUM_FACTORS; // Derived number of factors
    int NUM_ROWS;  // Number of rows in the sign table

    // Storage of experimental results
    std::vector<std::vector<int>> resultsMatrix; 

    // Constructor and main methods
    FactorialDesign(int k, int p, int r);
    bool checkFeasibility();
    void generateIndexCombinations();
    void createColumnLabels();
    void generateInputs(); 
    void calculateResultsMean();
    void createSignTable();
    void calculateStatistics();
    double linearRegression(const std::vector<int>& xs);
    void showSignTable();
    void showImpacts();
    void showLinearRegressionModel();
    void showResiduals();

    // Getters
    const std::vector<std::vector<int>>& getIndexCombinations() const {
        return indexCombinations;
    }

    const std::vector<std::string>& getColumnLabels() const {
        return columnLabels;
    }

    const std::vector<std::vector<int>>& getInputs() const {
        return inputs;
    }

    const std::vector<double>& getResultsMean() const {
        return resultsMean;
    }

    const std::vector<std::tuple<int, std::vector<int>, std::vector<int>, double>>& getSignTable() const {
        return signTable;
    }

    const std::vector<double>& getEffectSums() const {
        return effectSums;
    }

    const std::vector<double>& getEffectAverages() const {
        return effectAverages;
    }

    const std::vector<int>& getSquareSums() const {
        return squareSums;
    }

    double getSquareSumError() const {
        return squareSumError;
    }

    double getSquareSumTotal() const {
        return squareSumTotal;
    }

    const std::vector<double>& getFactorVariations() const {
        return factorVariations;
    }

    double getErrorVariation() const {
        return errorVariation;
    }

    // Setters
    void setResultsMatrix(const std::vector<std::vector<int>>& matrix) {
        resultsMatrix = matrix;
    }

private:
    // Internal data structures
    std::vector<std::vector<int>> indexCombinations;
    std::vector<std::string> factorLabels;
    std::vector<std::string> columnLabels;
    std::vector<std::vector<int>> inputs;
    std::vector<double> resultsMean;
    std::vector<std::tuple<int, std::vector<int>, std::vector<int>, double>> signTable;
    std::vector<double> effectSums;
    std::vector<double> effectAverages;
    std::vector<int> squareSums;
    double squareSumTotal;
    std::vector<double> factorVariations;
    double squareSumError;
    double errorVariation;

    // Helper method
    std::vector<std::vector<int>> generateCombinations(const std::vector<int>& elements, int length);
};

#endif
