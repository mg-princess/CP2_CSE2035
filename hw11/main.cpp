#include <iostream>
#include "string.hpp"

using std::cout;
using std::endl;

void test1() {
    String s1("abcd");
    cout << s1[1] << endl; // Should print "b\n"
    s1[2] = 'z';
    s1.Print(); // Should print "abxd"
}

void test2() {
    String s1("abcd");
    cout << s1[-1] << endl; // Should print "Error\n" and exit.
}

void test3() {
    String s1("abcd");
    s1[4] = 'D'; // Should print "Error\n" and exit.
    s1.Print();
}

void test4() {
    String s1("abc");
    String s2("abcdefghijk");
    s2 = s1;
    s1[1] = 'B';
    s2.Print(); // Should print "abcd".
}

int main() {
    test1();
    //test2();
    //test3();
    test4();
    return 0;
}
