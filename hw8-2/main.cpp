#include <iostream>
#include "dynamic-array.hpp"
using std::cout;
using std::endl;
int test5() {
    string* arr0 = NULL;
    string arr1[3] = { "CSE]", "of ", "[Dept. " };
    DynamicArray<string> *da1 = new DynamicArray<string>(arr1, 3);
    auto da0 = new DynamicArray<string>(arr0, 0);

    da1->Print();
    auto da2 = da1->Subseq(2, 1);
    da0->Append(da2);
    da0->Print();
    auto da3 = da1->Subseq(1, 1);
    da0->Append(da3);
    da0->Print();
    auto da4 = da1->Subseq(0, 1);
    da0->Append(da4);
    da0->Print();

    delete da0;
    delete da1;
    delete da2;
    delete da3;
    delete da4;
    return 0;
}
int main(int argc, char ** argv) {
    test5();
    return 0;
}
