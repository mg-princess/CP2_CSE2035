#ifndef SIMPLE_SORT
#define SIMPLE_SORT

#include "max.hpp"
// TODO: Fill in this function.
template <typename T>
void simple_sort(T arr[], int n) {
    for(int i = 0; i<n-1; i++)  {
        find_max<T>((arr+i), n-i);
    }
}

#endif
