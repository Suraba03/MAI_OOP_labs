#ifndef LAB6_TALLOCATIONBLOCK_H
#define LAB6_TALLOCATIONBLOCK_H

#include <iostream>
#include <cstdlib>
#include "TLinkedList.h"

class TAllocationBlock {
public:
    TAllocationBlock(int32_t size, int32_t count);

    void *Allocate();
    void Deallocate(void *ptr);
    bool Empty();
    int32_t Size();

    virtual ~TAllocationBlock();

private:
    char *used_bl;
    TLinkedList free_bl;
};

#endif //LAB6_TALLOCATIONBLOCK_H
