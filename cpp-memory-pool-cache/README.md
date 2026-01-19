# C++ Memory Pool Allocator

This project implements a simple fixed-size memory pool in C++.  
The goal is to understand how dynamic memory allocation works *under the hood* by building a custom allocator from scratch.

Instead of asking the operating system for memory each time, the pool allocates one big buffer and then manages it manually using fixed-size blocks and a free list.  
This approach is common in high-performance systems (game engines, databases, real-time software).

The project focuses on:
- pointers and raw memory
- object lifetime
- constant-time allocation
- safe manual memory management
