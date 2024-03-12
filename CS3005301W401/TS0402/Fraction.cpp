#include "Fraction.h"

#include <iostream>

int gcd(int a, int b) {
    if (b)
        while ((a %= b) && (b %= a))
            ;
    return a + b;
}

void Fraction::setNumerator(int nu) {
    numerator = nu;
}

void Fraction::setDenominator(int de) {
    denominator = de;
}

void Fraction::getDouble() {
    if (denominator != ::gcd(numerator, denominator))
        std::cout << std::fixed;
    else
        std::cout << std::defaultfloat;
    std::cout << (double)numerator / (double)denominator << std::endl;
}

void Fraction::outputReducedFraction() {
    int gcd       = ::gcd(numerator, denominator);
    int reducedNu = numerator / gcd, reducedDe = denominator / gcd;
    std::cout << reducedNu;
    if (reducedDe ^ 1)
        std::cout << "/" << reducedDe;
    std::cout << std::endl;
}
