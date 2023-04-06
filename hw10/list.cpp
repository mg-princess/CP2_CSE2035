#include "node.hpp"
#include "list.hpp"

// TODO: Implement the following functions.

void List::InsertFront(int i) {
    Node* new_node = new Node(i);
    new_node->next = head;
    head = new_node;
}

void List::InsertBack(int i) {
    if(head == NULL) {
        head = new Node(i); 
        return;
    }
    Node* rec_node = head;
    while(rec_node->next != NULL) 
        rec_node = rec_node->next;
    rec_node->next = new Node(i);
}

void List::InsertAt(int pos, int i) {
    Node* rec_node = head;
    if(pos < 0) 
        return;
    else if(pos == 0) {
        InsertFront(i);
        return;
    }
    for(int idx = 0; idx<pos-1; idx++) {
        if(rec_node->next->next == NULL) {
            if(idx == pos-2)
                InsertBack(i);
            return;
        }
        rec_node = rec_node->next;
    }
    Node* new_node = new Node(i);
    new_node->next = rec_node->next;
    rec_node->next = new_node;
}

void List::RemoveFirst() {
    if(head == NULL) {
        return;
    } 
    Node* n = head;
    head = head->next;
    delete n;
}

void List::RemoveLast() {
    Node* rec_node = head;
    if(rec_node == NULL) 
        return;
    else if(rec_node->next == NULL) {
        RemoveFirst();
        return;
    }
    while(rec_node->next->next != NULL) 
        rec_node = rec_node->next;
    delete rec_node->next;
    rec_node->next = NULL;
}

void List::RemoveNth(int idx) {
    Node* rec_node = head;
    Node* rec_back_node = head;
    if(idx < 0) 
        return;
    else if(idx == 0) {
        RemoveFirst();
        return;
    }
    for(int i = 0; i<idx; i++) {
        if(rec_node->next == NULL) {
            if(i == idx)
                RemoveLast();
            return;
        }
        rec_back_node = rec_node;
        rec_node = rec_node->next;
    }
    rec_back_node->next = rec_node->next;
    delete rec_node;
}

bool List::IsEmpty() {
    return (head == NULL);
}

void List::Clear() {
    while(!IsEmpty()) {
        RemoveLast();
    }
}
