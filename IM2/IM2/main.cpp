#include "lib.h"
#include "MersenneTwister.h"
#include "LinearCongruentialGenerator.h"
#include "FibonacciGenerator.h"
#include "Test.h"

void generateRandomNumbers(MersenneTwister& customMT, std::mt19937& libMT,
    std::vector<double>& customResults,
    std::vector<double>& libResults, size_t n) {
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for (size_t i = 0; i < n; ++i) {
        customResults.push_back(customMT.nextDouble());
        libResults.push_back(dist(libMT));
    }
}

void saveToCSV(const std::vector<double>& values, const std::string& filename) {
    std::ofstream file(filename);
    for (size_t i = 0; i < values.size() - 1; ++i) {
        file << values[i] << "," << values[i + 1] << "\n";
    }
    file.close();
}


int main() {
    setlocale(LC_ALL, "RUS");
    // ������� ����������
    MersenneTwister customMT(5489U);
    std::mt19937 libMT(5489U);

    LinearCongruentialGenerator lcg(42U, 1664525U, 1013904223U, 4294967296U);
    FibonacciGenerator fibonacci(1U, 1U, 4294967296U);

    std::vector<double> customResults, libResults, lcgResults, fibonacciResults;

    // ���������� 10,000 ��������� �����
    size_t numSamples = 10000;
    generateRandomNumbers(customMT, libMT, customResults, libResults, numSamples);

    for (size_t i = 0; i < numSamples; ++i) {
        lcgResults.push_back(lcg.nextDouble());
        fibonacciResults.push_back(fibonacci.nextDouble());
    }

    // ��������� ������ ��� ������������ ������� (������ Mersenne Twister)
    saveToCSV(customResults, "custom_mt_points.csv");
    saveToCSV(libResults, "lib_mt_points.csv");
    saveToCSV(lcgResults, "LCG_points.csv");
    saveToCSV(fibonacciResults, "fibonacci_points.csv");

    // ��-������� ����
    double customChiSquare = chiSquareTest(customResults, 10);
    double libChiSquare = chiSquareTest(libResults, 10);

    std::cout << "���� ��-�������:\n";
    std::cout << "���������� MT: " << customChiSquare << "\n";
    std::cout << "������������ MT: " << libChiSquare << "\n";

    // ��������������
    double customAutoCorr = autocorrelationTest(customResults, 1);
    double libAutoCorr = autocorrelationTest(libResults, 1);

    std::cout << "\n�������������� (lag=1):\n";
    std::cout << "���������� MT: " << customAutoCorr << "\n";
    std::cout << "������������ MT: " << libAutoCorr << "\n";

    // ����� �������
    int customPeriod = findPeriod(customResults);
    int libPeriod = findPeriod(libResults);

    std::cout << "\n������:\n";
    std::cout << "���������� MT: " << (customPeriod == -1 ? "�� ������" : std::to_string(customPeriod)) << "\n";
    std::cout << "������������ MT: " << (libPeriod == -1 ? "�� ������" : std::to_string(libPeriod)) << "\n";
}