#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

class Document {
    public:
    Document(const std::string& text): text(text) {
    }

    Document(const Document& other): Document(other.text) {
    }

    ~Document() {
    }

    inline Document& operator=(const Document& other) {
        text = other.text;
        return *this;
    }

    inline std::string getText() const {
        return text;
    }

    inline void setText(const std::string& newText) {
        text = newText;
    }

    protected:
    std::string text;
};
#endif  // !DOCUMENT_H
