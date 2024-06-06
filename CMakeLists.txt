cmake_minimum_required(VERSION 3.28)

project(Azathoth64_Memory_Area)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Azathoth64_Memory_Area
        src/azathoth64/uuid.cpp
        src/azathoth64/memory/area.cpp
        src/main.cpp
)
