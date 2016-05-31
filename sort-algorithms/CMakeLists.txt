cmake_minimum_required(VERSION 2.8)
project(Sort-Algorithms)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2 -Wall")

set (Include_dirs 
        include/ 
)
set (Project_bin_src 
        src/main.cpp
)
set (Project_src    
        src/Archivos.cpp
        src/Ordenamientos.cpp
)

include_directories (${Include_dirs})
#add_library (Project_lib SHARED ${Project_src})

add_executable(sort-algorithms.out ${Project_bin_src} ${Project_src})
