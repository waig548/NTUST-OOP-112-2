#include <regex>
#include <string>
using namespace std;

class Atoi {
    private:
    std::string beTrans;

    public:
    Atoi();
    Atoi(std::string s);
    void        SetString(std::string s);
    std::string GetString() const;
    int         Length();
    bool        IsDigital();
    int         StringToInteger();
};

Atoi::Atoi(): Atoi("") {
}

Atoi::Atoi(std::string s): beTrans(s) {
}

void Atoi::SetString(std::string s) {
    beTrans = s;
}

std::string Atoi::GetString() const {
    return beTrans;
}

int Atoi::Length() {
    return beTrans.size() - (beTrans.front() == '-');
}

bool Atoi::IsDigital() {
    return std::regex_match(beTrans.begin(), beTrans.end(), std::regex("^-{0,1}[0-9]+$"));
}

int Atoi::StringToInteger() {
    int res = 0, sign = beTrans.front() == '-';
    for (int i = sign; i < beTrans.length(); i++) {
        res *= 10;
        res += beTrans[i] - '0';
    }
    return sign ? (-1) * res : res;
}