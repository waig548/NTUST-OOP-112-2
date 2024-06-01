/**
 * @file case2.h
 * @brief test for Problem02(Josephus Permutation)
 * Replace the content of `main.cpp` with this file to test.
 * If your program is correct, output should same as `out001.txt`
 */
#include <iostream>

#include "solution.h"

int main() {
  std::cout << permutation(38, 7) << '\n'; // expect 10
  std::cout << permutation(25, 5) << '\n'; // expect 8
  std::cout << permutation(41, 3) << '\n'; // expect 31
  std::cout << permutation(99, 6) << '\n'; // expect 62
  std::cout << permutation(38, 4) << '\n'; // expect 38
  return 0;
}
