/**
 * @brief
 * Please complete the specified requirements described in the problem.
 */

#include <memory>

template<class U, template<class _Ty, class _Alloc = std::allocator<_Ty>> class Container, class T, class _Fn>
Container<U> map(Container<T> container, _Fn transform)
{
    Container<U> res;
    for (auto e : container)
        res.push_back(transform(e));
    return res;
}

template<template<class _Ty, class _Alloc = std::allocator<_Ty>> class Container, class T, class _Fn>
Container<T> map(Container<T> container, _Fn transform)
{
    Container<T> res;
    for (auto e : container)
        res.push_back(transform(e));
    return res;
}

template<class _Con, class _Fn>
_Con pick(_Con container, _Fn selector)
{
    _Con res;
    for (auto e : container)
        if (selector(e))
            res.push_back(e);
    return res;
}

template<class _Con, class _Fn>
unsigned int count(_Con container, _Fn predicate)
{
    int res = 0;
    for (auto e : container)
        if (predicate(e))
            res++;
    return res;
}