#include <string>
#include <vector>
class Month {
    public:
    Month();
    Month(char first, char second, char third);
    Month(int monthInt);
    ~Month();

    void  inputInt();
    void  inputStr();
    void  outputInt();
    void  outputStr();
    Month nextMonth();

    private:
    int                             month;
    static int                      parseAbbreviation(char first, char second, char third);
    static int                      fitMonthValue(int monthInt);
    static std::vector<std::string> abbrs;
};
