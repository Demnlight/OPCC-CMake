file(GLOB SRCS *.cpp)
file(GLOB HEADERS *.hpp)

set (CMAKE_CXX_STANDARD 14)

if(WIN32)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:msvcrtd")

endif()

add_executable(TestByteConverterTest ${SRCS})

target_link_libraries(TestByteConverterTest
    libgtest
    libgmock
)

add_test(NAME TestByteConverterTest
         COMMAND TestByteConverterTest)