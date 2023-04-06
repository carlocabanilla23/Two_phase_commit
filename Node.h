//
// Created by johnc on 4/5/2023.
//

#ifndef INC_2PC_NODE_H
#define INC_2PC_NODE_H
#include <string>
using namespace std;

class Node {
    public:
        int _val;
        Node* _next;

        Node();
        Node(int val);
        Node(Node* node);
        string ToString () const;

};


#endif //INC_2PC_NODE_H
