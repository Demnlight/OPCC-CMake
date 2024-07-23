cmake_minimum_required(VERSION 3.26.4)
project(OPCC)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES src/*.hpp)
add_executable(OPCC Main.cpp ${SOURCE_FILES} ${HEADER_FILES})

if(APPLE)
    set_target_properties(${CMAKE_PROJECT_NAME}
    PROPERTIES # https://cmake.org/cmake/help/latest/prop_tgt/MACOSX_BUNDLE_INFO_PLIST.html
        MACOSX_BUNDLE_BUNDLE_NAME "${CMAKE_PROJECT_NAME}"
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.our-company"
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION} 
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION}
    )
endif()

target_compile_features(OPCC PRIVATE cxx_std_17)
target_include_directories(OPCC PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)