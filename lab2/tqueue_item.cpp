#include "tqueue_item.h"

#include <iostream>

TQueueItem::TQueueItem(const Trapezoid& trapezoid) {
  	this->trapezoid = trapezoid;
  	this->next = nullptr;
  	std::cout << "Queue item: created" << std::endl;
}
 
TQueueItem::TQueueItem(const TQueueItem& other) {
	this->trapezoid = other.trapezoid;
	this->next = other.next;
  	std::cout << "Queue item: copied" << std::endl;
}

TQueueItem* TQueueItem::SetNext(TQueueItem* next) {
	TQueueItem* old = this->next;
	this->next = next;
	return old;
}

Trapezoid TQueueItem::GetTrapezoid() const {
	return this->trapezoid;
}

TQueueItem* TQueueItem::GetNext() {
	return this->next;
}

TQueueItem::~TQueueItem() {
  	std::cout << "Queue item: deleted" << std::endl;
  	if (next != nullptr)
		delete next;
}

std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
  	os << "[" << obj.trapezoid << "]" << std::endl;
  	return os;
}

