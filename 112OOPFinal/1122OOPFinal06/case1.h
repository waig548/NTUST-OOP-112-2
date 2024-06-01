#include "solution.h"
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::function<int(int)> functor = [](int e) { return e - 1; };

std::string mapFunction(int e) {
  std::stringstream ss;
  ss << "c(" << e << ")";
  return ss.str();
}

template <typename T> void dumpData(T container) {
  for (auto data : container) {
    std::cout << data << ' ';
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result1 = map(input, [](int element) { return element * element; });
  dumpData(result1);

  auto result2 = map(result1, functor);
  dumpData(result2);

  auto result3 = map<std::string>(result2, mapFunction);
  dumpData(result3);

  auto result4 = pick(result2, [](int element){
    return element % 2 == 0;
  });
  dumpData(result4);

  int result5 = count(result4, [](int element){
    return true;
  });
  std::cout << result5 << std::endl;


  int result6 = count(result4, [](int element){
    return false;
  });
  std::cout << result6 << std::endl;

  return 0;
}