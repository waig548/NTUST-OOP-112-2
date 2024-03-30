#include <iostream>
#include <regex>
#include <string>
#include <vector>

class BigInteger {
    private:
    int              sign;
    std::string      mag;
    std::vector<int> digits;

    BigInteger(const std::string& numStr): mag(numStr) {
        if (mag.empty()) {
            sign = 0;
        } else {
            sign = mag.front() == '-';
            if (sign)
                mag.erase(mag.begin(), mag.begin() + 1);
        }
        for (auto it = mag.rbegin(); it != mag.rend(); it++)
            digits.push_back((*it) - '0');
    }

    BigInteger(const std::vector<int>& digits, const int sign = 0): digits(digits), sign(sign) {
        for (auto it = digits.rbegin(); it != digits.rend(); it++)
            mag.push_back((*it) + '0');
    }

    static BigInteger add(const BigInteger& lhs, const BigInteger& rhs, bool complement = false) {
        std::vector<int> a = lhs.digits, b = rhs.digits, result;
        size_t           workingLength = std::max(a.size(), b.size());
        a.resize(workingLength, 0);
        b.resize(workingLength, 0);
        int carry = 0, aModif = lhs.sign ? -1 : 1, bModif = rhs.sign ? -1 : 1;
        for (size_t i = 0; i < workingLength; i++) {
            int tmp = aModif * a[i] + bModif * b[i] + carry;
            carry   = tmp < 0 ? -1 : tmp / 10;
            result.push_back((tmp + 10) % 10);
        }
        if (carry < 0 && !complement) {
            std::string complementBase("1");
            complementBase.resize(1 + workingLength, '0');
            BigInteger res = add(BigInteger(complementBase), BigInteger(result, 1), true);
            result         = res.digits;

        } else
            result.push_back(carry);
        while (result.size() > 1 && !result.back()) {
            result.pop_back();
        }
        return BigInteger(result, carry < 0);
    }

    static BigInteger mul(const BigInteger& lhs, const BigInteger& rhs) {
        int        resSign = lhs.sign ^ rhs.sign;
        BigInteger sum;
        for (int i = 0; i < rhs.digits.size(); i++) {
            int              carry = 0;
            std::vector<int> innerSum;
            for (int j = 0; j < lhs.digits.size(); j++) {
                int tmp = lhs.digits[j] * rhs.digits[i] + carry;
                carry   = tmp / 10;
                int s   = tmp % 10;
                innerSum.push_back(s);
            }
            innerSum.push_back(carry);
            innerSum.insert(innerSum.begin(), i, 0);
            sum = add(sum, BigInteger(innerSum));
        }
        return BigInteger(sum.digits, resSign);
    }

    public:
    BigInteger operator+(const BigInteger& other) const {
        return add(*this, other);
    }

    BigInteger operator-(const BigInteger& other) const {
        return add(*this, -other);
    }

    BigInteger operator*(const BigInteger& other) const {
        return mul(*this, other);
    }

    BigInteger operator-() const {
        return BigInteger(digits, !sign);
    }

    std::string toString() const {
        return (sign ? "-" : "") + mag;
    }

    BigInteger(): BigInteger("0") {
    }

    static BigInteger of(const std::string& numStr) {
        if (isNumber(numStr))
            return BigInteger(numStr);
        return BigInteger();
    }

    static bool isNumber(const std::string& numStr) {
        return std::regex_match(numStr.begin(), numStr.end(), std::regex("^-{0,1}[0-9]+$"));
    }
};

int main() {
    std::string sA, sB;
    while (std::cin >> sA >> sB) {
        BigInteger a = BigInteger::of(sA), b = BigInteger::of(sB);
        BigInteger sum = a + b;
        std::cout << sum.toString() << std::endl;
        BigInteger diff = a - b;
        std::cout << diff.toString() << std::endl;
        BigInteger mul = a * b;
        std::cout << mul.toString() << std::endl;
    }
}