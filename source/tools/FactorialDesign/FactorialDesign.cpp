#include <iostream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cmath>
#include <tuple>
#include "FactorialDesign.h"

/**
 * @brief Checks the feasibility of the factorial design.
 *
 * This method evaluates the feasibility of a factorial design based on the number of interactions.
 *
 * @return true if the factorial design is feasible, false otherwise.
 */
bool FactorialDesign::checkFeasibility() {
    return NUM_ROWS - NUM_FACTORS > p;
}

/**
 * @brief Generates combinations of indexes for the Factorial Design of Experiments.
 *
 * This method generates combinations of indexes with lengths ranging from 1 to NUM_FACTORS.
 * The generated combinations are precomputed and utilized to access various data structures.
 * These structures are essential for constructing the sign table and performing statistical calculations.
 */
void FactorialDesign::generateIndexCombinations() {
    std::vector<int> indexes(NUM_FACTORS);
    std::iota(indexes.begin(), indexes.end(), 0);

    // Generate combinations of lengths = {1, 2, ..., NUM_FACTORS}
    for (int length = 1; length <= NUM_FACTORS; ++length) {
        std::vector<std::vector<int>> combinations = generateCombinations(indexes, length);
        indexCombinations.insert(indexCombinations.end(), combinations.begin(), combinations.end());
    }
}

/**
 * @brief Generates combinations of elements from a given set.
 *
 * This helper method produces all possible combinations of elements with a specified length
 * from the provided set of elements. The combinations are generated using a lexicographic
 * ordering approach, and the result is a vector of vectors, each representing a unique combination.
 *
 * @param elements The set of elements from which combinations are generated.
 * @param length The length of each combination to be generated.
 * @return A vector of vectors containing all possible combinations of the specified length.
 */
std::vector<std::vector<int>> FactorialDesign::generateCombinations(const std::vector<int>& elements, int length) {
    std::vector<std::vector<int>> result;
    int n = elements.size();

    if (length <= 0 || length > n) return result;  // Handle invalid input

    // Initialize the first combination (e.g., {0, 1, 2, ..., length-1})
    std::vector<int> combination(length);
    std::iota(combination.begin(), combination.end(), 0);

    // Generate combinations using a lexicographic ordering approach
    while (combination[0] < n - length + 1) {
        // Create a vector to store the current combination
        std::vector<int> current_combination;

        // Map indices to elements based on the current combination
        for (int index : combination) current_combination.push_back(elements[index]);

        // Add the current combination to the result vector
        result.push_back(current_combination);

        // Find the rightmost element that can be incremented
        int i = length - 1;
        while (i >= 0 && combination[i] == i + n - length) i--;

        // Break if all combinations have been generated
        if (i < 0) break;

        // Increment the found element and set the following elements
        // to be consecutive values
        combination[i]++;
        for (int j = i + 1; j < length; ++j) combination[j] = combination[j - 1] + 1;
    }

    return result;
}

/**
 * @brief Adds column labels for the sign table.
 * 
 * This method creates labels for experimental factors (F1, F2, ..., FN), 
 * interaction terms, and results (R1, R2, ..., Rr, R~) based on the combinations
 * of factor levels generated earlier. Additionally, it adds aliases for confounded
 * factors and ensures appropriate labeling for each column in the table.
 * 
 * The resulting column labels are stored in the 'columnLabels' member variable.
 */
void FactorialDesign::createColumnLabels() {
    // Resize factorLabels to accommodate NUM_FACTORS labels
    factorLabels.resize(NUM_FACTORS);

    // Add labels for factors (e.g., F1, F2, ..., FN)
    for (int i = 0; i < NUM_FACTORS; ++i)
        factorLabels[i] = "F" + std::to_string(i + 1);

    // Initialize columnLabels with "Exp." and "I" labels
    columnLabels = {"Exp.", "I"};

    // Add labels for interactions (e.g., F1F2, F1F3, ..., F1F2...FN)
    std::string label;
    for (const std::vector<int>& indexCombination : indexCombinations) {
        label = "";
        for (int index : indexCombination)
            label += factorLabels[index];
        columnLabels.push_back(label);
    }

    // Add aliases for confounded factors (if any)
    for (int i = NUM_FACTORS+2; i < NUM_FACTORS+2+p; ++i)
        columnLabels[i] = "F" + std::to_string(i - 1) + "=" + columnLabels[i];

    // Add labels for experimental results (e.g., R1, R2, ..., Rr), and their mean (R~)
    for (int i = 1; i <= r; ++i)
        columnLabels.push_back("R" + std::to_string(i));
    columnLabels.push_back("R~");
}

/**
 * @brief Generates input vectors of experiments to populate the sign table.
 *
 * This method creates input vectors representing the experimental conditions
 * in a Factorial Design. Each input vector is a combination of factor levels, where
 * the presence of a factor at a high level is represented by '1', whereas a low level
 * is represented by '-1'. The generated input vectors cover all possible combinations
 * of factor levels based on a binary counting pattern.
 *
 * The resulting input vectors are stored in the 'inputs' member variable.
 */
