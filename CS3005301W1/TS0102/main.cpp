#include <iostream>

int main() {
    unsigned long long int t;
    while (std::cin >> t) {
        int                    s = t % 60;
        int                    m = (t / 60) % 60;
        unsigned long long int h = t / 3600;
        std::cout << h << " hours " << m << " minutes and " << s << " seconds" << std::endl;
    }
}