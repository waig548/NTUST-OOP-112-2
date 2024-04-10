#include <iostream>

using namespace std;

class Complex {
    private:
    double realValue, imaginaryValue;

    public:
    Complex(): Complex(0, 0) {
    }

    Complex(double r): Complex(r, 0) {
    }

    Complex(double r, double i): realValue(r), imaginaryValue(i) {
    }

    friend inline double real(const Complex& c);
    friend inline double imag(const Complex& c);
    friend inline double norm(const Complex& c);

    inline double real() {
        return realValue;
    }

    inline double imag() {
        return imaginaryValue;
    }

    inline double norm() {
        return sqrt(pow(realValue, 2) + pow(imaginaryValue, 2));
    }

    inline Complex operator+(const Complex& c) {
        return Complex(this->realValue + c.realValue, this->imaginaryValue + c.imaginaryValue);
    }

    inline Complex operator-(const Complex& c) {
        return Complex(this->realValue - c.realValue, this->imaginaryValue - c.imaginaryValue);
    }

    inline Complex operator*(const Complex& c) {
        return Complex(
          this->realValue * c.realValue - this->imaginaryValue * c.imaginaryValue,
          this->realValue * c.imaginaryValue + this->imaginaryValue * c.realValue);
    }

    inline Complex operator/(const Complex& c) {
        double base = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);
        return Complex(
          (this->realValue * c.realValue + this->imaginaryValue * c.imaginaryValue) / base,
          (c.realValue * this->imaginaryValue - this->realValue * c.imaginaryValue) / base);
    }

    friend inline Complex  operator+(double d, const Complex& c);
    friend inline Complex  operator-(double d, const Complex& c);
    friend inline Complex  operator*(double d, const Complex& c);
    friend inline Complex  operator/(double d, const Complex& c);
    friend inline bool     operator==(const Complex& c1, const Complex& c2);
    friend inline ostream& operator<<(ostream& strm, const Complex& c);
    friend inline istream& operator>>(istream& strm, Complex& c);
};

inline double real(const Complex& c) {
    return c.realValue;
}

inline double imag(const Complex& c) {
    return c.imaginaryValue;
}

inline double norm(const Complex& c) {
    return sqrt(pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
}

inline Complex operator+(double d, const Complex& c) {
    return Complex(d) + c;
}

inline Complex operator-(double d, const Complex& c) {
    return Complex(d) - c;
}

inline Complex operator*(double d, const Complex& c) {
    return Complex(d) * c;
}

inline Complex operator/(double d, const Complex& c) {
    return Complex(d) / c;
}

inline bool operator==(const Complex& c1, const Complex& c2) {
    return c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue;
}
inline ostream& operator<<(ostream& strm, const Complex& c) {
    strm << c.realValue << " + " << c.imaginaryValue << "*i";
    return strm;
}
inline istream& operator>>(istream& strm, Complex& c) {
    strm.ignore(LLONG_MAX, '=');
    strm >> c.realValue;
    strm.ignore(LLONG_MAX, '+');
    strm >> c.imaginaryValue;
    strm.ignore(1, '*');
    strm.ignore(1, 'i');
    return strm;
}