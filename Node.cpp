//
// Created by johnc on 4/5/2023.
//

#include "Node.h"
#include <sstream>

Node::Node() : _val(0), _next(nullptr) {}

Node::Node(int val) : _val(val), _next(nullptr) {}
Node::Node(Node* node) : _val(node->_val), _next(node->_next) {}

string Node::ToString() const {
    stringstream  ss;
    ss << this->_val;
    return ss.str();
}