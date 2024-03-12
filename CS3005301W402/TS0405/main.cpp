#include <iostream>

int findCollatzSteps(int n) {
    int steps = 1;
    while (n ^ 1) {
        if (n & 1) {
            n = 3 * n + 1;
        } else {
            n >>= 1;
        }
        steps++;
    }
    return steps;
}

int main() {
    int i, j;
    while (std::cin >> i >> j) {
        int max = 0;
        for (int n = std::min(i, j); n <= std::max(i, j); n++) {
            int steps = findCollatzSteps(n);
            if (steps > max) {
                max = steps;
            }
        }
        std::cout << i << " " << j << " " << max << std::endl;
    }
    return 0;
}