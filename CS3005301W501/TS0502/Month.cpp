#include "Month.h"

#include <iostream>

Month::Month(): Month::Month(1) {
}

Month::Month(char first, char second, char third) {
    month = parseAbbreviation(first, second, third);
}

Month::Month(int monthInt) {
    month = fitMonthValue(monthInt);
}

Month::~Month() {
}

void Month::inputInt() {
    int input;
    std::cin >> input;
    month = fitMonthValue(input);
}

void Month::inputStr() {
    char a, b, c;
    std::cin >> a >> b >> c;
    month = parseAbbreviation(a, b, c);
}

void Month::outputInt() {
    std::cout << month;
}

void Month::outputStr() {
    std::cout << abbrs[month - 1];
}

Month Month::nextMonth() {
    return Month(month + 1);
}

int Month::parseAbbreviation(char first, char second, char third) {
    std::string abbr;
    abbr.push_back(first);
    abbr.push_back(second);
    abbr.push_back(third);
    auto res = std::find(abbrs.begin(), abbrs.end(), abbr);
    if (res == abbrs.end())
        return 1;
    else
        return (res - abbrs.begin()) + 1;
}

int Month::fitMonthValue(int monthInt) {
    if (monthInt < 1 || monthInt > 12)
        return 1;
    return monthInt;
}

std::vector<std::string> Month::abbrs = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};