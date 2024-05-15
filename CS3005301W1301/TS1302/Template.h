
template<class T>
inline double absoluteValue(T a, T b) {
    T diff = a - b;
    return diff < 0 ? -diff : diff;
}