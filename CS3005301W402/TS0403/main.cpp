#include <iostream>

int gcd(int a, int b) {
    if (b) {
        while ((a %= b) && (b %= a)) {
        }
    }
    return a + b;
}

int main() {
    int a, b;
    while (std::cin >> a >> b) {
        std::cout << gcd(a, b) << std::endl;
    }

    return 0;
}