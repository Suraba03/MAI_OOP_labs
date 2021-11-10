#include "tqueue_item.h"
#include <iostream>

template <class T> 
TQueueItem<T>::TQueueItem(const std::shared_ptr<T>& item) {
  	this->item = item;
  	this->next = nullptr;
  	std::cout << "Queue item: created" << std::endl;
}

template <class T> 
TQueueItem<T>::TQueueItem(const TQueueItem& other) { // maybe change to TQueueItem<T>
	this->item = other.item;
	this->next = other.next;
  	std::cout << "Queue item: copied" << std::endl;
}

template <class T> 
std::shared_ptr<TQueueItem<T>> TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem<T>> &next) { /////////////// added &
	std::shared_ptr<TQueueItem<T>> old = this->next;
	this->next = next;
	return old;
}

template <class T> 
std::shared_ptr<T> TQueueItem<T>::GetTrapezoid() const {
	return this->item;
}

template <class T> 
std::shared_ptr<TQueueItem<T>> TQueueItem<T>::GetNext() {
	return this->next;
}

template <class T> 
TQueueItem<T>::~TQueueItem() {
  	std::cout << "Queue item: deleted" << std::endl;
}

template <class A>
std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj) {
    os << obj.item->Area();
    return os;
}

template class TQueueItem<Trapezoid>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Trapezoid>& obj);

