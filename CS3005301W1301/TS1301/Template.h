
template<class T>
inline void ItrBinarySearch(const T a[], int first, int last, T key, bool &found, int &location) {
    found    = false;
    location = -1;
    while (true) {
        int mid = (first + last) / 2;
        if (a[mid] == key) {
            found    = true;
            location = mid;
            return;
        }
        if (first == last)
            return;
        first = key < a[mid] ? first : mid + 1;
        last  = key > a[mid] ? last : mid;
    }
}

template<class T>
inline void _RecBinarySearch(const T a[], int first, int last, T key, bool &found, int &location) {
    int mid = (first + last) / 2;
    if (a[mid] == key) {
        found    = true;
        location = mid;
        return;
    }
    if (first == last)
        return;
    _RecBinarySearch(a, key < a[mid] ? first : mid + 1, key < a[mid] ? mid : last, key, found, location);
}

template<class T>
inline void RecBinarySearch(const T a[], int first, int last, T key, bool &found, int &location) {
    found    = false;
    location = -1;
    _RecBinarySearch(a, first, last, key, found, location);
}