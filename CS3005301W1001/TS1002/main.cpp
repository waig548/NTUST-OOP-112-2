#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

inline std::string getAdjacents(const std::string& board, int pos, int walked) {
    int              x = pos % 4;
    int              y = pos / 4;
    std::vector<int> possibles;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            auto next = std::make_pair(x + i, y + j);
            if (next.first == x && next.second == y)
                continue;
            if (next.first < 0 || next.first >= 4 || next.second < 0 || next.second >= 4)
                continue;
            int nextP = next.second * 4 + next.first;
            if (!(walked & (1 << nextP)))
                possibles.push_back(nextP);
        }
    }
    std::string view(board.length(), 0);
    for (auto i: possibles)
        view[i] = board[i];
    return view;
}

inline bool findWord(const std::string& board, const std::string& word, int walked, int lastPos) {
    if (word.empty())
        return true;
    std::vector<int> nexts;
    std::string      adj;
    if (lastPos < 0)
        adj = board;
    else
        adj = getAdjacents(board, lastPos, walked);

    auto candidate = std::find(adj.begin(), adj.end(), word[0]);
    while (candidate != adj.end()) {
        nexts.push_back(candidate - adj.begin());
        *candidate = 0;
        candidate  = std::find(adj.begin(), adj.end(), word[0]);
    }
    if (nexts.empty())
        return false;
    for (auto pos: nexts) {
        std::string rem(word);
        rem.erase(0, 1);
        if (findWord(board, rem, walked | (1 << pos), pos))
            return true;
    }
    return false;
}

bool isValid(const std::string& board, const std::string& word) {
    if (word.length() < 3 || word.length() > 16)
        return false;
    return findWord(board, word, 0, -1);
}

int main() {
    std::string board;
    std::string tmp;
    while (std::cin >> board) {
        for (size_t i = 0; i < 3; i++) {
            std::cin >> tmp;
            board += tmp;
        }
        std::ifstream f("words.txt");
        std::string   word;
        while (f >> word) {
            if (isValid(board, word))
                std::cout << word << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}