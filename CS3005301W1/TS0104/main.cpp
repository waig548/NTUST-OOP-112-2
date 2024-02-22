#include <iomanip>
#include <iostream>
#include <string>

int main() {
    std::string buf;
    while (std::cin >> buf) {
        std::cout << std::setw(10) << buf << std::endl;
    }
}