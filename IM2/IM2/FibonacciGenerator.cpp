#include "lib.h"
#include "FibonacciGenerator.h"

FibonacciGenerator::FibonacciGenerator(uint64_t seed1, uint64_t seed2, uint64_t modulus)
    : a(seed1), b(seed2), m(modulus) {}

uint64_t FibonacciGenerator::next() {
    uint64_t nextValue = (a + b) % m;
    a = b;
    b = nextValue;
    return nextValue;
}

double FibonacciGenerator::nextDouble() {
    return static_cast<double>(next()) / m;
}