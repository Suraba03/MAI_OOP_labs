#include "tqueue.h"
#include <vector>

TQueue::TQueue() : head(nullptr), tail(nullptr) {
    std::cout << "Default queue created" << std::endl;
}

TQueue::TQueue(const TQueue& other) {
    head = other.head;
    tail = other.tail;
    std::cout << "Queue copied" << std::endl;
}

/* TQueue::TQueue(const TQueue& other) {
    std::shared_ptr<TQueueItem> item = other.head;

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

void TQueue::Push(std::shared_ptr<Trapezoid> &&trapezoid) {
    std::shared_ptr<TQueueItem> other(new TQueueItem(trapezoid));

    if (tail == nullptr) {
        head = tail = other;
        std::cout << "Added one trapezoid to tail. " << "Coordinates: " << *other->trapezoid << ". Area = " << other->trapezoid->Area() << std::endl;
        return;
    }
    tail->SetNext(other);
    //tail->next = other;
    tail = other;
    tail->next = nullptr;
    std::cout << "Added one trapezoid to tail. " << "Coordinates: " << *other->trapezoid << ". Area = " << other->trapezoid->Area() << std::endl;
}

void TQueue::Pop() {
    if (head == nullptr)
        return;

    std::cout << "Removed one trapezoid from head."  << "Coordinates: " << *head->trapezoid << ". Area = " << head->trapezoid->Area() << std::endl;

    head = head->GetNext();

    if (head == nullptr)
        tail = nullptr;
}

std::shared_ptr<Trapezoid>& TQueue::Top() {
    return head->trapezoid;
}

bool TQueue::Empty() {
    return (head == nullptr) && (tail == nullptr);
}

size_t TQueue::Length() {
    if (head == nullptr && tail == nullptr)
        return 0;
    std::shared_ptr<TQueueItem> temp = head;
    int counter = 0;
    while (temp != tail->GetNext()) {
        temp = temp->GetNext();
        counter++;
    }
    return counter;
}

std::ostream& operator<<(std::ostream& os, const TQueue& queue) {
    std::shared_ptr<TQueueItem> temp = queue.head;
    std::vector<std::shared_ptr<TQueueItem>> v;

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