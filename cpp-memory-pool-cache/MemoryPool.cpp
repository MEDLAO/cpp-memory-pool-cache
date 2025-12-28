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
      freeListHead(nullptr)
{
    buffer = new unsigned char[totalSize];
    
    // blockSize = 32;   // temporary, for testing only
    
    // first block
    freeListHead = reinterpret_cast<FreeBlock*>(buffer);
    //freeListHead->next = nullptr;
    FreeBlock* current = freeListHead;
    
    // second block (no loop yet)
    /*unsigned char* secondBlockAddress = buffer + blockSize;
    FreeBlock* secondBlock = reinterpret_cast<FreeBlock*>(secondBlockAddress);
    
    freeListHead->next = secondBlock;
    secondBlock->next = nullptr;*/
}

MemoryPool::~MemoryPool()
{
    delete[] buffer;
}
