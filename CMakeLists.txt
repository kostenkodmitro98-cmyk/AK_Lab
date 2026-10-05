cmake_minimum_required(VERSION 3.10)
project(CalculatorProject)

add_library(calculator STATIC calculator.cpp)
add_executable(calc_app main.cpp)
target_link_libraries(calc_app calculator)
