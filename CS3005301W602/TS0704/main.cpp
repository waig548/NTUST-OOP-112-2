#include <iostream>
#include <queue>
#include <string>

size_t levenshteinDistance(const std::string& source, const std::string& target) {
    if (source.empty())
        return target.size();
    if (target.empty())
        return source.size();
    std::queue<size_t> runningSpace;
    for (size_t i = 0; i <= target.size(); i++)
        runningSpace.push(i);
    for (size_t i = 0; i < source.size(); i++) {
        runningSpace.push(i + 1);
        for (size_t j = 0; j < target.size(); j++) {
            size_t totalSubsitutionDistance = runningSpace.front() + (source[i] != target[j]);
            runningSpace.pop();
            size_t totalDeletionDistance  = runningSpace.front() + 1;
            size_t totalInsertionDistance = runningSpace.back() + 1;
            runningSpace.push(std::min(totalSubsitutionDistance, std::min(totalDeletionDistance, totalInsertionDistance)));
        }
        runningSpace.pop();
    }
    return runningSpace.back();
}

int main() {
    std::string a, b, tmp;
    while (std::cin >> a) {
        std::getline(std::cin, tmp);
        a += tmp;
        std::getline(std::cin, b);
        std::cout << levenshteinDistance(a, b) << std::endl;
    }
    return 0;
}