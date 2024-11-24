#include "lib.h"

double chiSquareTest(const std::vector<double>& values, int numBins) {
    // Инициализируем все бины в frequency
    std::map<int, int> frequency;
    for (int i = 0; i < numBins; ++i) {
        frequency[i] = 0;
    }

    // Заполняем частоты
    for (double value : values) {
        int bin = static_cast<int>(value * numBins);
        if (bin >= numBins) bin = numBins - 1; // Гарантируем попадание в последний бин
        frequency[bin]++;
    }

    // Рассчитываем хи-квадрат
    double expected = static_cast<double>(values.size()) / numBins;
    double chiSquare = 0.0;
    for (int bin = 0; bin < numBins; ++bin) {
        int count = frequency[bin];
        double diff = count - expected;
        chiSquare += (diff * diff) / expected;
    }

    return chiSquare;
}

double autocorrelationTest(const std::vector<double>& values, int lag) {
    double mean = 0.0;
    for (double value : values) {
        mean += value;
    }
    mean /= values.size();

    double numerator = 0.0, denominator = 0.0;
    for (size_t i = 0; i < values.size() - lag; ++i) {
        numerator += (values[i] - mean) * (values[i + lag] - mean);
    }

    for (double value : values) {
        denominator += (value - mean) * (value - mean);
    }

    return numerator / denominator;
}

int findPeriod(const std::vector<double>& results) {
    std::unordered_map<std::string, int> history;
    for (int i = 0; i < results.size(); ++i) {
        std::string resultStr = std::to_string(results[i]);
        if (history.find(resultStr) != history.end()) {
            return i - history[resultStr];
        }
        history[resultStr] = i;
    }
    return -1;  // Если период не найден
}