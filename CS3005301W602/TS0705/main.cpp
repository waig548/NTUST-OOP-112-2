#include <iostream>
#include <string>
#include <vector>

class CowTablet {
    public:
    CowTablet(const std::vector<std::string>& contents) {
        num1 = CowNumber(contents[0]);
        num2 = CowNumber(contents[1]);
        for (int i = 2; i < 5; i++)
            ops.push_back(CowOperator::byID(contents[i][0]));
        expectedResult = CowNumber(contents[5]);
    }

    bool verify() const {
        CowNumber base = num2;
        for (auto e: ops) {
            base = e->performOperation(num1, base);
        }
        return base == expectedResult;
    }

    class CowNumber {
        public:
        CowNumber(): CowNumber(std::string("")) {
        }
        CowNumber(const std::string& raw): raw(raw) {
            for (auto it = raw.rbegin(); it != raw.rend(); it++)
                numeric.push_back(std::find(LITERALS.begin(), LITERALS.end(), *it) - LITERALS.begin());
        }
        CowNumber(const std::vector<int>& numeric): numeric(numeric) {
            for (auto it = numeric.rbegin(); it != numeric.rend(); it++)
                raw.push_back(LITERALS[*it]);
        }

        std::string getRaw() const {
            return raw;
        }
        std::vector<int> getNumeric() const {
            return numeric;
        }

        bool operator==(const CowNumber& other) const {
            std::vector<int> num1 = numeric, num2 = other.numeric;
            int              fullLength = std::max(num1.size(), num2.size());
            num1.resize(fullLength, 0);
            num2.resize(fullLength, 0);
            return num1 == num2;
        }

        static std::vector<char> const LITERALS;

        private:
        std::string      raw;
        std::vector<int> numeric;
    };

    class CowOperator {
        public:
        virtual char      getID() const                                                        = 0;
        virtual CowNumber performOperation(const CowNumber& num1, const CowNumber& num2) const = 0;

        static CowOperator* byID(char id) {
            auto result = std::find_if(OPERATORS.begin(), OPERATORS.end(), [id](auto it) {
                return (*it).getID() == id;
            });
            return *result;
        }

        static std::vector<CowOperator*> const OPERATORS;

        class Add;
        class ShiftLeft;
        class ShiftRight;
        class Nop;
    };
    class CowOperator::Add: public CowOperator {
        public:
        char getID() const override {
            return 'A';
        }
        CowNumber performOperation(const CowNumber& num1, const CowNumber& num2) const override {
            std::vector<int> base = num2.getNumeric(), addnum = num1.getNumeric();
            auto             cur   = base.begin();
            int              carry = 0;
            while (cur != base.end()) {
                int tmp = *cur + carry;
                if ((cur - base.begin()) < addnum.size())
                    tmp += addnum[cur - base.begin()];
                carry = tmp / 4;
                *cur  = tmp % 4;
                cur++;
            }
            if (carry)
                base.push_back(1);
            return CowNumber(base);
        }
    };
    class CowOperator::ShiftLeft: public CowOperator {
        public:
        char getID() const override {
            return 'L';
        }
        CowNumber performOperation(const CowNumber& num1, const CowNumber& num2) const override {
            return CowNumber(num2.getRaw() + 'V');
        }
    };
    class CowOperator::ShiftRight: public CowOperator {
        public:
        char getID() const override {
            return 'R';
        }
        CowNumber performOperation(const CowNumber& num1, const CowNumber& num2) const override {
            std::string newNum(num2.getRaw());
            newNum.insert(0, 1, 'V');
            newNum.resize(num2.getRaw().size());
            return CowNumber(newNum);
        }
    };
    class CowOperator::Nop: public CowOperator {
        public:
        char getID() const override {
            return 'N';
        }
        CowNumber performOperation(const CowNumber& num1, const CowNumber& num2) const override {
            return num2;
        }
    };

    private:
    CowNumber                 num1;
    CowNumber                 num2;
    std::vector<CowOperator*> ops;
    CowNumber                 expectedResult;
};

std::vector<char> const                    CowTablet::CowNumber::LITERALS{'V', 'U', 'C', 'D'};
std::vector<CowTablet::CowOperator*> const CowTablet::CowOperator::OPERATORS{
  new CowTablet::CowOperator::Add, new CowTablet::CowOperator::ShiftLeft, new CowTablet::CowOperator::ShiftRight,
  new CowTablet::CowOperator::Nop};

int main() {
    int N;
    std::cin >> N;
    std::cout << "COWCULATIONS OUTPUT" << std::endl;
    while (N--) {
        std::vector<std::string> contents(6);
        for (int i = 0; i < 6; i++)
            std::cin >> contents[i];
        CowTablet tablet(contents);
        if (tablet.verify())
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << std::endl;
    }
    std::cout << "END OF OUTPUT" << std::endl;
}