#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

class Translator {
    public:
    class Unit {
        public:
        const char in;
        const char out;
        Unit(const char in, const char out): in(in), out(out) {
        }
    };
    void addTranslationUnit(Unit unit) {
        translationUnits.push_back(unit);
        translatabilityMap.try_emplace(unit.in, std::set<char>());
        translatabilityMap[unit.in].insert(unit.out);
    }

    void addTranslationUnit(const char in, const char out) {
        addTranslationUnit(Unit(in, out));
    }

    void populateTranslatability() {
        bool unstable = true;
        while (unstable) {
            unstable = false;
            for (auto& p: translatabilityMap) {
                auto preSize = p.second.size();
                for (auto e: p.second) {
                    if (translatabilityMap.find(e) != translatabilityMap.end()) {
                        p.second.insert(translatabilityMap[e].begin(), translatabilityMap[e].end());
                    }
                }
                unstable |= p.second.size() != preSize;
            }
        }
        return;
    }

    bool matches(const std::string& input, const std::string& desired) {
        if (input.length() != desired.length())
            return false;
        if (input == desired)
            return true;
        for (int i = 0; i < desired.length(); i++) {
            if (!translatableTo(input[i], desired[i]))
                return false;
        }
        return true;
    }

    private:
    std::vector<Unit>              translationUnits;
    std::map<char, std::set<char>> translatabilityMap;

    inline bool translatableTo(char in, char desired) {
        if (in == desired)
            return true;
        if (translatabilityMap.find(in) == translatabilityMap.end())
            return false;
        return translatabilityMap[in].find(desired) != translatabilityMap[in].end();
    }
};

int main() {
    int m, n;
    while (std::cin >> m >> n) {
        if (m == 0 && n == 0)
            break;

        Translator translator;
        for (int i = 0; i < m; i++) {
            char in, out;
            std::cin >> in >> out;
            translator.addTranslationUnit(in, out);
        }
        translator.populateTranslatability();

        for (int i = 0; i < n; i++) {
            std::string input, desired;
            std::cin >> input >> desired;

            if (translator.matches(input, desired))
                std::cout << "yes";
            else
                std::cout << "no";
            std::cout << std::endl;
        }
    }
}