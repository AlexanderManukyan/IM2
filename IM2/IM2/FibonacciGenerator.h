#pragma once
#include "lib.h"

class FibonacciGenerator {
private:
    uint64_t a, b;
    const uint64_t m;

public:
    FibonacciGenerator(uint64_t seed1, uint64_t seed2, uint64_t modulus);

    uint64_t next();

    double nextDouble();
};