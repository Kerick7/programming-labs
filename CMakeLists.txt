cmake_minimum_required(VERSION 4.1)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp
        main.cpp
        Rectangle.h
        Queue.h
        FixedQueue.h
        VectorQueue.h
        ListQueue.h)
