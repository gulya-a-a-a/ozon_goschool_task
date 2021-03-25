cmake_minimum_required (VERSION 3.8)

project(ozon_goschool_task VERSION 0.1)

add_executable (findUnsortedSubarray "findUnsortedSubarray.cpp")
set_target_properties(findUnsortedSubarray PROPERTIES CXX_STANDARD 14 REQUIRED ON)

