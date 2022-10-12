cmake_minimum_required(VERSION 3.23)
project(my_vector)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_vector main.cpp src/my_vector.cpp lib/my_vector.h lib/my_iterator.h src/user_functions.cpp lib/user_functions.h lib/header.h)
