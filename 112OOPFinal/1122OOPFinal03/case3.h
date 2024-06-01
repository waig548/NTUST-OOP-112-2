/**
 * @file case3.h
 * @brief test for Problem03(Design Polynominal Class)
 * Replace the content of `main.cpp` with this file to test.
 * If your program is correct, output should same as `out001.txt`
 */
#pragma once
#include <iostream>
#include <string>

#include "solution.h"

using namespace std;

void print(string name, Polynomial poly) {
    cout << "Polynomial " << name << endl;
    for (int i = 0; i < poly.mySize(); i++)
        cout << "term with degree " << i << " has coefficient " << poly[i] << endl;
}

int main() {
    double one[] = { 1 };
    double quad[] = { 3, 2, 1 };
    double cubic[] = { 1, 2, 0, 3 };
    Polynomial r;
    Polynomial q(quad, 3);   // q is 3 + 2*x + x*x
    Polynomial c(cubic, 4);  // c is 1 + 2*x + 0*x*x + 3*x*x*x
    Polynomial p = q;        // test copy constructor
    r = c;                   // test operator=
    print("p", p);
    print("r", r);

    q[1] = 5;
    q[0] = 6;
    print("p", p);

    c[1] = 5;
    c[0] = 6;
    print("r", r);
    print("c", c);

    cout << "value of q(2) is " << evaluate(q, 2) << endl;
    cout << "value of p(2) is " << evaluate(p, 2) << endl;
    cout << "value of r(-2) is " << evaluate(r, -2) << endl;
    cout << "value of c(-2) is " << evaluate(c, -2) << endl;

    double x1 = 23, x2 = 8;
    p = r * c;
    cout << "size of r*c is " << p.mySize() << endl;
    print("p", p);
    cout << "Polynomial p(=r*c) " << endl;
    cout << "value of (r*c)(-2) is " << evaluate(p, -2) << endl;

    p = r * x1;
    cout << "size of r*" << x1 << " is " << p.mySize() << endl;
    print("p", p);
    cout << "Polynomial p(=r*" << x1 << ") " << endl;
    cout << "value of (r*" << x1 << ")(-2) is " << evaluate(p, -2) << endl;

    p = x2 * c;
    cout << "size of " << x2 << "*c is " << p.mySize() << endl;
    print("p", p);
    cout << "Polynomial p(=" << x2 << "*c) " << endl;
    cout << "value of (" << x2 << "*c)(-2) is " << evaluate(p, -2) << endl;

    p = r + c;
    cout << "size of r+c is " << p.mySize() << endl;
    print("p", p);
    cout << "Polynomial p(=r+c) " << endl;
    cout << "value of (r+c)(-2) is " << evaluate(p, -2) << endl;

    p = r + x1;
    cout << "size of r+" << x1 << " is " << p.mySize() << endl;
    print("p", p);
    cout << "Polynomial p(=r+" << x1 << ") " << endl;
    cout << "value of (r+" << x1 << ")(-2) is " << evaluate(p, -2) << endl;

    p = x2 + c;
    cout << "size of " << x2 << "+c is " << p.mySize() << endl;
    print("p", p);
    cout << "Polynomial p(=" << x2 << "+c) " << endl;
    cout << "value of (" << x2 << "+c)(-2) is " << evaluate(p, -2) << endl;

    p = r - c;
    cout << "size of r-c is " << p.mySize() << endl;
    print("p", p);
    cout << "Polynomial p(=r-c) " << endl;
    cout << "value of (r-c)(-2) is " << evaluate(p, -2) << endl;

    p = r - x1;
    cout << "size of r-" << x1 << " is " << p.mySize() << endl;
    print("p", p);
    cout << "Polynomial p(=r-" << x1 << ") " << endl;
    cout << "value of (r-" << x1 << ")(-2) is " << evaluate(p, -2) << endl;

    p = x2 - c;
    cout << "size of " << x2 << "-c is " << p.mySize() << endl;
    print("p", p);
    cout << "Polynomial p(=" << x2 << "-c) " << endl;
    cout << "value of (" << x2 << "-c)(-2) is " << evaluate(p, -2) << endl;

    p = Polynomial() * c;
    cout << "size of " << 0 << "*c is " << p.mySize() << endl;
    print("p", p);
    cout << "Polynomial p(=" << 0 << "*c) " << endl;
    cout << "value of (" << 0 << "*c)(-2) is " << evaluate(p, -2) << endl;

    return 0;
}
