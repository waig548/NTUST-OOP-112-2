#include "Point.h"

void Point::Set(int vertical, int horizontal) {
    this->vertical   = vertical;
    this->horizontal = horizontal;
}

void Point::Move(int x, int y) {
    this->vertical += x;
    this->horizontal += y;
}
void Point::Rotate() {
    int newX   = horizontal;
    int newY   = -vertical;
    vertical   = newX;
    horizontal = newY;
}
