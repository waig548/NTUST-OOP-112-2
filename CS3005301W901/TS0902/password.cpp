#include <algorithm>
#include <iostream>
#include <string>

bool isValid(std::string& password) {
    return password.length() >= 8 && std::find_if_not(password.begin(), password.end(), std::isalpha) != password.end();
}

namespace Authenticate {
std::string password;

void inputPassword() {
    do {
        std::cout << "Enter your password (at least 8 characters "
                  << "and at least one non-letter)" << std::endl;
        std::cin >> password;
    } while (!isValid(password));
}

std::string getPassword() {
    return password;
}
}  // namespace Authenticate
