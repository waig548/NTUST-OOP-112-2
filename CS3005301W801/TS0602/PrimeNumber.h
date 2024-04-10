#include <array>
#include <utility>

class PrimeNumber {
    private:
    int value;

    public:
    PrimeNumber(): PrimeNumber(1) {
    }
    PrimeNumber(int _value): value(_value) {
    }

    int get() {
        return value;
    }
    PrimeNumber& operator++() {
        while (!isPrime(++value))
            ;
        return *this;
    }
    PrimeNumber operator++(int) {
        int old = value;
        ++(*this);
        return PrimeNumber(old);
    }
    PrimeNumber& operator--() {
        while (!isPrime(--value))
            ;
        return *this;
    }
    PrimeNumber operator--(int) {
        int old = value;
        --(*this);
        return PrimeNumber(old);
    }

    private:
    static bool isPrime(int n) {
        if (n < 1)
            return false;
        for (size_t i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
};
