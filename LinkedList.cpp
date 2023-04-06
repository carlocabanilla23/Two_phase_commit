//
// Created by johnc on 4/5/2023.
//

#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() : _head(nullptr) {}
LinkedList::LinkedList(LinkedList* list) : _head(list->_head) {}

LinkedList::LinkedList(Node* node) : _head(node) {}
LinkedList::LinkedList(int val)  {
    Node* tmp = new Node(val);
    _head = tmp;
}
bool LinkedList::RollAdd(int val) {
    Node* tmp = new Node(val);

    if (_head == nullptr) {
        _head = tmp;
    }

    Node* tmpHead = _head;

    while(tmpHead->_next != nullptr) {
        tmpHead = tmpHead->_next;
    }

    tmpHead->_next = tmp;
    return true;
}
bool LinkedList::Add(int val) {
    _cacheAdd.push_back(val);
    Node* tmp = new Node(val);

    if (_head == nullptr) {
        _head = tmp;
    }

    Node* tmpHead = _head;

    while(tmpHead->_next != nullptr) {
        tmpHead = tmpHead->_next;
    }

    tmpHead->_next = tmp;
    return true;
}

LinkedList * LinkedList::Clone() {
    return new LinkedList(this);
}
bool LinkedList::Delete(int key) {
    _cacheDel.push_back(key);
    Node* tmpHead = _head;

    while (tmpHead->_next->_val != key) {
        if (tmpHead->_next->_next == nullptr) {
            return false;
        }
        tmpHead = tmpHead->_next;
    }

    Node* tmp = tmpHead->_next;
    tmpHead->_next = tmpHead->_next->_next;
    delete tmp;
    return true;
}
bool LinkedList::RollDelete(int key) {
    Node* tmpHead = _head;

    while (tmpHead->_next->_val != key) {
        if (tmpHead->_next->_next == nullptr) {
            return false;
        }
        tmpHead = tmpHead->_next;
    }

    Node* tmp = tmpHead->_next;
    tmpHead->_next = tmpHead->_next->_next;
    delete tmp;
    return true;
}
void LinkedList::Print() const {
    Node* tmp = _head;
    while (tmp != nullptr) {
        cout << tmp->ToString() << " ";
        tmp = tmp->_next;
    }
    cout << endl;
}

bool LinkedList::RollBack () {
//    cout << _cacheDel.size();
    for (int i = 0 ; i < _cacheDel.size() ; i++ ) {
        RollAdd(_cacheDel[i]);
    }
    for (int i = 0 ; i < _cacheAdd.size() ; i++ ) {
        RollDelete(_cacheAdd[i]);
    }
}
bool LinkedList::Commit () {
    _cacheAdd.clear();
    _cacheDel.clear();
}