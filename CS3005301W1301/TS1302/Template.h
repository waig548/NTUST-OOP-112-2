
template<class T>
inline double absoluteValue(T a, T b) {
    return a < b ? b - a : a - b;
}