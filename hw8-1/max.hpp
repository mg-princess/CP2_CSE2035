#ifndef FIND_MAX
#define FIND_MAX

// TODO: Fill in this function.
template <typename T>
void find_max(T arr[], int n) {
    if(n <= 0) return;
    T max = arr[0];
    int idx = 0;
    for(int i = 1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
            idx = i;
        }
    }
    T tmp = max;
    arr[idx] = arr[0];
    arr[0] = tmp;
}

#endif
