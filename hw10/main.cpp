#include <iostream>
#include "list.hpp"

using std::cout;
using std::endl;

void test() {
    List lst;
    List lst2;
    lst2.Print();
    lst.InsertFront(1);
    lst.InsertFront(2);
    lst.InsertFront(3);
    lst.InsertBack(4);
    lst.InsertBack(5);
    lst.Print();
    // Print() above should print the following:
    // 3
    // 2
    // 1
    // 4
    // 5
    // ==========

    lst.RemoveFirst();
    lst.RemoveLast();
    lst.Print();
    // Print() above should print the following:
    // 2
    // 1
    // 4
    // ==========

    lst.InsertAt(1, 7);
    lst.Print();
    lst.InsertAt(6,2);
    lst.Print();
    // Print() above should print the following:
    // 2
    // 7
    // 1
    // 4
    // ==========

    lst.RemoveNth(3);
    lst.Print();
    // Print() above should print the following:
    // 2
    // 7
    // 4
    // ==========
    /*
    lst.Clear();
    lst.InsertAt(0, 10);
    lst.Print();
    lst.InsertAt(1, 9);
    lst.Print();
    lst.RemoveNth(1);
    lst.Print();
    */


/*
   lst.InsertFront(10);
   lst.Print();
   lst.RemoveFirst();
   cout << lst.IsEmpty() << endl;
   */
   //List lst;
}

int main() {
    test();
    return 0;
}
