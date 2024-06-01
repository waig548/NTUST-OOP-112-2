// Will Replace by OJ, DO NOT EDIT!
#ifndef TEST_UTILS
#define TEST_UTILS
#include <cstdlib>
#include <iostream>
#define MustEquals(expression, expected)              \
    {                                                 \
        auto got = expression;                        \
        if (got != expected) {                        \
            _MustEquals(#expression, #expected, got); \
        }                                             \
    }

template<class T>
void _MustEquals(const char* expression, const char* expected, T got) {
    std::cout << "Assertion failed: "
              << "expression `" << expression << "`, "
              << "expected `" << expected << "`, "
              << "got `" << got << "`" << std::endl;
    std::exit(0);
}
#define MustEquals_Double(expression, expected)       \
    {                                                 \
        auto got = expression;                        \
        if (!DoubleEquals(got, expected)) {           \
            _MustEquals(#expression, #expected, got); \
        }                                             \
    }
bool DoubleEquals(double a, double b, double epsilon = 0.001) {
    return std::abs(a - b) < epsilon;
}
#define MustNoNull(expression)                                   \
    {                                                            \
        auto got = expression;                                   \
        if (got == nullptr) {                                    \
            _MustEquals(#expression, "(not null pointer)", got); \
        }                                                        \
    }
#endif