//
//  main.cpp
//  cpp-memory-pool-cache
//
//  Created by MEDLAO on 17/12/2025.
//

#include <iostream>
#include "MemoryPool.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    MemoryPool pool(128, 32);
    
    void* a = pool.allocate();
    void* b = pool.allocate();
    
    pool.deallocate(a);
    pool.deallocate(b);
    
    std::cout << "MemoryPool constructed\n";
    
    return 0;
}
