#include <iostream>
#include <string>

int main() {
    std::string input;
    while (std::cin >> input) {
        double tmp        = sqrt(input.length());
        size_t sideLength = (size_t)((tmp - (size_t)tmp) ? tmp + 1 : tmp);
        for (size_t i = 0; i < sideLength; i++) {
            for (size_t j = 0; j < sideLength; j++) {
                if (sideLength * j + i < input.length())
                    std::cout << input[sideLength * j + i];
            }
            std::cout << std::endl;
        }
    }
}