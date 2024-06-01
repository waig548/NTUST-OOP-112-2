// Will Replace by OJ, DO NOT EDIT!
#ifndef XMLTOKENIZER_H
#define XMLTOKENIZER_H
#include <regex>
#include <string>
class XMLTokenizer {
    public:
    enum class TokenType {
        INVALID,
        LT,      // <
        LT_END,  // </
        GT,      // >
        EQUAL,   // =
        STR,     // ABC123, "ABC123"
    };
    class Token {
        public:
        TokenType Type() {
            return this->type;
        }
        virtual ~Token() = default;
        template<class T>
        T* Cast() {
            return dynamic_cast<T*>(this);
        }
        virtual std::string ToString() {
            auto ty = this->type;
            switch (ty) {
                case XMLTokenizer::TokenType::LT:
                    return "<";
                case XMLTokenizer::TokenType::LT_END:
                    return "</";
                case XMLTokenizer::TokenType::GT:
                    return ">";
                case XMLTokenizer::TokenType::EQUAL:
                    return "=";
                case XMLTokenizer::TokenType::STR:
                    return "STR";
                case XMLTokenizer::TokenType::INVALID:
                default:
                    return "INVALID";
            }
        }
        Token(TokenType _type):
            type(_type) {
        }

        private:
        TokenType type;
    };
    class StringToken: public Token {
        public:
        StringToken(const std::string& _val):
            Token(TokenType::STR), val(_val) {
        }
        virtual ~StringToken() = default;

        virtual std::string ToString() override {
            return "STR(" + this->val + ")";
        }

        std::string Value() {
            return this->val;
        }

        private:
        std::string val;
    };

    static std::vector<Token*> Tokenize(const std::string& xml) {
        std::vector<Token*> result;

        for (size_t i = 0; i < xml.size(); i++) {
            // remove leading whitespace
            if (std::isspace(xml[i])) {
                continue;
            }
            if (xml[i] == '<') {
                if (xml[i + 1] == '/') {
                    result.push_back(new Token(TokenType::LT_END));
                } else {
                    result.push_back(new Token(TokenType::LT));
                }

                auto        gtPos  = xml.find('>', i);
                std::string tagStr = xml.substr(i + 1, gtPos - i - 1);

                const static std::regex nameRegex("([a-zA-Z0-9-]+)");
                const static std::regex attrRegex("([a-zA-Z0-9]+) *= *(\"[^\"]+\")");

                std::smatch match;

                std::regex_search(tagStr, match, nameRegex);
                result.push_back(new StringToken(match[1]));
                tagStr = match.suffix().str();

                while (std::regex_search(tagStr, match, attrRegex)) {
                    result.push_back(new StringToken(match[1]));
                    result.push_back(new Token(TokenType::EQUAL));
                    result.push_back(new StringToken(match[2]));

                    tagStr = match.suffix().str();
                }

                result.push_back(new Token(TokenType::GT));
                i = gtPos;
                continue;
            }
            auto gtPos     = xml.find('<', i);
            auto strEndPos = gtPos;

            std::string text = xml.substr(i, strEndPos - i);

            // trim trailing whitespace
            while (text.size() > 0 && std::isspace(text.back())) {
                text.pop_back();
            }
            if (text.size() == 0) {
                continue;
            }

            result.push_back(new StringToken(text));

            i = strEndPos - 1;
        }
        return result;
    }
};
#endif  // XMLTOKENIZER_H
