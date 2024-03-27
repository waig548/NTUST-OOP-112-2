#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Form {
    private:
    std::string              refWord;
    std::map<char, int>      refLetters;
    std::string              fileName;
    std::vector<std::string> validWords;

    public:
    void SetInputWord(std::string inputWord);  // set input
    void ProcessInputWord();                   // process input
    void SetFileName(std::string fileName);    // set file name
    void Load_CompareWord();                   // read-in data and compare
    void PrintFoundWords();                    // print answers
};

void Form::SetInputWord(std::string inputWord) {
    refWord = inputWord;
}

void Form::ProcessInputWord() {
    std::transform(refWord.begin(), refWord.end(), refWord.begin(), std::tolower);
    for (auto e: refWord) {
        refLetters.try_emplace(e, 0);
        refLetters[e]++;
    }
}

void Form::SetFileName(std::string fileName) {
    this->fileName = fileName;
}

void Form::Load_CompareWord() {
    std::ifstream ifs(fileName);
    std::string   word;
    while (ifs >> word) {
        std::string tmp(word);
        std::transform(tmp.begin(), tmp.end(), tmp.begin(), std::tolower);
        std::map<char, int> letters;
        bool                valid = true;
        for (auto e: tmp) {
            letters.try_emplace(e, 0);
            letters[e]++;
            if (refLetters.find(e) == refLetters.end() || letters[e] > refLetters[e]) {
                valid = false;
                break;
            }
        }
        if (valid)
            validWords.push_back(word);
    }
}

void Form::PrintFoundWords() {
    for (auto e: validWords)
        std::cout << e << std::endl;
}