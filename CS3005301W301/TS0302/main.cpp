#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::vector<size_t> counts(6, 0);
    int                 n;
    std::ifstream       inputFile("grade.txt", std::ios_base::in);
    std::ofstream       outputFile("grades.Output", std::ios_base::out);
    while (inputFile >> n) {
        counts[n]++;
    }
    for (size_t i = 0; i < 6; i++) {
        outputFile << counts[i] << " grade(s) of " << i << std::endl;
    }
}