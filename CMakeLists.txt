cmake_minimum_required(VERSION 3.5.0)
project(arasterizer)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

add_executable(arasterizer 
    main.cpp
    tgaimage.cpp
    renderer.cpp
    renderer.h
    geometry.h
    model.cpp
    model.h
)