#ifndef TQUEUE_ITEM_H
#define TQUEUE_ITEM_H
 
#include <memory>
#include "trapezoid.h"

class TQueueItem {
public:
  TQueueItem(const Trapezoid& trapezoid);
  TQueueItem(const TQueueItem& other);
  
  std::shared_ptr<TQueueItem> SetNext(std::shared_ptr<TQueueItem> next);
  std::shared_ptr<TQueueItem> GetNext();

  Trapezoid GetTrapezoid() const;
 
  friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);
  
  virtual ~TQueueItem();

public:
  Trapezoid trapezoid;
  std::shared_ptr<TQueueItem> next;
};
 
#endif // TQUEUE_ITEM_H