#ifndef UNIVMEM_CLASSS
#define UNIVMEM_CLASSS

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class UnivMem {
private:
    int id;
    string name;
public:
    UnivMem(int _id, const char* _name): id(_id) {
        name = _name; // Automatically converted and stored as std::string.
    }

    int GetID() { return id; }

    const char* GetName() { return name.c_str(); }

    void Print() {
        cout << name << "(" << id << ")" << endl;
    }
};

#endif
