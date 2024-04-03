#include <vector>
#include <stdexcept>
#include <iostream>


class Matrix {
    private:
    size_t rows, cols;
    std::vector<double> content;

    public:
    Matrix(size_t rows, size_t cols, const std::vector<double>& content): rows(rows), cols(cols), content(content) {
        this->content.resize(rows * cols, 0);
    }

    Matrix(const Matrix& copy): rows(copy.rows),cols(copy.cols) {
        for (auto e: copy.content)
            content.push_back(e);
    }

    ~Matrix() {
    }

    Matrix& operator=(const Matrix& copy) {
        rows = copy.rows;
        cols = copy.cols;
        content = std::vector<double>();
        for (auto e: copy.content)
            content.push_back(e);
    }

    inline size_t getRows() {
        return rows;
    }

    inline size_t getCols() {
        return cols;
    }

    inline double getAt(size_t row, size_t col) {
        return content[row * cols + col];
    }

    friend static Matrix operator*(const Matrix& a, const Matrix& b) {
        if (a.cols != b.rows)
            throw std::invalid_argument("Matrix dimensions not match.");
        std::vector<double> res;
        for (int i = 0; i < a.rows; i++) {
            for (int j = 0; j < b.cols; j++) {
                res.push_back(dot(getRow(a, i), getCol(b,j)));
            }
        }
        return Matrix(a.rows, b.cols, res);
    }

    private:
    static double dot(std::vector<double> a, std::vector<double> b) {
        if (a.size() != b.size())
            throw std::invalid_argument("Vector dimensions not match.");
        double res = 0;
        for (int i = 0; i < a.size(); i++)
            res += a[i] * b[i];
        return res;
    }

    static std::vector<double> getRow(const Matrix& m, size_t rowNum) {
        std::vector<double> res;
        for (int i = 0; i < m.cols; i++)
            res.push_back(m.content[rowNum * m.cols + i]);
        return res;
    }

    static std::vector<double> getCol(const Matrix& m, size_t colNum) {
        std::vector<double> res;
        for (int i = 0; i < m.rows; i++)
            res.push_back(m.content[i * m.cols + colNum]);
        return res;
    }
};

int main() {
    size_t ar, ac, br, bc;
    std::cin >> ar >> ac >> br >> bc;
    std::vector<double> aNums(ar*ac), bNums(br*bc);
    for (int i = 0; i < aNums.size(); i++) {
        std::cin >> aNums[i];
    }
    for (int i = 0; i < bNums.size(); i++) {
        std::cin >> bNums[i];
    }
    Matrix a(ar, ac, aNums), b(br, bc, bNums);
    try {
        Matrix res = a * b;
        for (int i = 0; i < res.getRows(); i++) {
            for (int j = 0; j < res.getCols(); j++) {
                if (j)
                    std::cout << " ";
                std::cout << res.getAt(i, j);
            }
            std::cout << std::endl;
        }
    } catch (std::invalid_argument e) {
        std::cout << "Matrix multiplication failed." << std::endl;
    }
    
}