cmake_minimum_required(VERSION 3.22)
project(TLB)

set(CMAKE_CXX_STANDARD 17)


add_executable(TLB
        TLB.cpp
        TLB.h
        MMU.cpp
        MMU.h
        Policy/Policy.cpp
        Policy/Policy.h
        Policy/FIFO.cpp
        Policy/FIFO.h
        Policy/LRU.cpp
        Policy/LRU.h
        Policy/RAND.cpp
        Policy/RAND.h
        Policy/CLOCK.cpp
        Policy/CLOCK.h
        main.cpp
)
