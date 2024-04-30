#ifndef FILE_H
#define FILE_H

#include "Document.h"

class File: public Document {
    public:
    File(const std::string& text, const std::string& pathname): Document(text), pathname(pathname) {
    }

    File(const File& other): File(other.text, other.pathname) {
    }

    ~File() {
    }

    inline File& operator=(const File& other) {
        Document::operator=(other);
        pathname          = other.pathname;
        return *this;
    }

    inline std::string getPathname() const {
        return pathname;
    }

    inline void setPathname(const std::string& pathname) {
        this->pathname = pathname;
    }

    private:
    std::string pathname;
};

#endif  // !FILE_H
