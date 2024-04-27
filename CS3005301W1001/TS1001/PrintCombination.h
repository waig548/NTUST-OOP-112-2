#ifndef PRINT_COMBINATION_H
#define PRINT_COMBINATION_H

#include <iostream>
#include <vector>

inline void _PrintCombination(const std::vector<int>& arr, int n, int m, const std::vector<int>& keep = std::vector<int>()) {
    if (n < 1 || m < 1) {
        for (int i = 0; i < keep.size(); i++)
            std::cout << (i ? " " : "") << keep[i];
        std::cout << std::endl;
        return;
    }
    if (n == m) {
        for (int i = 0; i < keep.size(); i++)
            std::cout << (i ? " " : "") << keep[i];

        for (int i = 0; i < arr.size(); i++)
            std::cout << ((i || !keep.empty()) ? " " : "") << arr[i];
        std::cout << std::endl;
        return;
    }
    auto leftOver(arr);
    leftOver.erase(leftOver.begin());
    auto newKeep(keep);
    newKeep.push_back(arr[0]);
    _PrintCombination(leftOver, n - 1, m - 1, newKeep);
    _PrintCombination(leftOver, n - 1, m, keep);
}

void PrintCombination(int* arrayPtr, int n, int m) {
    _PrintCombination(std::vector<int>(arrayPtr, arrayPtr + n), n, m);
}

#endif  // !PRINT_COMBINATION_H