#include <iostream>
#include "graphics.hpp"

using std::cout;
using std::endl;

// I will fix this function to test your class implementation
void test() {
    Rectangle r(1, 2, 5, 4);
    r.IncreaseWidth(1);
    r.Fix();
    r.IncreaseHeight(2);
    r.Unfix();
    r.IncreaseHeight(1);
    r.Print();
    cout << "Size = " << r.Size() << endl;
}

int main() {
    test();
    return 0;
}
