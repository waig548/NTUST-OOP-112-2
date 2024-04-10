#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
class Book {
public:
	class ISBN {
	private:
		ISBN(const std::string& raw) : raw(raw), valid(verify()) {}
	public:
		std::string raw;
		bool valid;

		~ISBN() {
		}
		bool verify() {
			return checkRaw(raw);
		}

		bool operator==(const ISBN& other) {
			return *this == other;
		}

		static ISBN tryMake(const std::string& raw) {
			if (checkRaw(raw))
				return ISBN(raw);
			return ISBN("");
		}

		static bool checkRaw(const std::string& raw) {
			static const  int coef[2] = { 1,3 };
			if (raw.size() != 13 || std::find_if_not(raw.begin(), raw.end(), std::isdigit) != raw.end())
				return false;
			int s = 0;
			for (int i = 0; i < 12; i++) {
				s += (raw[i] - '0') * coef[i % 2];
			}
			if (raw[12] - '0' != (10 - s % 10))
				return false;
			return true;
		}
	};

	int id;
	std::string name;
	ISBN isbn;
	Book &operator=(const Book& copy) {
		id = copy.id;
		name = copy.name;
		isbn = copy.isbn;
		return *this;
	}

	Book(int id, const std::string& name, const ISBN& isbn) : id(id), name(name), isbn(isbn) {}

	static Book tryMake(int id, const std::string& name, const std::string& rawISBN) {
		ISBN isbn = ISBN::tryMake(rawISBN);
		return Book(id, name, isbn);
	}


};


class Collect {
public:
	std::string name;
	std::vector<Book> books;

	Collect(const std::string& name) : Collect(name, {}) {}
	Collect &operator=(const Collect& copy) {
		name = copy.name;
		books = copy.books;
		return *this;
	}
	int findBookByID(int id) {
		auto res = std::find_if(books.begin(), books.end(), [id](Book book) {return book.id == id; });
		if (res == books.end())
			return -1;
		return res - books.begin();
	}

	int findBookByISBN(Book::ISBN isbn) {
		auto res = std::find_if(books.begin(), books.end(), [isbn](Book book) {return book.isbn.raw == isbn.raw; });
		if (res == books.end())
			return -1;
		return res - books.begin();
	}

	void removeBook(int index) {
		books.erase(books.begin() + index);
		//int id = books[index].id;
		//books.erase(std::remove_if(books.begin(), books.end(), [id](auto book) {return book.id == id; }), books.end());
	}
private:
	Collect(const std::string& name, const std::vector<Book>& books) : name(name), books(books) {}
};

int searchCollect(const std::vector<Collect>& collections, const std::string& name) {
	auto res = std::find_if(collections.begin(), collections.end(), [name](const Collect& collect) {
		return collect.name == name; });
	if (res == collections.end())
		return -1;
	return res - collections.begin();
}

bool bookIDExists(const std::vector<Collect>& collections, int bookID) {
	for (auto e : collections)
	{
		if (std::find_if(e.books.begin(), e.books.end(), [bookID](const Book& book) {return book.id == bookID; }) != e.books.end())
			return true;
	}
	return false;
}
bool ISBNExists(const std::vector<Collect>& collections, Book::ISBN isbn) {
	for (auto e : collections)
	{
		if (std::find_if(e.books.begin(), e.books.end(), [isbn](const Book& book) {return isbn.raw == book.isbn.raw; }) != e.books.end())
			return true;
	}
	return false;
}

int makeCollect(std::vector<Collect>& collections, const std::string& name) {
	if (searchCollect(collections, name) != -1)
		return 1;

	collections.push_back(Collect(name));
	std::cout << "Insert Collect: " << name << "." << std::endl;
	return 0;
}
int dropCollect(std::vector<Collect>& collections, const std::string& name) {
	int res = searchCollect(collections, name);
	if (res == -1)
		return 1;
	int N = collections[res].books.size();
	collections.erase(collections.begin() + res);
	std::cout << "Delete Collect: " << name << " with " << N << " books." << std::endl;
	return 0;
}
int insertBooks(std::vector<Collect>& collections, int collectIndex, std::vector<std::string>& bookData) {
	std::vector<Book> books;
	while (bookData.size() % 3)
		bookData.push_back("");
	for (int i = 0; i < bookData.size(); i += 3) {
		int bookID = -1;
		std::string bookName = bookData[i + 1];
		Book::ISBN isbn = Book::ISBN::tryMake(bookData[i + 2]);
		if (std::find_if_not(bookData[i].begin(), bookData[i].end(), std::isdigit) != bookData[i].end() || bookIDExists(collections, bookID = std::stoi(bookData[i])))
		{
			std::cout << "Invalid bookid." << std::endl;
			return 0;
		}
		if (!isbn.valid || ISBNExists(collections, isbn)) {
			std::cout << "Invalid isbn." << std::endl;
			return 0;
		}
		books.push_back(Book(bookID, bookName, isbn));
	}
	for (auto e : books)
		collections[collectIndex].books.push_back(e);
	std::cout << "Insert " << books.size() << " books into " << collections[collectIndex].name << "." << std::endl;
	return 0;
}
int deleteBooks(std::vector<Collect>& collections, const std::vector<int>& ids, const std::vector<Book::ISBN>& isbns) {
	int deleteCount = 0;
	for (int i = 0; i < collections.size(); i++) {
		Collect collect = collections[i];
		for (auto id : ids) {
			while (1) {
				int res = collections[i].findBookByID(id);
				if (res == -1)
					break;
				collections[i].removeBook(res);
				deleteCount++;
			}
		}for (auto isbn : isbns) {
			while (1) {
				int res = collections[i].findBookByISBN(isbn);
				if (res == -1)
					break;
				collections[i].removeBook(res);
				deleteCount++;
			}
		}
	}
	std::cout << deleteCount << " books delete." << std::endl;
	return 0;
}

