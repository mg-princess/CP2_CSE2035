#include <iostream>
#include "string.hpp"

// TODO: Implement the following functions.

char& String::operator[](int idx) {
    if (idx < 0 || idx >= this->len) {
        std::cout << "Error\n";
        exit(0);
    }
    return arr[idx];
}

String& String::operator=(String &s) {
    delete[] this->arr;
    this->len = s.len;
    this->arr = new char[this->len];
    for (int i = 0; i < this->len; i++) {
        this->arr[i] = s.arr[i];
    }
    return *this;
}
