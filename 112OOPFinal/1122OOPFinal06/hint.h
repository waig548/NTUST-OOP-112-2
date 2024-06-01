/* DONT Compile or Include this file!!! */

/**
 * @brief Hint1:
 * In the standard library, the declarations of vector, list, and deque are as
 * follows:
 */

#include <memory>
template <class T, class Allocator = std::allocator<T> >
class vector;

template <class T, class Allocator = std::allocator<T> >
class deque;

template <class T, class Allocator = std::allocator<T> >
class list;

/**
 * @brief Hint2:
 * To match a template template argument A to a template template parameter P, P
 * must be at least as specialized as A (see below). If P's parameter list
 * includes a parameter pack, zero or more template parameters (or parameter
 * packs) from A's template parameter list are matched by it.(since C++11)
 /// quote from cppreference
 */

template <typename T>  // primary template
class A {
  int x;
};

template <typename T>  // partial specialization
class A<T*> {
  long x;
};

// class template with a template template parameter V
template <template <typename> class V>
class C {
  V<int> y;   // uses the primary template
  V<int*> z;  // uses the partial specialization
};

C<A> c;  // c.y.x has type int, c.z.x has type long

/**
 * @brief Hint3
 * If you declare a template, it remains a template without an argument and
 * cannot be deduced by the compiler.
 * However, once you add an argument, it
 * becomes a type that can be deduced by the compiler.
 */

template <typename T>
struct Wrap {
  T data;
};

// decltype(Wrap) wrap1= { .data = 0.0f};             // Error, `Wrap` is unable to be deduce
decltype(Wrap<int>()) deducedWrap = { .data = 100 };  // OK, `Wrap<int>` is able to be deduce.
