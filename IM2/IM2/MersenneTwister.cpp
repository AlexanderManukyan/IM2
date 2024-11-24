#include "lib.h"
#include "MersenneTwister.h"

void MersenneTwister::generateState() {
    for (int i = 0; i < N; ++i) {
        uint32_t y = (mt[i] & UPPER_MASK) | (mt[(i + 1) % N] & LOWER_MASK);
        mt[i] = mt[(i + M) % N] ^ (y >> 1);
        if (y % 2 != 0) { // ���� ������� ��� �� ����� 0
            mt[i] ^= MATRIX_A;
        }
    }
}

// ����������� � �������������� seed
MersenneTwister::MersenneTwister(uint32_t seed) : index(N) {
    mt[0] = seed;
    for (int i = 1; i < N; ++i) {
        mt[i] = 1812433253U * (mt[i - 1] ^ (mt[i - 1] >> 30)) + i;
    }
}

// ��������� ���������� �����
uint32_t MersenneTwister::next() {
    if (index >= N) { // ���� ���� ������ ��������� ��������
        generateState();
        index = 0;
    }

    uint32_t y = mt[index++];

    // ������������� ����� ��� ��������� �����������
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9D2C5680U;
    y ^= (y << 15) & 0xEFC60000U;
    y ^= (y >> 18);

    return y;
}

// ��������� ����� � ��������� ������ � ��������� [0, 1)
double MersenneTwister::nextDouble() {
    return static_cast<double>(next()) / 4294967296.0; // 2^32
}
