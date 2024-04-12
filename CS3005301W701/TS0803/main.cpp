#include <iostream>
#include <map>
#include <sstream>
#include <string>

class MemoryBlock {
    private:
    char*  block;
    size_t size;

    public:
    MemoryBlock(size_t size): size(size) {
        block = (char*)malloc(size * sizeof(char));
        if (block)
            memset(block, 0, size * sizeof(char));
    }
    ~MemoryBlock() {
        delete[] block;
    }

    void set(int pos, const std::string& type, const std::string& value) {
        if (pos < 0)
            throw std::exception();
        bool overflow = (pos + typeSizes.at(type) > size);
        if (type == "String") {
            auto cur = value.begin();
            while (pos < size && cur != value.end()) {
                block[pos] = *cur;
                cur++;
                pos++;
            }
            overflow |= pos == size;
        } else {
            size_t typeSize     = typeSizes.at(type);
            size_t raw          = std::stoull(value);
            size_t amountToCopy = std::min(size - pos, typeSize);
            memcpy_s(block + pos, amountToCopy, &raw, amountToCopy);
        }
        if(overflow)
            throw std::exception();
    }

    std::string get(int pos, const std::string& type) const {
        if (pos < 0)
            throw std::exception();
        if(pos + typeSizes.at(type) > size)
            throw std::exception();
        if (type == "String") {
            std::string res;
            while (pos < size && block[pos]) {
                res.push_back(block[pos]);
                pos++;
            }
            return res;
        } else {
            size_t typeSize = typeSizes.at(type);
            unsigned int raw = 0;
            memcpy_s(&raw, typeSize, block + pos, typeSize);
            return std::to_string(raw);
        }
    }

    static const std::map<std::string, size_t> typeSizes;
};

const std::map<std::string, size_t> MemoryBlock::typeSizes{{"char", 1}, {"short", 2}, {"int", 4}, {"String", 1}};

int main() {
    int N, T;
    std::cin >> N;
    MemoryBlock block(N);
    std::cin >> T;
    while (T--) {
        std::string op, args, type, value, tmp;
        int         pos;
        std::cin >> op;
        std::getline(std::cin, args);

        std::stringstream prompt(args);
        prompt >> pos >> type >> value;
        std::getline(prompt, tmp);
        value += tmp;
        if (std::cin.bad() || prompt.bad() || MemoryBlock::typeSizes.find(type) == MemoryBlock::typeSizes.end())
            continue;

        try {
            if (op == "Set") {
                block.set(pos, type, value);
            } else if (op == "Get") {
                std::cout << block.get(pos, type) << std::endl;
            }
        } catch (std::exception e) {
            std::cout << "Violation Access." << std::endl;
        }
    }
}