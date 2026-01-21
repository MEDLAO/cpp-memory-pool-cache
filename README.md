# C++ Memory Pool Allocator

This project implements a simple fixed-size memory pool in C++.  
Its purpose is to understand how memory allocation works at a low level by building a small allocator from scratch.
It was an opportunity to practice several C++ concepts such as raw memory management, pointers, and
simple data structures.

The pool allocates one big buffer and manages it manually using fixed-size blocks and a free list.  
This avoids repeated calls to the operating system and makes allocation and deallocation constant time.

---

## How It Works

- One contiguous buffer is allocated in the constructor  
- The buffer is split into equal-sized blocks  
- Free blocks are linked using a simple free list  

### Allocation
- Take the first block from the free list  
- Move the head forward  
- Return the block as `void*`  
- Runs in **O(1)**  

### Deallocation
- Check that the pointer belongs to the pool  
- Treat it as a free block again  
- Insert it back into the free list  
- Runs in **O(1)**  

---

## Example

```cpp
MemoryPool pool(128, 32);

void* a = pool.allocate();
void* b = pool.allocate();

pool.deallocate(a);
pool.deallocate(b);
```
