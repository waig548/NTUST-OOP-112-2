#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void parseRecords(std::ifstream &scoreboard, std::vector<std::pair<std::string, int>> &records) {
    while (!scoreboard.eof()) {
        std::string name, score;
        std::getline(scoreboard, name);
        std::getline(scoreboard, score);
        if (!name.empty())
            records.push_back(std::make_pair(name, std::stoi(score)));
    }
}

void getHighScores(std::vector<std::string> &names, std::vector<int> &scores) {
    std::ifstream scoreboard;
    scoreboard.open("scores.txt");

    std::vector<std::pair<std::string, int>> records;
    parseRecords(scoreboard, records);

    std::sort(records.begin(), records.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b) {
        return a.second > b.second;
    });

    for (size_t i = 0; i < 3; i++) {
        names.push_back(records[i].first);
        scores.push_back(records[i].second);
    }
}

int main() {
    std::vector<std::string> names;
    std::vector<int>         scores;

    getHighScores(names, scores);

    for (size_t i = 0; i < 3; i++) {
        std::cout << names[i] << std::endl << scores[i] << std::endl;
    }
}