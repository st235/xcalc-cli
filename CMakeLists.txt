cmake_minimum_required(VERSION 3.17)
project(xcalc_cli)
set(CMAKE_CXX_STANDARD 14)

message(${CMAKE_SOURCE_DIR})

add_library(xcalc_core SHARED IMPORTED)
set_target_properties(xcalc_core PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/xcalc/libxcalc_core.so)

add_executable(xcalc_cli main.cpp)
target_link_libraries(xcalc_cli xcalc_core)


include_directories(xcalc_cli ${CMAKE_SOURCE_DIR}/libs/xcalc/include)
