/**
 * @brief
 * Please complete the specified functionality within the function as
 * described in the problem.
 *
 * If you wish to separate declaration and implementation, it is also acceptable
 * to create a file `Polynomial.cpp`
 */

#include <vector>

class Polynomial
{
public:
    Polynomial() : Polynomial(std::vector<double>{})
    {
    }

    Polynomial(const std::vector<double> _coef) : coef(_coef)
    {
        //clean();
    }

    Polynomial(const double* params, int size)
    {
        for (int i = 0; i < size; i++)
            coef.push_back(params[i]);
    }

    Polynomial(const Polynomial& other) : Polynomial(other.coef)
    {

    }

    ~Polynomial()
    {

    }

    Polynomial& operator=(const Polynomial& other)
    {
        coef = other.coef;
        //clean();
        return *this;
    }

    /*double operator[](const int& i)const
    {
        return coef.at(i);
    }*/

    double& operator[](const int& i)
    {
        while (coef.size() < i)
            coef.push_back(0);
        return coef[i];
    }

    int mySize() const
    {
        // return coef.size();
        int res = coef.size();
        auto it = coef.rbegin();
        while (it != coef.rend() && *it == 0)
        {
            res--;
            it++;
        }
        return res;
    }

    Polynomial operator+(const Polynomial& other) const
    {
        auto res = coef;
        res.resize(std::max(res.size(), other.coef.size()), 0);
        for (int i = 0; i < other.coef.size(); i++)
            res[i] += other.coef[i];
        return Polynomial(res);
    }

    Polynomial operator-(const Polynomial& other) const
    {
        auto res = coef;
        res.resize(std::max(res.size(), other.coef.size()), 0);
        for (int i = 0; i < other.coef.size(); i++)
            res[i] -= other.coef[i];
        return Polynomial(res);
    }

    Polynomial operator*(const Polynomial& other) const
    {
        std::vector<double> res(coef.size() + other.coef.size() - 1, 0);
        for (int i = 0; i < other.coef.size(); i++)
        {
            for (int j = 0; j < coef.size(); j++)
            {
                res[i + j] += other.coef[i] * coef[j];
            }
        }
        return Polynomial(res);
    }

    friend double evaluate(const Polynomial& poly, const double& var)
    {
        double res = 0;
        for (int i = 0; i < poly.mySize(); i++)
            res += poly.coef[i] * std::pow(var, i);
        return res;
    }

    friend Polynomial operator+(const Polynomial& a, double b)
    {
        return a + Polynomial({ b });
    }
    friend Polynomial operator+(double  a, const Polynomial& b)
    {
        return Polynomial({ a }) + b;
    }
    friend Polynomial operator-(const Polynomial& a, double b)
    {
        return a - Polynomial({ b });
    }
    friend Polynomial operator-(double  a, const Polynomial& b)
    {
        return Polynomial({ a }) - b;
    }
    friend Polynomial operator*(const Polynomial& a, double b)
    {
        return a * Polynomial({ b });
    }
    friend Polynomial operator*(double  a, const Polynomial& b)
    {
        return Polynomial({ a }) * b;
    }

private:
    void clean()
    {
        while (!coef.empty() && coef.back() == 0)
            coef.pop_back();
    }

    std::vector<double> coef;
};