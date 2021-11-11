#include "tqueue_item.h"
#include <iostream>

TQueueItem::TQueueItem(const std::shared_ptr<Trapezoid>& trapezoid) {
  	this->trapezoid = trapezoid;
  	this->next = nullptr;
  	std::cout << "Queue item: created" << std::endl;
}
 
TQueueItem::TQueueItem(const TQueueItem& other) {
	this->trapezoid = other.trapezoid;
	this->next = other.next;
  	std::cout << "Queue item: copied" << std::endl;
}

std::shared_ptr<TQueueItem> TQueueItem::SetNext(std::shared_ptr<TQueueItem> &next) { /////////////// added &
	std::shared_ptr<TQueueItem> old = this->next;
	this->next = next;
	return old;
}

std::shared_ptr<Trapezoid> TQueueItem::GetTrapezoid() const {
	return this->trapezoid;
}


std::shared_ptr<TQueueItem> TQueueItem::GetNext() {
	return this->next;
}

TQueueItem::~TQueueItem() {
  	std::cout << "Queue item: deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
  	os << obj.trapezoid->Area();
  	return os;
}

