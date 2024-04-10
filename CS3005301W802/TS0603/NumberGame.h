#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class NumberGame {
    private:
    unsigned int              refNum = 0;
    std::vector<unsigned int> filter;
    std::string               fileName;
    std::vector<unsigned int> res;

    public:
    NumberGame() {
    }
    ~NumberGame() {
    }

    void SetInput(int input) {
        refNum = input;
    }
    void ProcessInput() {
        std::string               ref = std::to_string(refNum);
        std::vector<unsigned int> refs;
        for (auto e: ref) {
            refs.push_back(e - '0');
        }

        for (int k = 1; k <= refs.size(); k++) {
            std::string mask(k, 1);
            mask.resize(refs.size(), 0);

            do {
                unsigned int tmp = 1;
                for (int i = 0; i < refs.size(); i++) {
                    if (mask[i])
                        tmp *= refs[i];
                }
                if (std::find(filter.begin(), filter.end(), tmp) == filter.end())
                    filter.push_back(tmp);
            } while (std::prev_permutation(mask.begin(), mask.end()));
        }
    }
    void SetFileName(std::string name) {
        fileName = name;
    }
    void LoadNumberList() {
        std::ifstream ifs(fileName);
        unsigned int  num;
        while (ifs >> num) {
            if (std::find(filter.begin(), filter.end(), num) != filter.end())
                res.push_back(num);
        }
    }
    void PrintAllValid() {
        for (auto e: res) {
            std::cout << e << std::endl;
        }
    }
    void Reset() {
        refNum = 0;
        filter.clear();
        fileName.clear();
        res.clear();
    }
};