#include <algorithm>
#include <iostream>
#include <string>

namespace {

std::string username;

bool isValid() {
    return username.length() == 8 && std::find_if_not(username.begin(), username.end(), std::isalpha) == username.end();
}
}  // namespace

namespace Authenticate {

void inputUserName() {
    do {
        std::cout << "Enter your username (8 letters only)" << std::endl;
        std::cin >> username;
    } while (!isValid());
}

std::string getUserName() {
    return username;
}
}  // namespace Authenticate
