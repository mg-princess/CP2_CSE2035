#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <iostream>

using namespace std;

template <typename T>
class DynamicArray {
private:
    T *ptr;
    int length;
public:
    // Constructor. Note that it does not matter even if 'arr' is empty and
    // 'len' is 0. Assume that input 'len' is always non-negative. Don't change
    // this function.
    DynamicArray(T arr[], int len) {
        ptr = new T[len];
        length = len;
        for (int i = 0; i < len; i++) {
            ptr[i] = arr[i];
        }
    }

    // Print the elements of the array one by one. Don't change this function.
    void Print() {
        for (int i = 0; i < length; i++) {
            cout << ptr[i];
            if (i == length - 1) {
                cout << endl;
            } else {
                cout << ", ";
            }
        }
    }

    // Destructor.
    ~DynamicArray();
    // Append array 'da' at the end of this array.
    void Append(DynamicArray *da);
    // Return a fresh subsequence that starts from 'idx' and includes up to 'n'
    // consecutive elements in this array. If 'idx' < 0 or 'idx' >= 'length',
    // return an empty DynamicArray. If the subsequence reaches the end before
    // including 'n' elements, return a subsequence that stops there.
    DynamicArray* Subseq(int idx, int n);
};

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] ptr;
}

template <typename T>
void DynamicArray<T>::Append(DynamicArray *da) {
    T* new_ptr = new T[this->length + da->length];
    for (int i = 0; i < this->length; i++) {
        new_ptr[i] = this->ptr[i];
    }
    for (int i = 0; i < da->length; i++) {
        new_ptr[this->length + i] = da->ptr[i];
    }
    delete[] ptr;
    ptr = new_ptr;
    this->length += da->length;
}


template <typename T>
DynamicArray<T>* DynamicArray<T>::Subseq(int idx, int n) {
    if (idx < 0 || idx >= this->length) {
        return new DynamicArray(NULL, 0);
    }
    int adjusted_n = n;
    if (idx + n > this->length) {
        adjusted_n = this->length - idx;
    }
    return new DynamicArray(this->ptr + idx, adjusted_n);
}

#endif
