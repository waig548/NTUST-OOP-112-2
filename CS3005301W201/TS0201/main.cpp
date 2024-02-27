#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef long double LD;

size_t parseInput(const std::string &rawInput, std::vector<LD> &numbers) {
    std::stringstream rawInputStream(rawInput);
    std::string       element;

    while (std::getline(rawInputStream, element, ' ')) {
        numbers.push_back(std::stod(element));
    }
    numbers.erase(numbers.begin(), numbers.begin() + 1);
    return 0;
}

LD getMean(const std::vector<LD> &vec) {
    LD sum = 0;
    for (LD e: vec)
        sum += e;
    return sum / vec.size();
}

LD getStdDev(const std::vector<LD> &vec, const LD mean) {
    LD squareDiffSum = 0;
    for (LD e: vec)
        squareDiffSum += pow(e - mean, 2);
    return sqrt(squareDiffSum / vec.size());
}

int main() {
    std::string rawInput;
    while (std::getline(std::cin, rawInput)) {
        std::vector<LD> numbers;
        if (parseInput(rawInput, numbers)) {
            std::cout << "Error parsing input string into a list of numbers" << std::endl;
            continue;
        }
        LD mean   = getMean(numbers);
        LD stdDev = getStdDev(numbers, mean);
        std::cout << "Average:" << mean << "\tStandard deviation:" << stdDev << std::endl;
    }

    return 0;
}