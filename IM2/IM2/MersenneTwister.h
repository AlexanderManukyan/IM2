#pragma once
#include "lib.h"
class MersenneTwister {
private:
    static const int N = 624;       // ������ ������� ���������
    static const int M = 397;       // �������� ��������
    static const uint32_t MATRIX_A = 0x9908B0DFU; // ������� ��� ��������������
    static const uint32_t UPPER_MASK = 0x80000000U; // ������� ���
    static const uint32_t LOWER_MASK = 0x7FFFFFFFU; // ��������� ����

    uint32_t mt[N];  // ������ ���������
    int index;       // ������ �������� �����

    // ��������� ������ ���������
    void generateState();

public:
    // ����������� � �������������� seed
    MersenneTwister(uint32_t seed);

    // ��������� ���������� �����
    uint32_t next();

    // ��������� ����� � ��������� ������ � ��������� [0, 1)
    double nextDouble();
};