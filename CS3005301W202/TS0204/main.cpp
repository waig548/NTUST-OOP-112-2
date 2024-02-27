#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    while (std::cin >> N) {
        std::vector<std::string> names, salaries, awards;
        size_t                   maxNameWidth = 0, maxSalaryWidth = 0, maxAwardWidth = 0;
        while (N--) {
            std::string name, salary, award;
            std::cin >> name >> salary >> award;
            names.push_back(name);
            if (name.length() > maxNameWidth)
                maxNameWidth = name.length();
            salaries.push_back(salary);
            if (salary.length() > maxSalaryWidth)
                maxSalaryWidth = salary.length();
            awards.push_back(award);
            if (award.length() > maxAwardWidth)
                maxAwardWidth = award.length();
        }
        for (size_t i = 0; i < names.size(); i++) {
            std::cout << std::setw(maxNameWidth) << names[i] << '|' << std::setw(maxSalaryWidth + (size_t)2) << salaries[i] << '|'
                      << std::setw(maxAwardWidth + (size_t)2) << awards[i] << std::endl;
        }
    }
}