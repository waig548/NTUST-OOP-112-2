#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

template<class T>
inline std::ostream& operator<<(std::ostream& o, const std::vector<T>& s) {
    for (auto it = s.begin(); it != s.end(); it++)
        o << *it << (it + 1 == s.end() ? "" : ", ");
    return o;
}

template<class T>
inline std::ostream& operator<<(std::ostream& o, const std::set<T>& s) {
    return o << std::vector<T>(s.begin(), s.end());
}

class Book {
    public:
    Book(const std::string& title, const std::string& author, int edition): title(title), author(author), editions{edition} {
    }

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    std::set<int> getEditions() const {
        return editions;
    }

    void addEdition(int edition) {
        editions.insert(edition);
    }

    void removeEditoon(int edition) {
        editions.erase(edition);
    }

    private:
    std::string   title;
    std::string   author;
    std::set<int> editions;
};

inline std::ostream& operator<<(std::ostream& o, const Book& book) {
    return o << "Title: " << book.getTitle() << "\tAuthor: " << book.getAuthor() << "\tEdition: " << book.getEditions();
}

inline int _findBook(const std::vector<Book>& books, const std::string& title, const std::string& author) {
    auto res = std::find_if(books.begin(), books.end(), [title, author](const Book& b) {
        return b.getTitle() == title && b.getAuthor() == author;
    });
    if (res == books.end())
        return -1;
    return res - books.begin();
}

void findBook(const std::vector<Book>& books, const std::vector<std::string>& args) {
    if (args.size() < 2)
        throw std::exception("Incomplete Command.");
    int idx = _findBook(books, args[0], args[1]);
    if (idx == -1)
        throw std::exception("Book doesn't exist.");
    std::cout << books[idx] << std::endl;
}

void findAuthor(const std::vector<Book>& books, const std::vector<std::string>& args) {
    if (args.size() < 1)
        throw std::exception("Incomplete Command.");
    std::vector<std::string> titles;
    for (auto b: books)
        if (b.getAuthor() == args[0])
            titles.push_back(b.getTitle());
    if (titles.empty())
        throw std::exception("No book found.");
    std::sort(titles.begin(), titles.end());
    std::cout << args[0] << "'s Books: " << titles << std::endl;
}

void findBooksWith(const std::vector<Book>& books, const std::vector<std::string>& args) {
    static const std::map<std::string, std::function<void(const std::vector<Book>&, const std::vector<std::string>&)>> delegates{
      std::make_pair(std::string("Book"), findBook), std::make_pair(std::string("Author"), findAuthor)};
    if (args.size() < 1 || !delegates.count(args[0]))
        throw std::exception("Unknown Command.");
    delegates.at(args[0])(books, std::vector<std::string>(args.begin() + 1, args.end()));
}

void insertBook(std::vector<Book>& books, const std::vector<std::string>& args) {
    if (args.size() < 3 || !std::regex_match(args[2], std::regex("^[0-9]+$")))
        throw std::exception("Incomplete Command.");
    int idx = _findBook(books, args[0], args[1]);
    int ed  = std::stoi(args[2]);
    if (idx == -1)
        books.push_back(Book(args[0], args[1], std::stoi(args[2])));
    else {
        auto& book     = books[idx];
        auto  editions = book.getEditions();
        if (editions.find(ed) != editions.end())
            throw std::exception("Datum already exist.");
        book.addEdition(ed);
    }
    std::cout << "Insert " << args[1] << "'s " << args[0] << ", Edition: " << args[2] << "." << std::endl;
}

void deleteBook(std::vector<Book>& books, const std::vector<std::string>& args) {
    if (args.size() < 2)
        throw std::exception("Incomplete Command.");
    int idx = _findBook(books, args[0], args[1]);
    if (idx == -1)
        throw std::exception("Book doesn't exist.");
    books.erase(books.begin() + idx);
    std::cout << "Delete " << args[1] << "'s " << args[0] << "." << std::endl;
}

void deleteEdition(std::vector<Book>& books, const std::vector<std::string>& args) {
    if (args.size() < 3 || !std::regex_match(args[2], std::regex("^[0-9]+$")))
        throw std::exception("Incomplete Command.");
    int idx = _findBook(books, args[0], args[1]);
    int ed  = std::stoi(args[2]);
    if (idx == -1 || !books[idx].getEditions().count(ed))
        throw std::exception("Datum doesn't exist.");
    books[idx].removeEditoon(ed);
    if (books[idx].getEditions().empty())
        books.erase(books.begin() + idx);
    std::cout << "Delete " << args[1] << "'s " << args[0] << ", Edition: " << args[2] << "." << std::endl;
}

void deleteBooksWith(std::vector<Book>& books, const std::vector<std::string>& args) {
    static const std::map<std::string, std::function<void(std::vector<Book>&, const std::vector<std::string>&)>> delegates{
      std::make_pair(std::string("Book"), deleteBook), std::make_pair(std::string("Edition"), deleteEdition)};
    if (args.size() < 1 || !delegates.count(args[0]))
        throw std::exception("Unknown Command.");
    delegates.at(args[0])(books, std::vector<std::string>(args.begin() + 1, args.end()));
}

void sort(std::vector<Book>& books, const std::vector<std::string>& args) {
    static const std::map<std::string, std::function<bool(const Book&, const Book&)>> cmpMethods{
      std::make_pair(
        "Title",
        [](const Book& a, const Book& b) -> bool {
            return a.getTitle() < b.getTitle() || (a.getTitle() == b.getTitle() && a.getAuthor() < b.getAuthor());
        }),
      std::make_pair("Author", [](const Book& a, const Book& b) -> bool {
          return a.getAuthor() < b.getAuthor() || (a.getAuthor() == b.getAuthor() && a.getTitle() < b.getTitle());
      })};
    if (args.size() < 2 || args[0] != "by" || !cmpMethods.count(args[1]))
        throw std::exception("Unknown Command.");
    std::sort(books.begin(), books.end(), cmpMethods.at(args[1]));
    for (auto b: books)
        std::cout << b << std::endl;
}

std::vector<std::string> processArguments(std::string arg) {
    std::vector<std::string> res;
    std::stringstream        ss(arg);
    std::string              tmp, residual;
    while (ss >> tmp) {
        if (tmp.front() == '"') {
            if (tmp.back() != '"') {
                std::getline(ss, residual, '"');
                tmp += residual;
            } else
                tmp = tmp.substr(0, tmp.length() - 1);
            tmp = tmp.substr(1);
        }
        res.push_back(tmp);
    }
    return res;
}

void processPrompt(std::vector<Book>& books, std::string cmd, std::string arg) {
    static const std::map<std::string, std::function<void(std::vector<Book>&, const std::vector<std::string>&)>> commands{
      std::make_pair(std::string("Insert"), insertBook), std::make_pair(std::string("Delete"), deleteBooksWith),
      std::make_pair(std::string("Find"), findBooksWith), std::make_pair(std::string("Sort"), sort)};
    auto args = processArguments(arg);
    if (!commands.count(cmd))
        throw std::exception("Unknown Command.");
    commands.at(cmd)(books, args);
}

int main() {
    std::vector<Book> books;

    std::string prompt, arg;
    while (std::cin >> prompt) {
        std::getline(std::cin, arg);
        try {
            processPrompt(books, prompt, arg);
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}