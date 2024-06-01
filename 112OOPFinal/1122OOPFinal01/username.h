// This file will be replaced by the Online Judge
// MUST NOT modify it.
#pragma once
#include "global.h"
#include "solution.h"
#include <iostream>
#include <string>

using namespace std;



namespace Authenticate {

inline void inputUserName() {
  do {
    cout << "Enter your username (8 letters only)" << endl;
    cin >> ::usernameRef;
  } while (!::isValidUsername());
}

inline string getUserName() { return ::usernameRef; }

} // namespace Authenticate