cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        include/judet.h
        include/cnp.h
        src/cnp.cpp
        include/displayable.h
        include/readable.h
        src/persoana.cpp
        include/persoana.h
        include/angajat.h
        include/student.h
        src/angajat.cpp
        src/student.cpp
        include/student_angajat.h
        include/menu.h
        src/menu.cpp
)
