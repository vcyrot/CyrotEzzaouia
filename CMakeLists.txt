cmake_minimum_required(VERSION 3.28)
project(CyrotEzzaouia)

set(CMAKE_CXX_STANDARD 17)

add_executable(CyrotEzzaouia src/main.cpp
        src/Deal.cpp
        src/Deal.h
        src/Facility.cpp
        src/Facility.h
        src/Part.cpp
        src/Part.h
        src/Portfolio.cpp
        src/Portfolio.h
        src/Lender.cpp
        src/Lender.h
        src/Borrower.cpp
        src/Borrower.h
        src/Database.cpp
        src/Database.h)
