cmake_minimum_required(VERSION 3.15)

project(MyFirstProject VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(MyExecutable
  main.cpp
  Point.cpp
)
