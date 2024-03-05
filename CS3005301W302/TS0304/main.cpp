#include <iostream>

int main() {
    const size_t INITIAL_BITS = 4;
    const size_t INITIAL_YEAR = 1900;
    int          Y;
    while (std::cin >> Y) {
        long double currentBits  = INITIAL_BITS * std::powl(2, (Y - INITIAL_YEAR) / 10);
        size_t      N            = 1;
        long double factExponent = 0.0;
        while (factExponent <= currentBits) {
            factExponent += std::log2(N);
            N++;
        }
        std::cout << (N - 2) << std::endl;
    }
}