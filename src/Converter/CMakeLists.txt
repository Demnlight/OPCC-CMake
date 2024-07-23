set(libConverterFiles
    ByteConverter.hpp
    ISink.hpp
    ISource.hpp
    IByteConverter.hpp
    ByteConverter.cpp
)

add_library(libConverter STATIC ${libConverterFiles})

target_include_directories(libConverter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )