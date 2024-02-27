#include <iostream>
#include <string>

#define is_digit(x) ((x) >= '0' && (x) <= '9')
#define to_digit(x) ((x) - '0')
#define to_char(x)  ((x) + '0')

typedef struct BigInt {
    std::string mag;
} BigInt;

BigInt Add(const BigInt &lhs, const BigInt &rhs) {
    std::string a(lhs.mag), b(rhs.mag);

    size_t workLength = std::max(a.length(), b.length());
    a.insert(0, workLength - a.size(), '0');
    b.insert(0, workLength - b.size(), '0');

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    std::string res;
    int         carry = 0;
    for (size_t i = 0; i < workLength; i++) {
        int digitA = to_digit(a[i]), digitB = to_digit(b[i]);

        int s = carry + digitA + digitB;
        carry = s / 10;
        res.push_back(to_char(s % 10));
    }

    if (carry > 0)
        res.push_back('1');

    std::reverse(res.begin(), res.end());

    BigInt result;
    result.mag = res;
    return result;
}
int main() {
    size_t N;
    std::cin >> N;
    while (N--) {
        BigInt a, b;

        std::cin >> a.mag >> b.mag;

        int checkFail = 0;
        for (auto e: a.mag) {
            if (!isdigit(e)) {
                checkFail = 1;
                break;
            }
        }
        for (auto e: b.mag) {
            if (!isdigit(e)) {
                checkFail = 1;
                break;
            }
        }
        if (checkFail) {
            std::cout << "Not a valid number, please try again." << std::endl;
            continue;
        }

        BigInt res = Add(a, b);
        std::cout << res.mag << std::endl;
    }
}
