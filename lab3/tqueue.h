#ifndef TQUEUE_H
#define TQUEUE_H

#include "tqueue_item.h"
#include <memory>

class TQueue {
public:
    // Конструктор по умолчанию
    TQueue();
    // Конструктор копирования очереди.
    TQueue(const TQueue& other);
    // Метод, добавляющий фигуру в конец очереди.
    void Push(const Trapezoid& trapezoid);
    // Метод, убирающий первую фигуру из очереди.
    void Pop();
    // Метод, возвращающий ссылку на первую в очереди фигуру
    Trapezoid& Top();
    // Метод, проверяющий пустоту очереди
    bool Empty();
    // Метод, возвращающий длину очереди
    size_t Length();
    // Оператор вывода очереди в формате:
    // "=> Sn Sn-1 ... S1 =>", где Si - площадь фигуры,
    // а n – номер последней фигуры в очереди
    friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);
    // Метод, удаляющий все элементы контейнера,
    // но позволяющий пользоваться им.
    void Clear();
    // Деструктор
    virtual ~TQueue();
private:
    std::shared_ptr<TQueueItem> head, tail;
};

#endif // TQUEUE_H