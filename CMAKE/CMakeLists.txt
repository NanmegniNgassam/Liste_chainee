cmake_minimum_required(VERSION 3.20.0)

project(Shop)

set(CMAKE_CXX_STANDARD 18)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../EXECUTABLE")

add_executable(Shop
  ../CODE_SOURCE/main.c
  ../CODE_SOURCE/LISTE/Liste.c ../CODE_SOURCE/LISTE/Liste.h
)