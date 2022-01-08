#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include "TLinkedListItem.h"
#include <memory>
#include <iostream>

class TLinkedList {
public:
    TLinkedList();
    void InsertFirst(void *link);
    void InsertLast(void *link);
    void Insert(int position, void *link);
    int Length();
    bool Empty();
    void Remove(int &position);
    void Clear();

    void* GetBlock();

    virtual ~TLinkedList();
private:
    TLinkedListItem* first;
};

#endif // TLINKEDLIST_H