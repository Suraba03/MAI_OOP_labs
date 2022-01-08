#include "TLinkedList.h"

TLinkedList::TLinkedList() {
    first = nullptr;
}

void TLinkedList::InsertFirst(void* link) {
    auto *other = new TLinkedListItem(link);
    other->SetNext(first);
    first = other;
}

void TLinkedList::Insert(int position, void *link) {
    TLinkedListItem *iter = this->first;
    auto *other = new TLinkedListItem(link);
    if (position == 1) {
        other->SetNext(iter);
        this->first = other;
    } else {
        if (position <= this->Length()) {
            for (int i = 1; i < position - 1; ++i)
                iter = iter->GetNext();
            other->SetNext(iter->GetNext());
            iter->SetNext(other);
        }
    }
}

void TLinkedList::InsertLast(void *link) {
    auto *other = new TLinkedListItem(link);
    TLinkedListItem *iter = this->first;
    if (first != nullptr) {
        while (iter->GetNext() != nullptr) {
            iter = iter->SetNext(iter->GetNext());
        }
        iter->SetNext(other);
        other->SetNext(nullptr);
    }
    else {
        first = other;
    }
}

int TLinkedList::Length() {
    int len = 0;
    TLinkedListItem* item = this->first;
    while (item != nullptr) {
        item = item->GetNext();
        len++;
    }
    return len;
}

bool TLinkedList::Empty() {
    return first == nullptr;
}

void TLinkedList::Remove(int &position) {
    TLinkedListItem *iter = this->first;
    if (position <= this->Length()) {
        if (position == 1) {
            this->first = iter->GetNext();
        } else {
            int i = 1;
            for (i = 1; i < position - 1; ++i) {
                iter = iter->GetNext();
            }
            iter->SetNext(iter->GetNext()->GetNext());
        }

    } else {
        std::cout << "error" << std::endl;
    }
}

void TLinkedList::Clear() {
    first = nullptr;
}

void * TLinkedList::GetBlock() {
    return this->first->GetBlock();
}

TLinkedList::~TLinkedList() {
    delete first;
}