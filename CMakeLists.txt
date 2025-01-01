cmake_minimum_required(VERSION 3.10)
project(my_filter)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_filter my_filter.cpp)

# Link with necessary libraries (you might need to adjust this)
target_link_libraries(my_filter iptables)