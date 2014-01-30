/* 
 * File:   LinkedList.cpp
 * Author: chachalaca
 * 
 * Created on 10. červenec 2013, 9:21
 */
using namespace std;
#include <iostream>
#include "LinkedList.h"

#include "Node.h"

#include <stdexcept>
#include <stdlib.h>

LinkedList::LinkedList() {
    this->size = 0;
}

LinkedList::LinkedList(const LinkedList& orig) {
}

LinkedList::~LinkedList() {
}

LinkedList* LinkedList::addAfter(int i, int value) {
    if(i>this->size) {
        throw std::invalid_argument( "DeleteElement: neplatny rozsah v argumentu" );
    }
    Node* curr = this->getElement(i);
    Node* n = new Node(value);
    
    if (i == 0) { //na zacatek
        n->setNext(this->first);
        this->first->setPrev(n);
        this->first = n;
    } else {
    
        if(i==this->size) { //na konec
            n->setPrev(this->last);
            this->last->setNext(n);
            this->last = n;
        }

        else { //jinak
           curr->getNext()->setPrev(n);
           n->setNext(curr->getNext());
           n->setPrev(curr);
           curr->setNext(n);
        }
    
    
    }
    this->size++;
}

LinkedList* LinkedList::addLast(int value) {
    Node *n = new Node(value);
    if(this->last){ 
        this->last->setNext(n);
        n->setPrev(this->last);
    }
    else {
        this->first = n;
    }
        
    this->last = n;
    this->size ++;
    return this;
}

LinkedList* LinkedList::addBefore(int i, int value) {
    if(i>this->size) {
        throw std::invalid_argument( "AddBefore: neplatny rozsah v argumentu" );
    }
    return this;
}
Node* LinkedList::getElement(int i) {
    i--;
    if(i>this->size) {
        throw std::invalid_argument( "GetElement: neplatny rozsah v argumentu" );
    }
    int iter = 1;
    Node* curr = this->first;
    for (int iter = 1; iter <= i; iter++) {
        curr = curr->getNext();
    }
    return curr;
    
}
LinkedList* LinkedList::deleteElement(int i){
    if(i>this->size) {
        throw std::invalid_argument( "DeleteElement: neplatny rozsah v argumentu" );
    }
    if (i == 0) {
        throw std::invalid_argument( "DeleteElement: neplatny rozsah v argumentu" );
    } else {
    Node* curr = this->getElement(i);
        if(i==this->size) { //je posledni
            curr->getPrev()->setNext(NULL);
            this->last = curr->getPrev();
        }
        else if(i==1) { //je prvni
            curr->getNext()->setPrev(NULL);
            this->first = curr->getNext();
        }
        else { //jinak
           curr->getNext()->setPrev(curr->getPrev());
           curr->getPrev()->setNext(curr->getNext());
        }
    delete curr;
    this->size--;
    }
    
    return this;
}

int LinkedList::getValue(int i) {
    return this->getElement(i)->value;
}

int LinkedList::getSize() {
    return this->size;
}

int LinkedList::findMin(int from) {
    int cache;
    Node* curr = this->getElement(from);
    for (int i = from; i <= this->size; i++) {
        if (i==from) {
            cache = i;
        }
        
        if (curr->value > this->getElement(cache)->value) {
            cache = i;
            
        }
        
        curr = curr->getNext();
    }

    return cache;
}

LinkedList* LinkedList::selSort() {
    for (int i = 1; i <= this->size; i++) {
        int min = this->findMin(i);
        
        Node* curr = this->getElement(min);
        this->addAfter(i-1, curr->value);
        this->deleteElement(min+1);
        
    }

    return this;
}



