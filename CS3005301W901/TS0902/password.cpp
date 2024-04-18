#include <algorithm>
#include <iostream>
#include <string>

namespace {

std::string password;

bool isValid() {
    return password.length() >= 8 && std::find_if_not(password.begin(), password.end(), std::isalpha) != password.end();
}
}  // namespace

namespace Authenticate {

void inputPassword() {
    do {
        std::cout << "Enter your password (at least 8 characters "
                  << "and at least one non-letter)" << std::endl;
        std::cin >> password;
    } while (!isValid());
}

std::string getPassword() {
    return password;
}
}  // namespace Authenticate
