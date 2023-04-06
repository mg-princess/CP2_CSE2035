#ifndef NODE_CLASS
#define NODE_CLASS

#include <cstddef>

class Node {
public:
    // For simplicity, declare as public members.
    int data;
    Node *next;
    Node(int i): data(i) {
        next = NULL;
    }
};

#endif
