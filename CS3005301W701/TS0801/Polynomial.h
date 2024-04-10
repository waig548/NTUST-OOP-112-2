#include <algorithm>
#include <vector>

class Polynomial {
    private:
    std::vector<double> coefs;

    Polynomial(std::vector<double> coefs): coefs(coefs) {
    }

    public:
    Polynomial() {
    }
    Polynomial(double* param, int size) {
        for (int i = 0; i < size; i++)
            coefs.push_back(param[i]);
    }
    Polynomial(const Polynomial& copy) {
        for (auto e: copy.coefs)
            coefs.push_back(e);
    }
    ~Polynomial() {
    }

    Polynomial& operator=(const Polynomial& copy) {
        coefs = std::vector<double>();
        for (auto e: copy.coefs)
            coefs.push_back(e);
        return *this;
    }

    double& operator[](size_t index) {
        if (index >= coefs.size())
            coefs.resize(index + 1, 0);
        return coefs[index];
    }

    int mySize() {
        if (coefs.empty())
            return 0;
        return coefs.rend() - std::find_if_not(coefs.rbegin(), coefs.rend(), [](auto it) {
                   return it == 0;
               });
    }

    friend static double evaluate(const Polynomial& poly, const double& var) {
        double res = 0;
        for (int i = 0; i < poly.coefs.size(); i++) {
            res += poly.coefs[i] * std::pow(var, i);
        }
        return res;
    }

    friend static Polynomial operator+(const Polynomial& a, const Polynomial& b) {
        std::vector<double> res(a.coefs);
        res.resize(std::max(a.coefs.size(), b.coefs.size()));
        for (int i = 0; i < b.coefs.size(); i++)
            res[i] += b.coefs[i];
        return Polynomial(res);
    }
    friend static Polynomial operator+(const Polynomial& a, const double& b) {
        return a + Polynomial(std::vector<double>(1, b));
    }
    friend static Polynomial operator+(const double& a, const Polynomial& b) {
        return b + a;
    }

    friend static Polynomial operator-(const Polynomial& a, const Polynomial& b) {
        std::vector<double> res(a.coefs);
        res.resize(std::max(a.coefs.size(), b.coefs.size()));
        for (int i = 0; i < b.coefs.size(); i++)
            res[i] -= b.coefs[i];
        return Polynomial(res);
    }
    friend inline static Polynomial operator-(const Polynomial& a, const double& b) {
        return a - Polynomial(std::vector<double>(1, b));
    }
    friend inline static Polynomial operator-(const double& a, const Polynomial& b) {
        return Polynomial(std::vector<double>(1, a)) - b;
    }

    friend static Polynomial operator*(const Polynomial& a, const Polynomial& b) {
        std::vector<double> res;
        res.resize(a.coefs.size() + b.coefs.size() - 1);
        for (int i = 0; i < b.coefs.size(); i++) {
            for (int j = 0; j < a.coefs.size(); j++)
                res[i + j] += a.coefs[j] * b.coefs[i];
        }
        return Polynomial(res);
    }
    friend inline static Polynomial operator*(const Polynomial& a, const double& b) {
        return a * Polynomial(std::vector<double>(1, b));
    }
    friend inline static Polynomial operator*(const double& a, const Polynomial& b) {
        return b * a;
    }
};