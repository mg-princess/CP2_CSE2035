// This is called a 'header guard'
#ifndef MY_STRING
#define MY_STRING

#include <cstdio>
#include <string.h>
#include <stdlib.h>

class MyString {
private:
    char *arr;
    size_t length;
public:
    // Let's promise to implement our string this way. No null character ('\0')
    // is required, because we have the 'length' field.
    MyString(const char *s) {
        length = strlen(s);
        if (length == 0) {
            arr = NULL;
        }
        else {
            arr = (char*) malloc(length);
            memcpy(arr, s, length);
        }
    }
    
    void Print() {
        for (int i = 0; i < length; i++) {
            putchar(arr[i]);
        }
        putchar('\n');
    }

    // Destructor.
    ~MyString();
    // Get the length of this string.
    size_t GetLength();
    // Make this string into an empty string.
    void Clear();
    // Insert 's' at the position 'idx' of this string. idx=0 means the start.
    void Insert(MyString *s, int idx);
    // Starting from the position 'idx', remove 'n' characters.
    void Remove(int idx, int n);
};

#endif
