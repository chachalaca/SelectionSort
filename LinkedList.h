/* 
 * File:   LinkedList.h
 * Author: chachalaca
 *
 * Created on 10. červenec 2013, 9:21
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList& orig);
    virtual ~LinkedList();
    
    LinkedList* selSort(); 
    
    LinkedList* addLast(int value);
    LinkedList* addAfter(int i, int value);
    LinkedList* addBefore(int i, int value); 
    int getValue(int i);
    int getSize();
    LinkedList* deleteElement(int i);    
    
    
private:
    int findMin(int from);
    Node* getElement(int i);
    Node* first;
    Node* last;
    int size;
};

#endif	/* LINKEDLIST_H */

