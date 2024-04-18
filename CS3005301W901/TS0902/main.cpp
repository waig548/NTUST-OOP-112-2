#include <iostream>
#include <string>

#include "Authenticate.h"

int main() {
    Authenticate::inputUserName();
    Authenticate::inputPassword();
    std::cout << "Your username is " << Authenticate::getUserName() << " and your password is: " << Authenticate::getPassword()
              << std::endl;
    return 0;
}
