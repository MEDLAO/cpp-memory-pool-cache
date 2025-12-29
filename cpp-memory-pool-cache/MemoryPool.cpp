//
//  MemoryPool.cpp
//  cpp-memory-pool-cache
//
//  Created by MEDLAO on 19/12/2025.
//

#include "MemoryPool.hpp"

MemoryPool::MemoryPool(std::size_t size, std::size_t blockSize)
    : buffer(nullptr),
      totalSize(size),
      blockSize(blockSize),
      blockCount(size / blockSize),
      freeListHead(nullptr)
{
    buffer = new unsigned char[totalSize];
    
    // first block
    freeListHead = reinterpret_cast<FreeBlock*>(buffer);
   
    FreeBlock* current = freeListHead;
    
    for (std::size_t i = 1; i < blockCount; ++i) {
        // compute the address of block i
        unsigned char* nextBlockAdress = buffer + i * blockSize;
        // link
        current->next = reinterpret_cast<FreeBlock*>(nextBlockAdress);
        // move current forward
        current = current->next;
    }
    
    current->next = nullptr;
    
}

MemoryPool::~MemoryPool()
{
    delete[] buffer;
}
