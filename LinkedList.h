//
// Created by johnc on 4/5/2023.
//

#ifndef INC_2PC_LINKEDLIST_H
#define INC_2PC_LINKEDLIST_H

#include <vector>
#include "Node.h"

class LinkedList {
    public:
    LinkedList(LinkedList *list);

        Node* _head;
        vector<int> _cacheAdd;
        vector<int> _cacheDel;

        LinkedList();
        LinkedList(int val);
        LinkedList(Node* node);
        bool Add(int val);
        bool Delete(int key);
        void Print() const;
        Node* Clone() const;
        bool RollBack ();
        bool Commit ();

    LinkedList * Clone();

    bool RollDelete(int key);

    bool RollAdd(int val);
};


#endif //INC_2PC_LINKEDLIST_H
