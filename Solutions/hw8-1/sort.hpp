#ifndef SIMPLE_SORT
#define SIMPLE_SORT

#include "max.hpp"

template <typename T>
void simple_sort(T arr[], int n) {
    for (int i = 0; i < n; i ++) {
        find_max<T>(arr + i, n - i);
    }
}

#endif
