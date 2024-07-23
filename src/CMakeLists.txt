file(GLOB_RECURSE SOURCE_FILES Converter/*.cpp)
file(GLOB_RECURSE HEADER_FILES Converter/*.hpp)
add_executable(OPCC Main.cpp ${SOURCE_FILES} ${HEADER_FILES})

install(TARGETS OPCC DESTINATION bin)