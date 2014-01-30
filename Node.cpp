/* 
 * File:   Node.cpp
 * Author: chachalaca
 * 
 * Created on 10. červenec 2013, 9:22
 */

#include "Node.h"

Node::Node(int value) {
    this->value = value;
}

Node::Node(const Node& orig) {
}

Node::~Node() {
}

Node* Node::setNext(Node* next) {
    this->next = next;
    return this;
}
        
Node* Node::setPrev(Node* prev) {
    this->prev = prev;
    return this;
    
}

Node* Node::getNext() {
    
    return this->next;
}
        
Node* Node::getPrev() {
    
    return this->prev;
    
}
