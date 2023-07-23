cmake_minimum_required(VERSION 3.25)
project(work5)

set(CMAKE_CXX_STANDARD 17)

add_executable(work5 main.cpp Address.cpp Address.h Person.h Person.cpp Lawyer.cpp Lawyer.h Client.cpp Client.h LawFirm.cpp LawFirm.h)
