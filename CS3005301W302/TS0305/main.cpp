#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef long long int ll;

class Canvas {
    public:
    Canvas(const size_t width, const size_t height): width(width), height(height), bg(std::vector<char>(width * height, '*')) {
    }
    int drawSquare(const size_t w, const ll x, const ll y) {
        if (checkBounds(x, y) || checkBounds(x + w - 1, y + w - 1))
            return 1;
        for (size_t i = 0; i < w; i++) {
            for (size_t j = 0; j < w; j++) {
                bg[(y + i) * this->width + (x + j)] = 'X';
            }
        }
        return 0;
    }
    int drawTriangle(const ll w, const ll x, const ll y, const int horizontalDir, const int verticalDir) {
        if (checkBounds(x, y) || checkBounds(x + horizontalDir * w, y + verticalDir * w))
            return 1;
        for (ll i = 0; i < w; i++) {
            for (ll j = 0; j < w - i; j++) {
                bg[(y + verticalDir * i) * this->width + (x + horizontalDir * j)] = 'X';
            }
        }
        return 0;
    }
    int drawLine(const ll x1, const ll y1, const ll x2, const ll y2) {
        if (checkBounds(x1, y1) || checkBounds(x2, y2))
            return 1;
        long double length    = std::ceil(std::sqrtl(std::powl(x2 - x1, 2) + std::powl(y2 - y1, 2)));
        long double xStepSize = (x2 - x1) / length, yStepSize = (y2 - y1) / length;
        for (size_t i = 0; i <= length; i++) {
            bg[(std::llroundl(y1 + yStepSize * i)) * this->width + std::llroundl(x1 + xStepSize * i)] = 'X';
        }
        return 0;
    }
    void print() const {
        for (size_t i = 0; i < this->height; i++) {
            for (size_t j = 0; j < this->width; j++) {
                std::cout << bg[i * width + j];
            }
            std::cout << std::endl;
        }
    }

    private:
    int checkBounds(const ll x, const ll y) const {
        return x < 0 || y < 0 || x >= this->width || y >= this->height;
    }

    std::vector<char> bg;
    size_t            width;
    size_t            height;
};

int processPrompt(Canvas &canvas, const std::string &prompt) {
    std::istringstream stream(prompt);
    char               instruction;
    stream >> instruction;
    if (instruction == 'S') {
        ll w, x, y;
        stream >> w >> x >> y;
        return canvas.drawSquare(w, x, y);
    }
    if (instruction == 'T') {
        ll          w, x, y;
        std::string face;
        int         horizontalDir, verticalDir;
        stream >> w >> x >> y >> face;
        horizontalDir = face[0] == 'L' ? -1 : face[0] == 'R' ? 1 : 0;
        verticalDir   = face[1] == 'U' ? -1 : face[1] == 'D' ? 1 : 0;
        return canvas.drawTriangle(w, x, y, horizontalDir, verticalDir);
    }
    if (instruction == 'L') {
        ll x1, y1, x2, y2;
        stream >> x1 >> y1 >> x2 >> y2;
        return canvas.drawLine(x1, y1, x2, y2);
    }
    return 1;
}

int main() {
    size_t m, n;
    std::cin >> m >> n;
    Canvas canvas(m, n);
    std::cin.ignore();
    std::string prompt;
    while (1) {
        std::getline(std::cin, prompt);
        if (prompt == "EXIT")
            break;
        if (processPrompt(canvas, prompt))
            std::cout << "Out of range." << std::endl;
        else
            canvas.print();
        std::cout << std::endl;
    }
}