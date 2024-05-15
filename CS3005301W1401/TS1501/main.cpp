#include <fstream>
#include <iostream>
#include <set>
#include <string>

int main() {
    std::ifstream         ifs("name.txt");
    std::set<std::string> names;

    std::string tmp;
    while (std::getline(ifs, tmp))
        names.insert(tmp);

    for (auto e: names)
        std::cout << e << std::endl;
}