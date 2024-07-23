file(GLOB SRCS *.cpp)
file(GLOB HEADERS *.hpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(Test ${SRCS} ${HEADERS})
target_link_libraries(Test libConverter gtest_main gmock_main)

add_test(Test foo)