/**
 * @file case1.h
 * @brief test for Problem02(Josephus Permutation)
 * Replace the content of `main.cpp` with this file to test.
 * If your program is correct, output should same as `out001.txt`
 */
#include <iostream>

#include "solution.h"

int main() {
  std::cout << permutation(14, 2) << '\n';  // expect 13
  std::cout << permutation(8, 3) << '\n';   // expect 7
  std::cout << permutation(5, 2) << '\n';   // expect 3
  std::cout << permutation(22, 4) << '\n';  // expect 3
  std::cout << permutation(41, 3) << '\n';  // expect 31
  return 0;
}
