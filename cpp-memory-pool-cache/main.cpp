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
    
    std::cout << "Allocated two blocks\n";
    
    pool.deallocate(a);
    pool.deallocate(b);
    
    std::cout << "Deallocated two blocks\n";
    
    void* c = pool.allocate();
    
    std::cout << "Allocated again \n";
    
    return 0;
}
