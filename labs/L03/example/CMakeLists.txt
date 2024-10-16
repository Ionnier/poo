cmake_minimum_required(VERSION 3.29)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        include/menu.h
        src/menu.cpp
        include/bloc.h
        include/adresa.h
        include/apartament.h
        include/scara.h
        include/bloc_repository.h
        src/bloc_repository.cpp
        src/bloc.cpp
        src/apartament.cpp
        src/scara.cpp
        src/adresa.cpp
)
