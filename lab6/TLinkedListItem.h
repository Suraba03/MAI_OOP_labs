#ifndef TLINKEDLISTITEM_H
#define TLINKEDLISTITEM_H

#include <memory>

class TLinkedListItem {
public:
    TLinkedListItem(void *link);
    void* GetBlock();

    TLinkedListItem* SetNext(TLinkedListItem* next);
    TLinkedListItem* GetNext();

    virtual ~TLinkedListItem();
private:
    void* link;
    TLinkedListItem* next;
};

#endif // TLINKEDLISTITEM_H