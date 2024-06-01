// This file will be replaced by the Online Judge
// MUST NOT modify it.
#pragma once
#include "global.h"
#include "solution.h"
#include <iostream>
#include <string>

using namespace std;



namespace Authenticate {

inline void inputPassword() {
  do {
    cout << "Enter your password (at least 8 characters "
         << "and at least one non-letter)" << endl;
    cin >> ::passwordRef;
  } while (!::isValidPassword());
}

inline string getPassword() { return ::passwordRef; }

} // namespace Authenticate