void FactorialDesign::generateInputs() {
    for (int i = 0; i < NUM_ROWS; ++i) {
        // Create the input vector for an experiment
        std::vector<int> input(NUM_FACTORS);
        // Populate the input vector based on the binary representation of 'i'
        for (int j = 0; j < NUM_FACTORS; ++j) input[j] = (i & (1 << j)) ? 1 : -1;
        inputs.push_back(input);
    }
}

/**
 * @brief Calculates the mean of results for each set of experiments from all replications.
 *
 * This method computes the mean of results for each set of experiments
 * from all replications, which are stored in the 'resultsMatrix'.
 *
 * The resulting mean values are stored in the 'resultsMean' member variable.
 */
void FactorialDesign::calculateResultsMean() {
    double sum;
    // Iterate through all sets of experiments
    for (int j = 0; j < NUM_ROWS; ++j) {
        sum = 0;
        // Sum the results from all replications
        for (int i = 0; i < r; ++i)
            sum += resultsMatrix[i][j];
        // Calculate the mean by diving by the number of replications and store it
        resultsMean.push_back(sum / r);
    }
}

/**
 * @brief Creates the sign table for a Factorial Design of Experiments.
 *
 * This method creates a sign table containing inputs and results of all experiments.
 * It calculates the input for each interaction as the product of the inputs of its factors.
 * 
 * The resulting signTable is a vector of tuples, each representing a row in the sign table.
 * Each tuple contains information about an experiment, facilitating further analysis
 * and interpretation of the experimental results.
 */
void FactorialDesign::createSignTable() {
    int product;

    // Iterate through all sets of experiments
    for (int i = 0; i < NUM_ROWS; ++i) {
        const std::vector<int>& input = inputs[i];
        std::vector<int> inputCombination{1};

        // Calculate the input of each interaction as the product of the inputs of its factors
        for (const std::vector<int>& indexCombination : indexCombinations) {
            product = 1;
            for (int index : indexCombination)
                product *= input[index];
            inputCombination.push_back(product);
        }

        // Retrieve the results for the current experiment
        std::vector<int> results;
        for (int j = 0; j < r; ++j)
            results.push_back(resultsMatrix[j][i]);

        // Construct a tuple containing the number of the experiment,
        // the combination of inputs of factors and interactions,
        // the results of all replications and the mean of those results
        signTable.push_back(std::make_tuple(i+1, inputCombination, results, resultsMean[i]));
    }
}

/**
 * @brief Displays the sign table.
 *
 * This method prints the sign table, organized in a tabular format, to the console.
 * The table includes column labels, experiment numbers, input combinations and results.
 * The output is formatted to align columns, providing a clear and readable representation
 * of the experimental conditions and their corresponding information.
 */
