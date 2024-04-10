#include <iostream>
#include <vector>
class VecNf {
    private:
    std::vector<float> values;

    VecNf(std::vector<float> values): values(values) {
    }

    public:
    VecNf(): VecNf(0, 0) {
    }
    VecNf(float* dest, int cnt) {
        if (dest)
            for (int i = 0; i < cnt; i++)
                values.push_back(dest[i]);
    }
    VecNf(const VecNf& rhs): values(rhs.values) {
    }

    size_t Size() const {
        return values.size();
    }

    VecNf& operator=(const VecNf& rhs) {
        values = std::vector<float>(rhs.values);
        std::cout << "ASSIGNMENT!!!" << std::endl;
        return *this;
    }

    float& operator[](const size_t pos) {
        return values[pos];
    }

    friend static VecNf operator+(const VecNf& a, const VecNf& b) {
        if (!checkDimension(a, b))
            return VecNf();
        auto res(a.values);
        for (int i = 0; i < res.size(); i++)
            res[i] += b.values[i];
        return VecNf(res);
    }

    friend static VecNf operator-(const VecNf& a, const VecNf& b) {
        if (!checkDimension(a, b))
            return VecNf();
        auto res(a.values);
        for (int i = 0; i < res.size(); i++)
            res[i] -= b.values[i];
        return VecNf(res);
    }

    friend static float operator*(const VecNf& a, const VecNf& b) {
        if (!checkDimension(a, b))
            return 0;
        float res = 0;
        for (int i = 0; i < a.Size(); i++)
            res += a.values[i] * b.values[i];
        return res;
    }

    friend static VecNf operator*(const VecNf& vec, const float scalar) {
        auto res(vec.values);
        for (auto& e: res)
            e *= scalar;
        return VecNf(res);
    }

    friend static inline VecNf operator*(const float scalar, const VecNf& vec) {
        return vec * scalar;
    }

    private:
    static inline bool checkDimension(const VecNf& a, const VecNf& b) {
        if (a.Size() != b.Size()) {
            std::cout << "dimensions inconsistent" << std::endl;
            return false;
        }
        return true;
    }
};