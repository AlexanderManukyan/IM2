#pragma once
#include "lib.h"

class LinearCongruentialGenerator {
private:
    uint64_t current;
    const uint64_t a;    // ���������
    const uint64_t c;    // ����������
    const uint64_t m;    // ������

public:
    LinearCongruentialGenerator(uint64_t seed, uint64_t multiplier, uint64_t increment, uint64_t modulus);

    uint64_t next();

    double nextDouble();
};