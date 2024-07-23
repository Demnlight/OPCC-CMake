cmake_minimum_required(VERSION 3.26)

project(OPCC)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(tests)