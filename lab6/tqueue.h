#ifndef TQUEUE_H
#define TQUEUE_H

#include "tqueue_item.h"
#include "titerator.h"
#include <memory>

template <typename T> class TQueue {
public:
    // Конструктор по умолчанию
    TQueue();
    // Конструктор копирования очереди.
    TQueue(const TQueue& other);
    // Метод, добавляющий фигуру в конец очереди.
    void Push(std::shared_ptr<T> &&trapezoid); // here may be &&
    // Метод, убирающий первую фигуру из очереди.
    void Pop();
    // Метод, возвращающий ссылку на первую в очереди фигуру
    std::shared_ptr<T>& Top();
    // Метод, проверяющий пустоту очереди
    bool Empty();
    // Метод, возвращающий длину очереди
    size_t Length();
    // Оператор вывода очереди в формате:
    // "=> Sn Sn-1 ... S1 =>", где Si - площадь фигуры,
    // а n – номер последней фигуры в очереди
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);
    // Метод, удаляющий все элементы контейнера,
    // но позволяющий пользоваться им.
    void Clear();
    // 
    TIterator<TQueueItem<T>, T> begin();
    TIterator<TQueueItem<T>, T> end();
    // Деструктор
    virtual ~TQueue();
private:
    std::shared_ptr<TQueueItem<T>> head, tail;
};

#endif // TQUEUE_H