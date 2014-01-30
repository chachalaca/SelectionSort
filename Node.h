/* 
 * File:   Node.h
 * Author: chachalaca
 *
 * Created on 10. červenec 2013, 9:22
 */

#ifndef NODE_H
#define	NODE_H

class Node {
public:
    Node(int value);
    Node(const Node& orig);
    virtual ~Node();
    Node* setNext(Node* node);
    Node* setPrev(Node* node);
    Node* getNext();
    Node* getPrev();
    int value;
private:
    
    Node* next;
    Node* prev;
};

#endif	/* NODE_H */

