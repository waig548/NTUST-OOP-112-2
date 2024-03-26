#include <algorithm>
#include <iostream>
#include <vector>

std::string getRow(const std::string &grid, int rowNum) {
    return grid.substr(rowNum * 9, 9);
}

std::string getColumn(const std::string &grid, int colNum) {
    std::string result;
    for (int i = 0; i < 9; i++)
        result.push_back(grid[i * 9 + colNum]);
    return result;
}

std::string getBox(const std::string &grid, int boxNum) {
    std::string result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.push_back(grid[((boxNum / 3) * 3 + i) * 9 + ((boxNum % 3) * 3 + j)]);
        }
    }
    return result;
}

int hasDuplicate(std::string numbers) {
    const std::string UNIQUE = "123456789";
    std::sort(numbers.begin(), numbers.end());
    return UNIQUE != numbers;
}

int checkGrid(const std::string &grid) {
    for (int i = 0; i < 9; i++) {
        if (hasDuplicate(getRow(grid, i)) || hasDuplicate(getColumn(grid, i)) || hasDuplicate(getBox(grid, i)))
            return 1;
    }
    return 0;
}

int main() {
    std::string grid;
    std::string line;
    while (std::cin >> line) {
        line.resize(std::remove(line.begin(), line.end(), ',') - line.begin());
        grid.append(line);

        if (grid.size() >= 81) {
            if (checkGrid(grid))
                std::cout << "False" << std::endl;
            else
                std::cout << "True" << std::endl;
            grid = "";
        }
    }
}