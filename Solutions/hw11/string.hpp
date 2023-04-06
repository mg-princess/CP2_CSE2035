#ifndef MY_STRING
#define MY_STRING

#include <iostream>
#include <cstring>

class String {
private:
    int len;
    char *arr;
public:
    String(const char *s) {
        len = strlen(s);
        arr = new char[len];
        for (int i = 0; i < len; i++) {
            arr[i] = s[i];
        }
    }

    ~String() { delete[] arr; }

    void Print() {
        for (int i = 0; i < len; i++) {
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }

    // Index operator for the object. We must be able to read or write idx-th
    // character by "obj[idx]". If 'idx' is invalid and tries to access out of
    // boundary, print "Error\n" and stop the execution by calling exit(0).
    char& operator[](int idx);
    // Assign operator for the object. We must make a fresh copy of 's' that is
    // managed independently from 's'. In other word, after we copy from 's',
    // any update on 's' should not affect the content of this object. Also,
    // make sure that no segmentation fault or memory leak occurs.
    String& operator=(String &s);
};

#endif
