#include "string.hpp"

// TODO: Implement the following functions.

char& String::operator[](int idx) {
    for(int i = 0; i<len; i++) {
        if(i == idx) 
            return *(arr+i);
    }
    printf("Error\n");
    exit(1);
}

String& String::operator=(String &s) {
    len = s.len;
    char* trash = arr;
    arr = new char(len);
    delete [] trash;
    strncpy(arr, s.arr, len);
    return *this;
}