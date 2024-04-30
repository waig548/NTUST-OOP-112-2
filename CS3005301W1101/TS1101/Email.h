#ifndef EMAIL_H
#define EMAIL_H

#include "Document.h"

class Email: public Document {
    public:
    Email(const std::string& text, const std::string& sender, const std::string& recipient, const std::string& title):
        Document(text), sender(sender), recipient(recipient), title(title) {
    }

    Email(const Email& other): Email(other.text, other.sender, other.recipient, other.title) {
    }

    ~Email() {
    }

    inline Email& operator=(const Email& other) {
        Document::operator=(other);
        sender            = other.sender;
        recipient         = other.recipient;
        title             = other.title;
        return *this;
    }

    inline std::string getSender() const {
        return sender;
    }

    inline std::string getRecipient() const {
        return recipient;
    }

    inline std::string getTitle() const {
        return title;
    }

    inline void setSender(const std::string& sender) {
        this->sender = sender;
    }

    inline void setRecipient(const std::string& recipient) {
        this->recipient = recipient;
    }

    inline void setTitle(const std::string& title) {
        this->title = title;
    }

    private:
    std::string sender;
    std::string recipient;
    std::string title;
};

#endif  // !EMAIL_H
