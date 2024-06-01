#include "solution.h"
#include <deque>
#include <iostream>
#include <sstream>
#include <string>

struct Point {
  int x;
  int y;

  Point(int _x, int _y) : x(_x), y(_y) {}

  static std::string toString(Point p) {
    std::stringstream ss;
    ss << "(" << p.x << "," << p.y << ")";
    return ss.str();
  }
};

std::string toString(Point p) { return Point::toString(p); }
std::string toString(int data) { return std::to_string(data); }
std::string toString(std::string data) { return data; }

template <typename T> void dumpData(T container) {
  for (auto data : container) {
    std::cout << toString(data) << ' ';
  }
  std::cout << std::endl;
}

int main() {
  std::deque<Point> input = {{0, 5},   {16, 8}, {-5, 39},
                             {77, 13}, {0, -1}, {1, 0}};

  auto result1 = map(input, [](Point e) { return e.x; });
  dumpData(result1);

  auto result2 = count(result1, [](int e) { return e >= 0; });
  std::cout << result2 << std::endl;

  auto result3 = map<std::string>(input, Point::toString);
  dumpData(result3);

  auto result4 = pick(input, [](Point e) { return e.y < 5; });
  dumpData(result4);

  auto result5 = map(result3, [](std::string e) { return "P" + e; });
  dumpData(result5);

  int result6 = count(input, [](Point e) { return e.y >= 8; });
  std::cout << result6 << std::endl;

  return 0;
}