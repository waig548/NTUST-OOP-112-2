#include <iostream>
#include <vector>

class Vec {
    public:
    int x;
    int y;
    Vec(): Vec(0, 0) {
    }
    Vec(int x, int y): x(x), y(y) {
    }
    Vec operator+(const Vec& other) const {
        return Vec(x + other.x, y + other.y);
    }
    Vec operator-(const Vec& other) const {
        return Vec(x - other.x, y - other.y);
    }
    bool operator==(const Vec& other) const {
        return x == other.x && y == other.y;
    }
    static std::vector<Vec> directions;
};

std::vector<Vec> Vec::directions{Vec(-1, 0), Vec(1, 0), Vec(0, -1), Vec(0, 1)};

class Board {
    private:
    std::vector<int> contents;

    public:
    Board(const std::vector<int>& symbols): contents(symbols) {
    }

    inline bool checkBounds(Vec p) const {
        return p.x >= 0 && p.x <= 5 && p.y >= 0 && p.y <= 5;
    }

    int getSymbolAt(Vec p) const {
        if (checkBounds(p))
            return contents[6 * p.y + p.x];
        return 0;
    }
    void setSymbolAt(Vec p, int symbol) {
        if (checkBounds(p))
            contents[6 * p.y + p.x] = symbol;
    }

    bool tryMatch(Vec& p1, Vec& p2) const {
        if (p1 == p2)
            return false;
        if (getSymbolAt(p1) != getSymbolAt(p2))
            return false;
        if (!getSymbolAt(p1) || !getSymbolAt(p2))
            return false;
        return findPath(p1, p2);
    }

    bool findPath(const Vec& target, const Vec& cur, const std::vector<int>& dirs = {}) const {
        if (dirs.size() > 3)
            return false;
        if (target == cur)
            return true;
        if (cur.x < -1 || cur.x > 6 || cur.y < -1 || cur.y > 6)
            return false;
        if (dirs.size() && getSymbolAt(cur))
            return false;
        int lastDirection = dirs.empty() ? -1 : dirs.back();
        for (int i = 0; i < Vec::directions.size(); i++) {
            Vec              next = cur + Vec::directions[i];
            std::vector<int> path(dirs);
            if (path.empty() || lastDirection != i)
                path.push_back(i);
            if (i != (lastDirection ^ 1) && findPath(target, next, path))
                return true;
        }
        return false;
    }

    bool tryEliminate(Vec p1, Vec p2) {
        if (tryMatch(p1, p2)) {
            setSymbolAt(p1, 0);
            setSymbolAt(p2, 0);
            return true;
        }
        return false;
    }
};

int main() {
    std::vector<int> symbols(36);
    for (int i = 0; i < 36; i++)
        std::cin >> symbols[i];
    Board board(symbols);
    Vec   p1, p2;
    while (std::cin >> p1.x >> p1.y >> p2.x >> p2.y) {
        if (board.tryEliminate(p1, p2))
            std::cout << "pair matched" << std::endl;
        else
            std::cout << "bad pair" << std::endl;
    }
}
