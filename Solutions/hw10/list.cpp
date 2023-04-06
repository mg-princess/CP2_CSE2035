#include "node.hpp"
#include "list.hpp"

// TODO: Implement the following functions.

void List::InsertFront(int i) {
    Node *newNode = new Node(i);
    newNode->next = this->head;
    this->head = newNode;
}

void List::InsertBack(int i) {
    if (this->head == NULL) {
        this->head = new Node(i);
        return;
    }

    Node *n = this->head;
    while (n->next != NULL) {
        n = n->next;
    }
    n->next = new Node(i);
}

void List::InsertAt(int pos, int i) {
    if (pos < 0) { return; }
    if (pos == 0) { // Same to InsertFront().
        Node *newNode = new Node(i);
        newNode->next = this->head;
        this->head = newNode;
        return;
    }
    if (this->head == NULL) { return; } // 'pos' must have been 0.

    // At this point, pos >= 1 and the list is not empty.
    Node *n = this->head;
    for (int i = 0; i < pos - 1; i++) {
        n = n->next;
        if (n == NULL) { // Passed the last node (invalid 'pos')
            return;
        }
    }
    Node *newNode = new Node(i);
    newNode->next = n->next;
    n->next = newNode;
}

void List::RemoveFirst() {
    if (this->head == NULL) { return; }

    Node *trash = this->head;
    this->head = this->head->next;
    delete trash;
}

void List::RemoveLast() {
    if (this->head == NULL) { return; }

    // List with only one node must be handled separately, too.
    if (this->head->next == NULL) {
        delete this->head;
        this->head = NULL;
        return;
    }

    Node *n = this->head;
    while (n->next->next != NULL) {
        n = n->next;
    }
    delete n->next;
    n->next = NULL;
}

void List::RemoveNth(int idx) {
    if (this->head == NULL || idx < 0) { return; }
    if (idx == 0) { // Same to RemoveFirst().
        Node *trash = this->head;
        this->head = this->head->next;
        delete trash;
        return;
    }
    if (this->head->next == NULL) { return; } // 'idx' must have been 0.

    // At this point, idx >= 1 and the least has at least two nodes.
    Node *n = this->head;
    for (int i = 0; i < idx - 1; i++) {
        n = n->next;
        if (n->next == NULL) { // Passed the second to last node (invalid 'idx')
            return;
        }
    }
    Node *trash = n->next;
    n->next = n->next->next;
    delete trash;
}

bool List::IsEmpty() {
    return (this->head == NULL);
}

void List::Clear() {
    // Should deallocate all the nodes first.
    Node *n = this->head;
    while (n != NULL) {
        Node *trash = n;
        n = n->next;
        delete trash;
    }
    // Then, update the head node into NULL.
    this->head = NULL;
}
