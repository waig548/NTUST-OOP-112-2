#include <string>
#include <iostream>
#include <vector>
#include <sstream>

typedef struct {
	char firstName[25 + 1];
	char lastName[30 + 1];
	char phone[15 + 1];
} StRec;

int printRecords(const std::vector<StRec>& records) {
	if (!records.size())
		return 1;
	for (auto e : records)
		std::cout << e.firstName << " " << e.lastName << " " << e.phone << std::endl;
	return 0;
}

int checkArgs(const std::string& fN, const std::string& lN, const std::string& pN) {
	if (fN.size() > 25 || lN.size() > 30 || pN.size() > 15)
		return 1;
	for (auto e : fN) {
		if (!std::isalpha(e))
			return 1;
	}for (auto e : lN) {
		if (!std::isalpha(e))
			return 1;
	}
	for (auto e : pN)
		if (!std::isdigit(e))
			return 1;
	return 0;
}

int searchRecord(const std::vector<StRec>& records, const std::string& fN, const std::string& lN, const std::string& pN) {
	auto res = std::find_if(records.begin(), records.end(), [fN, lN, pN](StRec record) {
		return std::string(record.firstName) == fN &&
			std::string(record.lastName) == lN &&
			std::string(record.phone) == pN;
		});
	if (res == records.end())
		return -1;
	return res - records.begin();
}
int insertRecord(std::vector<StRec>& records, const std::string& fN, const std::string& lN, const std::string& pN) {
	if(records.size()>=10 || searchRecord(records, fN, lN, pN) != -1)
		return 1;
	StRec record = { 0 };
	memcpy_s(record.firstName, 25, fN.c_str(), fN.size());
	memcpy_s(record.lastName, 30, lN.c_str(), lN.size());
	memcpy_s(record.phone, 15, pN.c_str(), pN.size());
	records.push_back(record);
	return 0;
}
int deleteRecord(std::vector<StRec>& records, const std::string& fN, const std::string& lN, const std::string& pN) {
	int res = searchRecord(records, fN, lN, pN);
	if (res== -1)
		return 1;
	records.erase(records.begin() + res);
	return 0;
}

int processPrompt(std::vector<StRec>& records, const std::string& command, const std::string& args) {
	std::stringstream ss(args);
	std::string fN, lN, pN;
	ss >> fN >> lN >> pN;
	if (ss.fail())
		return 1;
	if (checkArgs(fN, lN, pN))
		return 1;

	if (command == "search") {
		int res = searchRecord(records, fN, lN, pN);
		if (res == -1)
			std::cout << "Search Error" << std::endl;
		else
			std::cout << res << std::endl;
	}
	else if (command == "insert") {
		if (insertRecord(records, fN, lN, pN))
			std::cout << "Insert Error" << std::endl;
	}
	else if (command == "delete") {
		if (deleteRecord(records, fN, lN, pN))
			std::cout << "Delete Error" << std::endl;
	}
	else
		return 1;

	return 0;
}

int main() {
	std::vector<StRec> records;
	std::string command, args;
	while (std::cin >> command) {
		std::getline(std::cin, args);
		if (command == "print") {
			if (printRecords(records))
				std::cout << "Print Error" << std::endl;
		}
		else if (processPrompt(records, command, args)) {
			std::cout << "Input Error" << std::endl;
		}
	}

}