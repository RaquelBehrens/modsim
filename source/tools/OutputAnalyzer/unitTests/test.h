#define TEST_EPSILON 1e-2

#ifndef TEST_VPL_H
#define TEST_VPL_H

#include <iostream>
#include <cmath>
#include <string>

std::string showDescription(std::string description);

template<typename T>
int TEST_EQUAL(T v1, T v2, std::string description="");

template<typename T>
int TEST_DIFF(T v1, T v2, std::string description="");

template<typename T>
int TEST_LESS(T v1, T v2, std::string description="");

template<typename T>
int TEST_LEQ(T v1, T v2, std::string description="");

template<typename T>
int TEST_GREATER(T v1, T v2, std::string description="");

template<typename T>
int TEST_GEQ(T v1, T v2, std::string description="");

int TEST_EQUAL_FP(double v1, double v2, std::string description="", double relativeprecision = TEST_EPSILON);

#endif  /* TEST_VPL_H */