#include "TAllocationBlock.h"

TAllocationBlock::TAllocationBlock(int32_t size, int32_t count) {
    used_bl = (char *)malloc(size * count);
    for (int32_t i = 0; i < count; ++i) {
        void *ptr = (void *)malloc(sizeof(void *));
        ptr = used_bl + i * size;
        free_bl.InsertLast(ptr);
    }
}

void *TAllocationBlock::Allocate() {
    if (!free_bl.Empty()) {
        void *res = free_bl.GetBlock();
        int32_t first = 1;
        free_bl.Remove(first);
        std::cout << "Rectangle created" << std::endl;
        return res;
    } else {
        throw std::bad_alloc();
    }
}

void TAllocationBlock::Deallocate(void *ptr) {
    free_bl.InsertFirst(ptr);
}

bool TAllocationBlock::Empty() {
    return free_bl.Empty();
}

int32_t TAllocationBlock::Size() {
    return free_bl.Length();
}

TAllocationBlock::~TAllocationBlock() {
    while (!free_bl.Empty()) {
        int32_t first = 1;
        free_bl.Remove(first);
    }
    free(used_bl);
    std::cout << "Rectangle deleted" << std::endl;
}