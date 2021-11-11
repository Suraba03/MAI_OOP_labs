#include "tqueue.h"
#include <vector>

TQueue::TQueue() : head(nullptr), tail(nullptr) {
    std::cout << "Default queue created" << std::endl;
}

/* TQueue::TQueue(const TQueue& other) {
    TQueueItem *item = other.head;

    while (item->next != nullptr) {
        TQueueItem *item1 = new TQueueItem;
        item1->next = nullptr;
        tail->trapezoid = item->trapezoid;
        tail->next = item1;
        tail = item1;
        item = item->next;
    }
    std::cout << "Queue copied" << std::endl;
} */

TQueue::TQueue(const TQueue& other) {
    head = other.head;
    tail = other.tail;
}

void TQueue::Push(const Trapezoid& trapezoid) {
    TQueueItem* other = new TQueueItem(trapezoid);

    if (tail == nullptr) {
        head = tail = other;
        std::cout << "Added one trapezoid to tail. " << "Coordinates: " << other->trapezoid << ". Area = " << other->trapezoid.Area() << std::endl;
        return;
    }
    tail->next = other;
    tail = other;
    tail->next = nullptr;
    std::cout << "Added one trapezoid to tail. " << "Coordinates: " << other->trapezoid << ". Area = " << other->trapezoid.Area() << std::endl;
}

void TQueue::Pop() {
    if (head == nullptr)
        return;

    std::cout << "Removed one trapezoid " << head->trapezoid << " from head" << std::endl;

    TQueueItem *temp = head;

    head = head->next;
    
    delete temp;

    if (head == nullptr)
        tail = nullptr;
}

Trapezoid& TQueue::Top() {
    Trapezoid& out = head->trapezoid;
    return out;
}

bool TQueue::Empty() {
    return (head == nullptr) && (tail == nullptr);
}

size_t TQueue::Length() {
    if (head == nullptr && tail == nullptr)
        return 0;
    TQueueItem *temp = head;
    int counter = 0;
    while (temp != tail->GetNext()) {
        temp = temp->GetNext();
        counter++;
    }
    return counter;
}

std::ostream& operator<<(std::ostream& os, const TQueue& queue) {
    TQueueItem *temp = queue.head;
    std::vector<TQueueItem *> v;

    os << "Queue: ";
    os << "=> ";
    while (temp != nullptr) {
        v.push_back(temp);
        //os << *temp << " ";
        temp = temp->GetNext();
    }
    for (int i = v.size() - 1; i >= 0; --i) 
        os << *v[i] << " ";
    os << "=>";
    return os;
}

void TQueue::Clear() {
    for (int i = 0; i < this->Length(); i++) {
        this->Pop();
    }
    std::cout << "Queue was cleared but still exist" << std::endl;
}

TQueue::~TQueue() {
    std::cout << "Queue was deleted" << std::endl;
}