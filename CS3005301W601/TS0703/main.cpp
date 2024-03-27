#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> BCDMap{
  std::vector<std::string>{" _ ", "   ", " _ ", " _ ", "   ", " _ ", " _ ", " _ ", " _ ", " _ "},
  std::vector<std::string>{"| |", "  |", " _|", " _|", "|_|", "|_ ", "|_ ", "  |", "|_|", "|_|"},
  std::vector<std::string>{"|_|", "  |", "|_ ", " _|", "  |", " _|", "|_|", "  |", "|_|", " _|"},
};

void printBCDChunk(std::string s) {
    std::vector<std::string> output(3, "");
    for (auto n: s) {
        if (std::isdigit(n)) {
            for (int i = 0; i < 3; i++) {
                output[i] += BCDMap[i][n - '0'];
            }
        }
    }
    for (auto e: output) {
        std::cout << e << std::endl;
    }
}

int main() {
    std::string s, tmp;
    while (std::cin >> s) {
        std::getline(std::cin, tmp);
        s += tmp;
        printBCDChunk(s);
    }

    return 0;
}