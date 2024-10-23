cmake_minimum_required(VERSION 3.29)
project(example)

set(CMAKE_CXX_STANDARD 20)

add_executable(example main.cpp
        include/angajat.h
        src/angajat.cpp
        include/data.h
        include/angajat_permanent.h
        src/angajat_permanent.cpp
        include/angajat_temporar.h
        src/angajat_temporar.cpp
        include/menu.h
        src/menu.cpp)
