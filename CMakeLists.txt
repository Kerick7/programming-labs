cmake_minimum_required(VERSION 4.1)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled2 main.cpp
        additional.h
        additional.cpp
        sorts.h
        sorts.cpp
        models.h
        advanced_sorts.h
        advances_sorts.cpp)
