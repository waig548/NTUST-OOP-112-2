#include <iomanip>
#include <iostream>
#include <vector>

const std::vector<std::pair<double, double>> TAX_BRACKETS = {std::make_pair(750 - 0, 0.01),     std::make_pair(2250 - 750, 0.02),
                                                             std::make_pair(3750 - 2250, 0.03), std::make_pair(5250 - 3750, 0.04),
                                                             std::make_pair(7000 - 5250, 0.05), std::make_pair(0, 0.06)};

int main() {
    double income;
    while (std::cin >> income) {
        double tax = 0;
        for (auto bracket: TAX_BRACKETS) {
            if (income <= 0)
                break;
            tax += (bracket.first ? std::min(income, bracket.first) : income) * bracket.second;
            income -= bracket.first;
        }
        std::cout << std::fixed << std::setprecision(2) << tax << std::endl;
    }
}