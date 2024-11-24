#pragma once
#include "lib.h"

double chiSquareTest(const std::vector<double>& values, int numBins);
double autocorrelationTest(const std::vector<double>& values, int lag);
int findPeriod(const std::vector<double>& results);