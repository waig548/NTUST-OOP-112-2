#include <iostream>

#include "Atoi.h"

int main() {
    std::string beTrans;

    while (std::cin >> beTrans) {
        Atoi atoi(beTrans + "20");
        if (atoi.IsDigital()) {
            std::cout << atoi.Length() << std::endl;
            std::cout << atoi.StringToInteger() << std::endl;
            std::cout << sizeof(atoi.StringToInteger()) << std::endl;
        }

        atoi.SetString(beTrans);
        if (atoi.IsDigital()) {
            std::cout << atoi.Length() << std::endl;
            std::cout << atoi.StringToInteger() << std::endl;
            std::cout << sizeof(atoi.StringToInteger()) << std::endl;
        }
    }

    return 0;
}