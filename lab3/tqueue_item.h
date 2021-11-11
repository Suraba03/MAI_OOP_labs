#ifndef TQUEUE_ITEM_H
#define TQUEUE_ITEM_H
 
#include <memory>
#include "trapezoid.h"

class TQueueItem {
public:
  TQueueItem(const std::shared_ptr<Trapezoid>& trapezoid);
  TQueueItem(const TQueueItem& other);
  
  std::shared_ptr<TQueueItem> SetNext(std::shared_ptr<TQueueItem>& next);
  std::shared_ptr<TQueueItem> GetNext();

  std::shared_ptr<Trapezoid> GetTrapezoid() const;
 
  friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);
  
  virtual ~TQueueItem();

public:
  std::shared_ptr<Trapezoid> trapezoid;
  std::shared_ptr<TQueueItem> next;
};
 
#endif // TQUEUE_ITEM_H