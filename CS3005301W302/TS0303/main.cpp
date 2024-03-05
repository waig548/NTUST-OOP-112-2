#include <iomanip>
#include <iostream>
#include <string>

int main() {
    std::string  X;
    unsigned int M, N;
    char         C;
    while (std::cin >> X) {
        std::cin >> M >> N;
        std::cin.ignore(1);
        std::cin.get(C);
        auto floatingPoint = X.find_first_of('.');
        if (floatingPoint == std::string::npos) {
            if (N) {
                X.push_back('.');
                X.resize(X.size() + N, '0');
            }
        } else {
            if (N)
                X.resize(floatingPoint + N + 1, '0');
            else
                X.resize(floatingPoint);
        }
        std::cout << std::setw(M) << std::setfill(C) << X << std::endl;
    }
}