int sortCollectBy(std::vector<Collect>& collections, int collectIndex, std::string method) {
	if (method == "bookId")
		std::sort(collections[collectIndex].books.begin(), collections[collectIndex].books.end(), [](const Book& a, const Book& b) {
		return a.id < b.id; });
	if (method == "ISBN")
		std::sort(collections[collectIndex].books.begin(), collections[collectIndex].books.end(), [](const Book& a, const Book& b) {
		return a.isbn.raw < b.isbn.raw; });
	for (auto e : collections[collectIndex].books)
		std::cout << "BookId: " << e.id << "\tBookName: " << e.name << "\tISBN: " << e.isbn.raw << std::endl;
	return 0;
}

int processPrompt(std::vector<Collect>& collections, const std::string& command, const std::string& rawArgs)
{
	int failed = 0;
	std::stringstream ss(rawArgs);
	std::string arg0;
	ss >> arg0;
	failed = failed || ss.fail();
	if (command == "Make") {
		if (makeCollect(collections, arg0)) {
			std::cout << "Collect already exist." << std::endl;
		}
	}
	else if (command == "Drop") {
		if (dropCollect(collections, arg0)) {
			std::cout << "Collect doesn't exist." << std::endl;
		}
	}
	else if (command == "Insert") {
		int res = searchCollect(collections, arg0);

		std::string rawData;
		ss >> rawData;
		if (failed = (failed || ss.fail()));
		else if (res == -1)
			std::cout << "Collect doesn't exist." << std::endl;
		else {

			std::stringstream rawStream(rawData);
			std::string tmp;
			std::vector<std::string> bookData;
			while (std::getline(rawStream, tmp, ',')) {
				bookData.push_back(tmp);
			}
			insertBooks(collections, res, bookData);

		}
	}
	else if (command == "Delete") {
		std::string arg1;
		ss >> arg1;

		std::stringstream rawStream(arg0);
		std::string tmp;
		std::vector<int> ids;
		while (std::getline(rawStream, tmp, ',')) {
			if (std::find_if_not(tmp.begin(), tmp.end(), std::isdigit) == tmp.end())
				ids.push_back(std::stoi(tmp));
		}
		rawStream = std::stringstream(arg0);
		std::vector<Book::ISBN> isbns;

		while (std::getline(rawStream, tmp, ',')) {
			Book::ISBN isbn = Book::ISBN::tryMake(tmp);
			if (isbn.valid)
				isbns.push_back(isbn);
		}
		deleteBooks(collections, ids, isbns);
	}
	else if (command == "Sort") {
		failed = failed || arg0 != "by";
		std::string arg1, arg2;
		ss >> arg1 >> arg2;
		failed = failed || ss.fail() || (arg1 != "bookId" && arg1 != "ISBN");
		if (!failed) {
			int collectIndex = searchCollect(collections, arg2);
			if (collectIndex == -1)
				std::cout << "Collect doesn't exist." << std::endl;
			else if (collections[collectIndex].books.empty())
				std::cout << "Collect is empty." << std::endl;
			else
				sortCollectBy(collections, collectIndex, arg1);
		}
	}
	else
		return 1;

	if (failed)
	{
		std::cout << "Incomplete Command." << std::endl;
		return 0;
	}
	return 0;
}


int main() {
	std::vector<Collect> collections;
	std::string command, rawArgs;
	while (std::cin >> command)
	{
		std::getline(std::cin, rawArgs);
		if (processPrompt(collections, command, rawArgs))
		{
			std::cout << "Unknown Command." << std::endl;
		}

	}


	return 0;
}