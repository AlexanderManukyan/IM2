#include "lib.h"
#include "LinearCongruentialGenerator.h"

LinearCongruentialGenerator::LinearCongruentialGenerator(uint64_t seed, uint64_t multiplier, uint64_t increment, uint64_t modulus)
    : current(seed), a(multiplier), c(increment), m(modulus) {}

uint64_t LinearCongruentialGenerator::next() {
    current = (a * current + c) % m;
    return current;
}

double LinearCongruentialGenerator::nextDouble() {
    return static_cast<double>(next()) / m;
}
