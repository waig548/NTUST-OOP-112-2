#include <algorithm>
#include <iostream>
#include <string>

bool isValid(const std::string& username) {
    return username.length() == 8 && std::find_if_not(username.begin(), username.end(), std::isalpha) == username.end();
}

namespace Authenticate {
std::string username;

void inputUserName() {
    do {
        std::cout << "Enter your username (8 letters only)" << std::endl;
        std::cin >> username;
    } while (!isValid(username));
}

std::string getUserName() {
    return username;
}
}  // namespace Authenticate
