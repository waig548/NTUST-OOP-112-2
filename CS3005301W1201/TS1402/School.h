#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>

class School {
    public:
    School(std::string name, int studentAmount): School(name, studentAmount, studentAmount) {
    }

    School(const School& other): School(other.name, other.studentAmount, other.studentAmountNextYear) {
    }

    ~School() {
    }

    School& operator=(const School& other) {
        name                  = other.name;
        studentAmount         = other.studentAmount;
        studentAmountNextYear = other.studentAmountNextYear;
        return *this;
    }

    virtual inline bool admissions(float amount) {
        if (amount <= 0)
            return false;
        studentAmount += amount;
        return true;
    }
    virtual inline bool dropouts(float amount) {
        if (amount <= 0 || amount > studentAmount)
            return false;
        studentAmount -= amount;
        return true;
    }
    inline bool transfer(float amount, School& toSchool) {
        return dropouts(amount) && toSchool.admissions(amount);
    }

    friend std::ostream& operator<<(std::ostream& o, const School& school) {
        return school.toStream(o);
    }

    protected:
    School(std::string name, int studentAmount, int studentAmountNextYear):
        name(name), studentAmount(studentAmount), studentAmountNextYear(studentAmountNextYear) {
    }

    virtual inline std::ostream& toStream(std::ostream& o) const {
        return o << name << "\t" << studentAmount << "\t" << studentAmountNextYear;
    }

    std::string name;
    int         studentAmount;
    int         studentAmountNextYear;
};

class PrivateSchool: public School {
    public:
    PrivateSchool(std::string name, int studentAmount): PrivateSchool(name, studentAmount, studentAmount, 0) {
    }

    PrivateSchool(const PrivateSchool& other):
        PrivateSchool(other.name, other.studentAmount, other.studentAmountNextYear, other.dropoutCount) {
    }

    ~PrivateSchool() {
    }

    PrivateSchool& operator=(const PrivateSchool& other) {
        School::operator=(other);
        dropoutCount    = other.dropoutCount;
        return *this;
    }

    inline bool dropouts(float amount) override {
        if (School::dropouts(amount)) {
            if (dropoutCount)
                studentAmountNextYear -= 100;
            dropoutCount++;
            return true;
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& o, const PrivateSchool& school) {
        return school.toStream(o);
    }

    private:
    PrivateSchool(std::string name, int studentAmount, int studentAmountNextYear, int dropoutCount):
        School(name, studentAmount, studentAmountNextYear), dropoutCount(dropoutCount) {
    }

    inline std::ostream& toStream(std::ostream& o) const {
        return School::toStream(o);
    }

    int dropoutCount;
};

class PublicSchool: public School {
    public:
    PublicSchool(std::string name, int studentAmount): PublicSchool(name, studentAmount, studentAmount, 0.05) {
    }

    PublicSchool(const PublicSchool& other):
        PublicSchool(other.name, other.studentAmount, other.studentAmountNextYear, other.growing_rate) {
    }

    ~PublicSchool() {
    }

    PublicSchool& operator=(const PublicSchool& other) {
        School::operator=(other);
        growing_rate    = other.growing_rate;
        return *this;
    }

    inline bool dropouts(float amount) override {
        if (School::dropouts(amount)) {
            if (amount > 100)
                studentAmountNextYear -= growing_rate * studentAmountNextYear;
            return true;
        }
        return false;
    }

    inline void apply_growth() {
        studentAmountNextYear += growing_rate * studentAmountNextYear;
    }

    friend std::ostream& operator<<(std::ostream& o, const PublicSchool& school) {
        return school.toStream(o);
    }

    private:
    PublicSchool(std::string name, int studentAmount, int studentAmountNextYear, float growing_rate):
        School(name, studentAmount, studentAmountNextYear), growing_rate(growing_rate) {
    }

    inline std::ostream& toStream(std::ostream& o) const {
        return School::toStream(o);
    }

    float growing_rate;
};

#endif  // !SCHOOL_H
