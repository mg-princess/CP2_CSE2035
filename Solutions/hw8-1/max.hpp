#ifndef FIND_MAX
#define FIND_MAX

template <typename T>
void find_max(T arr[], int n) {
    if (n <= 1) {
        return;
    }

    T max_elem = arr[0];
    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (max_elem < arr[i]) {
            max_elem = arr[i];
            max_idx = i;
        }
    }

    T tmp = arr[0];
    arr[0] = arr[max_idx];
    arr[max_idx] = tmp;
}

#endif
