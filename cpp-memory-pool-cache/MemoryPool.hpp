//
//  MemoryPool.hpp
//  cpp-memory-pool-cache
//
//  Created by MEDLAO on 19/12/2025.
//

#ifndef MemoryPool_hpp
#define MemoryPool_hpp

#include <stdio.h>
#pragma once
#include <cstddef>  // for size_t

class MemoryPool {
public:
    // Constructor: creates a pool with fixed-size blocks
    MemoryPool(std::size_t blockSize, std::size_t blockCount);

private:
    unsigned char* buffer; // points to raw memory owned by the pool
};

#endif /* MemoryPool_hpp */
