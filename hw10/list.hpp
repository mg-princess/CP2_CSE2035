#ifndef LIST_CLASS
#define LIST_CLASS

#include <iostream>
#include "node.hpp"

using std::cout;
using std::endl;

class List {
private:
    Node *head; // The first node
public:
    List() { head = NULL; }

    ~List() {
        Node *n = this->head;
        while (n != NULL) {
            Node *trash = n;
            n = n->next;
            delete trash;
        }
    }

    void Print() {
        if(head == NULL){
            cout << "NULL list\n";
            return;
        } 
        Node *n = this->head;

        while (n != NULL) {
            cout << n->data << endl;
            n = n->next;
        }
        cout << "==========\n";
    }

    // Insert a new node at the front. The new node must contain 'i' as data.
    void InsertFront(int i);
    // Insert a new node at the back. The new node must contain 'i' as data.
    void InsertBack(int i);
    // Insert a new node at the specified position 'pos'. The new node must
    // contain 'i' as data. Let's say there are N nodes in the list. Then, the
    // valid range of 'pos' is from 0 to N. When 'pos' is 0, the new node must
    // be inserted at the front of the list. When 'pos' is N, the new node must
    // be inserted at the back of the list. If 'pos' is invalid, return without
    // inserting anything.
    void InsertAt(int pos, int i);

    // Remove the first node. If the list is empty, do nothing and just return.
    void RemoveFirst();
    // Remove the last node. If the list is empty, do nothing and just return.
    void RemoveLast();
    // Remove the node at index 'idx'. Let's say there are N nodes in the list.
    // Then the valid range of 'idx' is from 0 to N-1. If the list is empty or
    // 'idx' is invalid, return without removing anything.
    void RemoveNth(int idx);

    // Returns whether this list is empty.
    bool IsEmpty();
    // Make this list into an empty list.
    void Clear();
};

#endif
