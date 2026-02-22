cmake_minimum_required(VERSION 4.1)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2a
        lab2a/main.cpp
        lab2a/Rectangle.h
        lab2a/Queue.h
        lab2a/FixedQueue.h
        lab2a/VectorQueue.h
        lab2a/ListQueue.h)

add_executable(lab2b
        lab2b/main.cpp)