void FactorialDesign::showSignTable() {
    // Determine the maximum label length among column labels
    int MAX_LABEL_LENGTH = 0;
    for (const std::string& label : columnLabels)
        MAX_LABEL_LENGTH = std::max(MAX_LABEL_LENGTH, static_cast<int>(label.length()));

    // Lambda function to center-align strings within a given width
    auto center = [MAX_LABEL_LENGTH](const std::string& s) {
        std::string padded = s;
        int maxLength = std::max(MAX_LABEL_LENGTH, static_cast<int>(s.length()));
        int numSpaces = maxLength - s.length();
        int leftSpaces = numSpaces / 2;
        int rightSpaces = numSpaces - leftSpaces;
        return std::string(leftSpaces, ' ') + padded + std::string(rightSpaces, ' ');
    };

    // Display column labels
    for (const std::string& label : columnLabels)
        std::cout << center(label) << " ";
    std::cout << std::endl;

    // Display every row of the sign table
    for (const auto& row : signTable) {
        // Display experiment number
        std::cout << center(std::to_string(std::get<0>(row))) << " ";
        // Display input combinations
        const std::vector<int>& inputCombination = std::get<1>(row);
        for (int input : inputCombination)
            std::cout << center(std::to_string(input)) << " ";
        // Display results of all replications
        const std::vector<int>& results = std::get<2>(row);
        for (int result : results)
            std::cout << center(std::to_string(result)) << " ";
        // Display mean of results rounded to two decimal places
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << std::get<3>(row);
        std::cout << center(ss.str()) << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Calculates statistical measures.
 *
 * This method computes various statistical measures, including effect sums,
 * effect averages, square sums, square sum of errors, square sum total, factor variations,
 * and error variation. These measures are essential for assessing the significance
 * of experimental factors and understanding the variability in the experimental results.
 * The calculated statistics are stored in corresponding member variables for further analysis.
 */
void FactorialDesign::calculateStatistics() {
    // Calculate sum of effects for each input combination
    effectSums.resize(NUM_ROWS);
    for (int j = 0; j < NUM_ROWS; ++j)
        for (int i = 0; i < NUM_ROWS; ++i)
            effectSums[j] += std::get<1>(signTable[i])[j] * resultsMean[i];

    // Calculate averages of effects based on effect sums
    for (int i = 0; i < NUM_ROWS; ++i)
        effectAverages.push_back(effectSums[i] / NUM_ROWS);

    // Calculate square sums for each factor and interaction
    squareSums.resize(NUM_ROWS - 1);
    for (int i = 1; i < NUM_ROWS; ++i)
        squareSums[i - 1] = NUM_ROWS * r * pow(effectAverages[i], 2);

    // Calculate the square sum of the experimental error
    squareSumError = 0;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < NUM_ROWS; ++j)
            squareSumError += pow(resultsMatrix[i][j] - resultsMean[j], 2);

    // Calculate the square sum total by summing square sums and square sum of errors
    squareSumTotal = std::accumulate(squareSums.begin(), squareSums.end(), 0);
    squareSumTotal += squareSumError;

    // Calculate variations for each factor and interaction
    factorVariations.resize(NUM_ROWS - 1);
    for (int i = 0; i < NUM_ROWS - 1; ++i)
        factorVariations[i] = round(10000.0 * squareSums[i] / squareSumTotal) / 100.0;

    // Calculate error variation as a percentage of square sum total
    errorVariation = round(10000.0 * squareSumError / squareSumTotal) / 100.0;
}

/**
 * @brief Performs linear regression based on a set of input factors.
 *
 * This method calculates the predicted result (y) using a linear regression model.
 * The model is constructed using the effect averages for each factor in the Factorial Design,
 * and the input factors provided in the 'xs' vector. The predicted result is the sum
 * of the intercept (effect average for the first factor) and the product of each input
 * factor with its corresponding effect average.
 *
 * @param xs A vector representing the levels of input factors for which the result is predicted.
 * @return The predicted result (y) based on the linear regression model.
 */
double FactorialDesign::linearRegression(const std::vector<int>& xs) {
    // Initialize y with the intercept (effect average for the first factor)
    double y = effectAverages[0];
    double product;
    // Calculate the predicted result using the linear regression model
    for (int i = 1; i < NUM_ROWS; ++i) {
        product = effectAverages[i];
        const std::vector<int>& indexCombination = indexCombinations[i-1];
        // Multiply each input factor with its corresponding effect average
        for (int index : indexCombination)
            product *= xs[index];
        // Add the product to the predicted result
        y += product;
    }
    return y;
}

/**
 * @brief Displays the impacts of factors, interaction of factors and experimental error.
 *
 * This method prints the impacts of individual factors, interaction of factors
 * and experimental error as calculated from the statistical measures.
 * The impacts are represented as percentages of total variability, and provide insights
 * into the significance of each factor and the contribution of experimental error to the overall variability.
 */
void FactorialDesign::showImpacts() {
    // Display the impact of each factor and interaction on the results
    for (int i = 0; i < NUM_ROWS - 1; ++i)
        std::cout << "Impact of " << columnLabels[i+2] << ": " << factorVariations[i] << "%" << std::endl;
    // Display the impact of experimental error on the results
    std::cout << "Impact of experimental error: " << errorVariation << "%" << std::endl << std::endl;
}

/**
 * @brief Displays the linear regression model.
 *
 * This method prints the linear regression model for predicting the result variable
 * based on the inputs of factors and interactions. The model is presented in the form
 * of a mathematical expression, where coefficients are the intercept and the averages 
 * of effects for each factor, including interactions.
 */
void FactorialDesign::showLinearRegressionModel() {
    // Display the start of the expression with the intercept
    std::cout << "R^ = " << effectAverages[0];
    // Iterate through the average of effects of each factor and interaction
    for (int i = 1; i < NUM_ROWS; ++i) {
        // Display the coefficient, which is the average of effects
        std::cout << " + " << effectAverages[i];
        // Display product of the factor and interaction terms
        const std::vector<int>& indexCombination = indexCombinations[i-1];
        for (int index : indexCombination)
            std::cout << "*x" << factorLabels[index];
    }
    std::cout << std::endl << std::endl;
}

/**
 * @brief Displays the residuals for the experimental results.
 *
 * This method calculates and prints the residuals, which represent the differences
 * between the observed experimental results and the values predicted by the linear regression model.
 */
void FactorialDesign::showResiduals() {
    std::cout << "Residuals:" << std::endl;
    double residual;
    // Calculate and display residuals for each experiment
    for (int i = 0; i < NUM_ROWS; ++i) {
        std::vector<int> input = inputs[i];
        double modelResult = linearRegression(input);
        // Calculate and display residuals for each replication
        for (int j = 0; j < r; ++j) {
            residual = resultsMatrix[j][i] - modelResult;
            std::cout << " " << residual;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

// Constructor
FactorialDesign::FactorialDesign(int k, int p, int r) : k(k), p(p), r(r) {
    NUM_FACTORS = k - p;
    NUM_ROWS = 1 << NUM_FACTORS;
}
