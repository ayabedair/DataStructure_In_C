cmake_minimum_required(VERSION 3.24)
project(PolishNotation C)

set(CMAKE_C_STANDARD 11)

add_executable(PolishNotation main.c stack.c stack.h Global.h)
