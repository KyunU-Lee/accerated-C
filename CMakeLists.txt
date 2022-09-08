cmake_minimum_required(VERSION 3.23)
project(score4)

set(CMAKE_CXX_STANDARD 14)

add_executable(score4 main.cpp median.h median.cpp student_info.h student_info.cpp)
