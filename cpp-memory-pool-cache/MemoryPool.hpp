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
    MemoryPool(std::size_t size);
    
private:
    unsigned char* buffer; // start of memory
    std::size_t totalSize; // total bytes owned by the pool
    
};

#endif /* MemoryPool_hpp */
