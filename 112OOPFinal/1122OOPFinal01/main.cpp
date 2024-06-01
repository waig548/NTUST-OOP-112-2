// This file will be replaced by the Online Judge
// MUST NOT modify it.
#include <iostream>

#include "username.h"
#include "password.h"

using namespace Authenticate;
using namespace std;

int main() {
  inputUserName();
  inputPassword();
  cout << "Your username is " << getUserName()
       << " and your password is: " << getPassword() << endl;
  return 0;
}