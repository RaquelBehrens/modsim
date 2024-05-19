#include <iostream>
#include <cmath>
#include <string>
#include "test.h"

using namespace std;

std::string showDescription(std::string description) {
    if (description == "") {
        return description;
    }
    return "  (" + description + ")"; 
}

template<typename T>
int TEST_EQUAL(T v1, T v2, std::string description) {
    if ((v1 == v2)) {
        cout << "Ok: " << v1 << " == " << v2 << showDescription(description) << endl;
        return 0;
    }
    cout << "Error: Should be " << v1 << " == " << v2  << showDescription(description) << endl;
    return 1;
}

template<typename T>
int TEST_DIFF(T v1, T v2, std::string description) {
    if ((v1 != v2)) {
        cout << "Ok: " << v1 << " != " << v2 << showDescription(description) << endl;
        return 0;
    }
    cout << "Error: Should be " << v1 << " != " << v2  << showDescription(description) << endl;
    return 1;
}

template<typename T>
int TEST_LESS(T v1, T v2, std::string description) {
    if ((v1 < v2)) {
        cout << "Ok: " << v1 << " < " << v2 << showDescription(description) << endl;
        return 0;
    }
    cout << "Error: Should be " << v1 << " < " << v2 << showDescription(description) << endl;
    return 1;
}

template<typename T>
int TEST_LEQ(T v1, T v2, std::string description) {
    if ((v1 <= v2)) {
        cout << "Ok: " << v1 << " <= " << v2 << showDescription(description) << endl;
        return 0;
    }
    cout << "Error: Should be " << v1 << " <= " << v2 << showDescription(description) << endl;
    return 1;
}

template<typename T>
int TEST_GREATER(T v1, T v2, std::string description) {
    if ((v1 > v2)) {
        cout << "Ok: " << v1 << " > " << v2 << showDescription(description) << endl;
        return 0;
    }
    cout << "Error: Should be " << v1 << " > " << v2 << showDescription(description) << endl;
    return 1;
}

template<typename T>
int TEST_GEQ(T v1, T v2, std::string description) {
    if ((v1 >= v2)) {
        cout << "Ok: " << v1 << " >= " << v2 << showDescription(description) << endl;
        return 0;
    }
    cout << "Error: Should be " << v1 << " >= " << v2 << showDescription(description) << endl;
    return 1;
}

int TEST_EQUAL_FP(double v1, double v2, std::string description, double relativeprecision) {
    double max = v1>=v2?v1:v2;
    double diff = abs(v1-v2)/max;
    cout.precision(16);
    if (diff<=relativeprecision || (max<1e-307)) {
        cout << "Ok: " << v1 << " == " << v2 << showDescription(description) << endl;
        return 0;
    }
    cout << "Error: Values " << v1 << " and " << v2 << " should be equal.";
    cout.precision(6);
    cout  << " Diff: "<< diff << " should be <= "<< relativeprecision;
    cout << showDescription(description) << endl;
    return 1;
}
