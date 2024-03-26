#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef struct {
    char firstName[25];
    char lastName[30];
    char phone[15];
} StRec;

int printRecords(const std::vector<StRec>& records) {
    if (records.empty())
        return 1;
    for (const auto& e: records) {
        std::string firstName(e.firstName, 25);
        std::string lastName(e.lastName, 30);
        std::string phone(e.phone, 15);

        std::cout << firstName << " " << lastName << " " << phone << std::endl;
    }
    return 0;
}

int searchRecord(std::vector<StRec>& records, const std::string& firstName, const std::string& lastName, const std::string& phone) {
    auto result = std::find_if(records.begin(), records.end(), [&firstName, &lastName, &phone](StRec record) -> bool {
        return !std::strncmp(firstName.c_str(), record.firstName, 25) && !std::strncmp(lastName.c_str(), record.lastName, 30)
               && !std::strncmp(phone.c_str(), record.phone, 15);
    });
    if (result == records.end())
        return -1;
    return result - records.begin();
}

int insertRecord(std::vector<StRec>& records, const std::string& firstName, const std::string& lastName, const std::string& phone) {
    if (records.size() >= 10 || searchRecord(records, firstName, lastName, phone) != -1)
        return 1;
    StRec record = {0};
    memcpy_s(record.firstName, 25 * sizeof(char), firstName.c_str(), firstName.size());
    memcpy_s(record.lastName, 30 * sizeof(char), lastName.c_str(), lastName.size());
    memcpy_s(record.phone, 15 * sizeof(char), phone.c_str(), phone.size());
    records.push_back(record);
    return 0;
}

int deleteRecord(std::vector<StRec>& records, const std::string& firstName, const std::string& lastName, const std::string& phone) {
    int searchResult = searchRecord(records, firstName, lastName, phone);
    if (searchResult == -1)
        return 1;
    records.erase(records.begin() + searchResult);
    return 0;
}

int processPrompt(const std::string& command, const std::string& args, std::vector<StRec>& records) {
    std::stringstream ss(args);
    std::string       firstName, lastName, phone;
    ss >> firstName >> lastName >> phone;
    if (ss.fail())
        return 1;
    if (firstName.size() > 25 || lastName.size() > 30 || phone.size() > 15)
        return 1;
    if (std::find_if_not(phone.begin(), phone.end(), std::isdigit) != phone.end())
        return 1;

    if (command == "search") {
        int result = searchRecord(records, firstName, lastName, phone);
        if (result < 0)
            std::cout << "Search Error" << std::endl;
        else
            std::cout << result << std::endl;
    } else if (command == "insert") {
        if (insertRecord(records, firstName, lastName, phone))
            std::cout << "Insert Error" << std::endl;
    } else if (command == "delete") {
        if (deleteRecord(records, firstName, lastName, phone))
            std::cout << "Delete Error" << std::endl;
    } else
        return 1;
    return 0;
}

int main() {
    std::vector<StRec> records;
    std::string        command;
    while (std::cin >> command) {
        if (command == "print") {
            if (printRecords(records))
                std::cout << "Print Error" << std::endl;
        } else {
            std::string args;
            std::getline(std::cin, args);
            if (processPrompt(command, args, records))
                std::cout << "Input Error" << std::endl;
        }
    }
}