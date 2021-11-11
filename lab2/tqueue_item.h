#ifndef TQUEUE_ITEM_H
#define TQUEUE_ITEM_H
 
#include "trapezoid.h"

class TQueueItem {
public:
  TQueueItem();
  TQueueItem(const Trapezoid& trapezoid);
  TQueueItem(const TQueueItem& other);
  
  TQueueItem* SetNext(TQueueItem* next);
  TQueueItem* GetNext();

  Trapezoid GetTrapezoid() const;
 
  friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);
  
  virtual ~TQueueItem();

public:
  Trapezoid trapezoid;
  TQueueItem *next;
};
 
#endif // TQUEUE_ITEM_H