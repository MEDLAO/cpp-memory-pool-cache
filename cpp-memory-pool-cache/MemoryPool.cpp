//
//  MemoryPool.cpp
//  cpp-memory-pool-cache
//
//  Created by MEDLAO on 19/12/2025.
//

#include "MemoryPool.hpp"

MemoryPool::MemoryPool(std::size_t size) : buffer(nullptr), totalSize(size)
{
    buffer = new unsigned char[totalSize];
    
    freeListHead = reinterpret_cast<FreeBlock*>(buffer);
    freeListHead->next = nullptr;
}

MemoryPool::~MemoryPool()
{
    delete[] buffer;
}
