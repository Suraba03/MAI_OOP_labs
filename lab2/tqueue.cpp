#include "tqueue.h"

TQueue::TQueue() : head(nullptr), tail(nullptr) {
    std::cout << "Default queue created" << std::endl;
}

TQueue::TQueue(const TQueue& other) {
    head = other.head;
    tail = other.tail;
    std::cout << "Queue copied" << std::endl;
}

void TQueue::Push(const Trapezoid& trapezoid) {
    TQueueItem* other = new TQueueItem(trapezoid);

    if (tail == NULL) {
        head = tail = other;
        std::cout << "Added one trapezoid to tail. " << "Coordinates: " << other->trapezoid << ". Area = " << other->trapezoid.Area() << std::endl;
        return;
    }
    /* tail->SetNext(other); */
    tail->next = other;
    tail = other;
    std::cout << "Added one trapezoid to tail. " << "Coordinates: " << other->trapezoid << ". Area = " << other->trapezoid.Area() << std::endl;
}

void TQueue::Pop() {
    if (head == NULL)
        return;

    std::cout << "Removed one trapezoid " << head->trapezoid << " from head" << std::endl;

    head = head->next;
    
    if (head == NULL)
        tail = NULL;
}

Trapezoid& TQueue::Top() {
    Trapezoid& out = head->trapezoid;
    return out;
}

bool TQueue::Empty() {
    return (head == nullptr) && (tail == nullptr);
}

size_t TQueue::Length() {
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
    
    os << "Queue: ";
    os << "<= ";
    while (temp != /* queue.tail->GetNext() */nullptr) {
        os << temp->trapezoid.Area() << " ";
        temp = temp->next;
    }
    os << "<=";
    return os;
}

void TQueue::Clear() {
    while (tail != head) {
        this->Pop();
    }
    std::cout << "Queue was cleared but still exist" << std::endl;
}

TQueue::~TQueue() {
    delete head;
    delete tail;
    std::cout << "Queue was deleted" << std::endl;
}