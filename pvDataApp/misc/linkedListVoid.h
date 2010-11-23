/* linkedListVoid.h */
/**
 * Copyright - See the COPYRIGHT that is included with this distribution.
 * EPICS pvDataCPP is distributed subject to a Software License Agreement found
 * in file LICENSE that is included with this distribution.
 */

#include "pvType.h"
#include "showConstructDestruct.h"
#ifndef LINKEDLISTVOID_H
#define LINKEDLISTVOID_H
namespace epics { namespace pvData { 

class LinkedListVoid;
class LinkedListVoidNode;

class LinkedListVoidNode {
public:
    ~LinkedListVoidNode();
    static ConstructDestructCallback *getConstructDestructCallback();
    void *getObject();
    bool isOnList();
protected:
    LinkedListVoidNode(void *object);
private:
    LinkedListVoidNode(bool isHead);
    friend class LinkedListVoid;
    void *object;
    LinkedListVoidNode *before;
    LinkedListVoidNode *after;
    // do not implement the following
    LinkedListVoidNode(const LinkedListVoidNode&);
    LinkedListVoidNode & operator=(const LinkedListVoidNode&);
};

class LinkedListVoid {
public:
    ~LinkedListVoid();
    static ConstructDestructCallback *getConstructDestructCallback();
    int getLength();
    void addTail(LinkedListVoidNode *listNode);
    void addHead(LinkedListVoidNode *listNode);
    void insertAfter(LinkedListVoidNode *listNode,
        LinkedListVoidNode *addNode);
    void insertBefore(LinkedListVoidNode *listNode,
        LinkedListVoidNode *addNode);
    LinkedListVoidNode *removeTail();
    LinkedListVoidNode *removeHead();
    void remove(LinkedListVoidNode *listNode);
    void remove(void * object);
    LinkedListVoidNode *getHead();
    LinkedListVoidNode *getTail();
    LinkedListVoidNode *getNext(LinkedListVoidNode *listNode);
    LinkedListVoidNode *getPrev(LinkedListVoidNode *listNode);
    bool isEmpty();
    bool contains(void * object);
protected:
    LinkedListVoid();
private:
    friend class LinkedListVoidNode;
    LinkedListVoidNode *head;
    int length;
    // do not implement the following
    LinkedListVoid(const LinkedListVoid&);
    LinkedListVoid & operator=(const LinkedListVoid&);
};

}}
#endif  /* LINKEDLISTVOID_H */



