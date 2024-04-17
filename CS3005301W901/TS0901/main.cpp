#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::string findLongestReversedWord(const std::map<size_t, std::vector<std::string>>& words) {
    auto it = words.rbegin();
    while (it != words.rend()) {
        std::vector<std::string> seen;
        auto                     ref = it->second.rbegin();
        while (ref != it->second.rend()) {
            std::string copy(*ref);
            std::transform(copy.begin(), copy.end(), copy.begin(), std::tolower);
            std::string reversed(copy);
            std::reverse(reversed.begin(), reversed.end());

            if (std::find(seen.begin(), seen.end(), reversed) != seen.end())
                return *ref;
            else
                seen.push_back(copy);
            ref++;
        }
        it++;
    }
    return "";
}

int main() {
    std::map<size_t, std::vector<std::string>> words;

    std::string tmp;
    while (std::cin >> tmp) {
        words.try_emplace(tmp.length(), std::vector<std::string>());
        words[tmp.length()].push_back(tmp);
    }

    std::cout << findLongestReversedWord(words);
}