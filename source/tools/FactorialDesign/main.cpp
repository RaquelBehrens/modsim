#include <iostream>
#include <vector>
#include "FactorialDesign.h"

/**
 * @brief Fractional Factorial Design of Experiments application.
 *
 * This application uses the FactorialDesign class to interactively create and analyze
 * Fractional Factorial Designs of Experiments. The user is prompted to input design parameters
 * such as the number of factors (k), fraction size (p), and replications (r). The program then
 * generates or receives experimental results and performs statistical analysis based on those experiments.
 * Users then can view the sign table, assess factor and interaction impacts,
 * analyze linear regression model and residuals.
 */
int main() {
    std::cout << "======== Fractional Factorial Design of Experiments ========" << std::endl << std::endl;

    // Prompt user for design parameters: number of factors (k), fraction size (p), and replications (r)
    int k, p, r;
    std::cout << "Enter the number of factors investigated (k): ";
    std::cin >> k;
    std::cout << "Enter the fraction size (p): ";
    std::cin >> p;
    std::cout << "Enter the number of replications (r): ";
    std::cin >> r;

    // Create FactorialDesign object
    FactorialDesign factorialDesign = FactorialDesign(k, p, r);

    // Validate design feasibility based on the number of interactions
    if (!factorialDesign.checkFeasibility()) {
        std::cout << std::endl;
        std::cout << "Design 2^(" << k << "-" << p <<
        ") is impossible due to insufficient interactions." << std::endl;
        return -1;
    }

    // Initialize resultsMatrix for experimental results storage
    factorialDesign.resultsMatrix = std::vector<std::vector<int>>(r, std::vector<int>(factorialDesign.NUM_ROWS));

    // Prompt user for manual or random entry of experimental results
    // Randomized results can be used exclusively for validation of the tool
    bool generateRandom = false;
    std::string command;
    do {
        std::cout << std::endl;
        std::cout << "(1) Manually enter experimental results" << std::endl;
        std::cout << "(2) Generate random experimental results" << std::endl;
        std::cin >> command;
        if (command == "2") generateRandom = true;
    } while (command != "1" && command != "2");

    if (generateRandom) {
        // Generate random experimental results
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < factorialDesign.NUM_ROWS; ++j)
                factorialDesign.resultsMatrix[i][j] = rand() % 100;
    } else {
        // Get experiment results entered manually by the user
        std::cout << std::endl;
        std::cout << "Enter " << r << " sets of " << factorialDesign.NUM_ROWS <<
        " experimental results, separated by spaces:" << std::endl;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < factorialDesign.NUM_ROWS; ++j)
                std::cin >> factorialDesign.resultsMatrix[i][j];
    }
    std::cout << std::endl;

    // Executes all processes in the creation of the factorial design
    factorialDesign.generateIndexCombinations();
    factorialDesign.createColumnLabels();
    factorialDesign.generateInputs();
    factorialDesign.calculateResultsMean();
    factorialDesign.createSignTable();
    factorialDesign.calculateStatistics();

    // Display success message if the design is created successfully
    std::cout << "Factorial design created successfully." << std::endl << std::endl;

    // Display options for further analysis and exploration of the design
    do {
        std::cout << "(1) Show sign table" << std::endl;
        std::cout << "(2) Show impact of factors, interactions and experimental error" << std::endl;
        std::cout << "(3) Show linear regression model" << std::endl;
        std::cout << "(4) Show residuals of linear regression model" << std::endl;
        std::cout << "(5) Exit" << std::endl;
        std::cin >> command;
        std::cout << std::endl;

        // Check user's choice and display corresponding information
        if (command == "1") {
            bool show = true;
            // Check if the sign table is too large and confirm user's intention to display it
            if (factorialDesign.NUM_FACTORS > 4) {
                std::cout << "Sign table is too big. (" << factorialDesign.NUM_ROWS << " rows, " <<
                1 + factorialDesign.NUM_ROWS << " columns)" << std::endl;
                std::cout << "Are you sure you want to show it? (y/n)" << std::endl;
                // Prompt user for confirmation
                do {
                    std::cin >> command;
                } while (command != "y" && command != "n");
                std::cout << std::endl;
                // Set 'show' to false if the user chooses not to display the sign table
                if (command == "n") show = false;
            }
            // Display the sign table if the user chooses to show it
            if (show) factorialDesign.showSignTable();
        }
        else if (command == "2") factorialDesign.showImpacts();
        else if (command == "3") factorialDesign.showLinearRegressionModel();
        else if (command == "4") factorialDesign.showResiduals();
    } while (command != "5");

    // Display ending message for the Fractional Factorial Design
    std::cout << "Fractional factorial design of experiments ended." << std::endl << std::endl;
    return 0;
}
