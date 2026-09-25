cmake_minimum_required(VERSION 3.29)
project(HSE_learningC C)

set(CMAKE_C_STANDARD 11)

add_executable(HSE_learningC main.c
        libs/Vector.h
        libs/Set.h
        libs/Deque.h
        libs/Deque.c
        libs/Vector.c
        libs/Set.c
        libs/allKirills.h
        libs/Deque.c
)
