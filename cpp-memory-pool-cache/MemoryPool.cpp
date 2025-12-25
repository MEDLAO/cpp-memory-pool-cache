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
    
    blockSize = 32;   // temporary, for testing only
    
    freeListHead = reinterpret_cast<FreeBlock*>(buffer);
    freeListHead->next = nullptr;
    
    unsigned char* secondBlockAddress = buffer + blockSize;
    FreeBlock* secondBlock = reinterpret_cast<FreeBlock*>(secondBlockAddress);
    
    freeListHead->next = secondBlock;
    secondBlock->next = nullptr;
}

MemoryPool::~MemoryPool()
{
    delete[] buffer;
}
