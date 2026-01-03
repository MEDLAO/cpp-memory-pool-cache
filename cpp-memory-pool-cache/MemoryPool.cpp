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

void* MemoryPool::allocate()
{
    if (freeListHead == nullptr) {
        return nullptr;
    }
    
    // Take the first free block
    FreeBlock* block = freeListHead;
    
    // Move head to the next free block
    freeListHead = freeListHead->next;
    
    // Give the block to the user
    return reinterpret_cast<void*>(block);
}

void MemoryPool::deallocate(void* ptr)
{
    if (ptr == nullptr) return;
    
    unsigned char* raw = static_cast<unsigned char*>(ptr);
    
    if (raw < buffer || raw >= buffer + totalSize) {
        return; // pointer not from this pool
    }
    
    // Treat the returned memory as a free block again
    FreeBlock* block = reinterpret_cast<FreeBlock*>(ptr);
    
    // Insert it at the front of the free list
    block->next = freeListHead;
    freeListHead = block;
}

MemoryPool::~MemoryPool()
{
    delete[] buffer;
}

