cmake_minimum_required(VERSION 3.2)

project(OPCC)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

add_subdirectory(src/Converter)