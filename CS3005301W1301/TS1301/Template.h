
template<class T>
inline void ItrBinarySearch(const T a[], int first, int last, T key, bool &found, int &location) {
    for (int i = first; i <= last; i++)
        if (a[i] == key) {
            found    = true;
            location = i;
            return;
        }
    found    = false;
    location = -1;
}

template<class T>
inline void _RecBinarySearch(const T a[], int first, int last, T key, bool &found, int &location, bool initialPass) {
    if (initialPass) {
        found = false;
        location = -1;
        initialPass = false;
    }
    int mid  = (first + last) / 2;
    if (a[mid] == key) {
        found    = true;
        location = mid;
        return;
    }
    if (first == last)
        return;
    _RecBinarySearch(a, first, mid, key, found, location, initialPass);
    _RecBinarySearch(a, mid + 1, last, key, found, location, initialPass);
}

template<class T>
inline void RecBinarySearch(const T a[], int first, int last, T key, bool &found, int &location) {
    _RecBinarySearch(a, first, last, key, found, location, true);
}