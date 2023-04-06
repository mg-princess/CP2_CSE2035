#include <iostream>
#include "my-string.hpp"
void test3() {
    MyString s1("Sogang");
    MyString s2("Univ.");
    s1.Insert(&s2,s1.GetLength()+1);
    s1.Insert(&s2,s1.GetLength()-1);
    s1.Print();
}
int main(int argc, char ** argv) {
    test3();
    return 0;
}
