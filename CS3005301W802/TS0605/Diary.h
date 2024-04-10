#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <vector>

class Diary {
    public:
    class Date {
        public:
        const std::string date;
        const int         id;

        Date(const std::string& date): date(date), id(idHistory) {
            idHistory++;
        }

        friend static inline bool operator==(const Date& a, const Date& b) {
            return a.id == b.id;
        }
        friend static inline bool operator<(const Date& a, const Date& b) {
            return a.id < b.id;
        }

        private:
        static int idHistory;
    };

    static std::vector<Date> recordDays;

    static inline const Date getCurrentDay() {
        return recordDays.back();
    }

    static void NewDay(const std::string& newDay) {
        recordDays.push_back(Date(newDay));
    }
};

std::vector<Diary::Date> Diary::recordDays      = std::vector<Date>();
int                      Diary::Date::idHistory = 0;
#endif
