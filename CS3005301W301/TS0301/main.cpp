#include <iostream>
#include <map>

int main() {
    std::map<int, int> counts;
    int                n;
    while (std::cin >> n) {
        counts.try_emplace(n, 0);
        counts[n]++;
    }
    std::cout << "N\tcount" << std::endl;
    for (auto e = counts.rbegin(); e != counts.rend(); e++) {
        std::cout << e->first << "\t" << e->second << std::endl;
    }
}