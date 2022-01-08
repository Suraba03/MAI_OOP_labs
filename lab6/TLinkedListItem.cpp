#include "TLinkedListItem.h"
#include <iostream>

TLinkedListItem::TLinkedListItem(void* l) {
    this->link = l;
    this->next = nullptr;
}

TLinkedListItem* TLinkedListItem::SetNext(TLinkedListItem* n) {
    TLinkedListItem* o = this->next;
    this->next = n;
    return o;
}

TLinkedListItem* TLinkedListItem::GetNext() {
    return this->next;
}

void* TLinkedListItem::GetBlock() {
    return this->link;
}

TLinkedListItem::~TLinkedListItem() {
}
