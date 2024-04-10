#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "Diary.h"

class Creature {
    private:
    class Part {
        public:
        Part(Creature* base, std::string name): Part(base, name, 0) {
        }

        Part(Creature* base, std::string name, int value): name(name), value(value) {
            this->base = base;
        }

        Part& operator=(const int newValue) {
            std::string action;
            if (!value && newValue)
                action = "appeared";
            else if (value < newValue)
                action = "increased";
            else if (value > newValue)
                action = "decreased";
            if (!action.empty())
                base->log(name, action, value, newValue);
            value = newValue;
            return *this;
        }

        inline std::string getName() const {
            return name;
        }

        inline int getValue() const {
            return value;
        }

        inline Part& operator+=(const int rhs) {
            return this->operator=(value + rhs);
        }

        inline Part& operator-=(const int rhs) {
            return this->operator=(value - rhs);
        }

        private:
        Creature*   base;
        std::string name;
        int         value;
    };
    friend Part;

    public:
    Creature(const std::string& name): name(name), dob(Diary::getCurrentDay()) {
    }

    Creature(const std::string& name, const Creature& base): Creature(name) {
        for (auto p: base.parts) {
            parts.try_emplace(p.first, Part(this, p.second.getName(), p.second.getValue()));
        }
    }

    ~Creature() {
    }

    Part operator[](const std::string& partName) const {
        return parts.at(partName);
    }

    Part& operator[](const std::string& partName) {
        parts.try_emplace(partName, Part(this, partName));
        return parts.at(partName);
    }

    void PrintStatus() {
        std::cout << name << "'s status:" << std::endl;
        for (auto e: parts) {
            if (e.second.getValue())
                std::cout << e.second.getName() << " * " << e.second.getValue() << std::endl;
        }
        std::cout << std::endl;
    }

    void PrintLog() {
        std::cout << name << "'s log:" << std::endl;
        auto it = std::find(Diary::recordDays.begin(), Diary::recordDays.end(), dob);
        while (it != Diary::recordDays.end()) {
            std::cout << "Day " << it->date << std::endl;
            if (logs.find(*it) != logs.end())
                for (auto entry: logs.at(*it))
                    std::cout << entry << std::endl;
            it++;
        }
        std::cout << std::endl;
    }

    private:
    std::string                                     name;
    std::map<std::string, Part>                     parts;
    std::map<Diary::Date, std::vector<std::string>> logs;
    Diary::Date                                     dob;

    void log(const std::string part, const std::string action, const int original, const int changed) {
        logs.try_emplace(Diary::getCurrentDay(), std::vector<std::string>());
        std::stringstream ss;
        ss << name << "'s " << part << " " << action << " (" << std::to_string(original) << " -> " << std::to_string(changed) << ").";
        logs.at(Diary::getCurrentDay()).push_back(ss.str());
    }
};
#endif  // !CREATURE_H
