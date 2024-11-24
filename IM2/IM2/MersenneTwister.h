#pragma once
#include "lib.h"
class MersenneTwister {
private:
    static const int N = 624;       // Размер массива состояния
    static const int M = 397;       // Параметр смещения
    static const uint32_t MATRIX_A = 0x9908B0DFU; // Матрица для преобразования
    static const uint32_t UPPER_MASK = 0x80000000U; // Старший бит
    static const uint32_t LOWER_MASK = 0x7FFFFFFFU; // Остальные биты

    uint32_t mt[N];  // Массив состояния
    int index;       // Индекс текущего числа

    // Генерация нового состояния
    void generateState();

public:
    // Конструктор с инициализацией seed
    MersenneTwister(uint32_t seed);

    // Генерация следующего числа
    uint32_t next();

    // Генерация числа с плавающей точкой в диапазоне [0, 1)
    double nextDouble();
};