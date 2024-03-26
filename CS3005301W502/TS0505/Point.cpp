#include "Point.h"

Point::Point() {
    pos = new float[2]{0};
}

Point::Point(const Point& p) {
    pos[0] = p.pos[0];
    pos[1] = p.pos[1];
}

Point::~Point() {
    delete[] pos;
}

void Point::Set(float x, float y) {
    pos[0] = x;
    pos[1] = y;
}

void Point::Move(float dx, float dy) {
    pos[0] += dx;
    pos[1] += dy;
}

void Point::Rotate() {
    float nx = pos[1], ny = -pos[0];
    pos[0] = nx;
    pos[1] = ny;
}

void Point::Reflect() {
    Rotate();
    Rotate();
}

float Point::GetHorizontal() const {
    return pos[0] == 0 ? 0 : pos[0];
}

float Point::GetVertical() const {
    return pos[1] == 0 ? 0 : pos[1];
}