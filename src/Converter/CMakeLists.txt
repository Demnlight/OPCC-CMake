set(libConverterFiles
    Processing/IProcessing.hpp
    Processing/IThreadedProcessing.hpp
    ByteReader/IByteReader.hpp
    Sink/ISink.hpp
    SourceReader/ISource.hpp
    IConverter.hpp
    IByteConverter.hpp
    ByteConverter.hpp
    ByteConverter.cpp
)

add_library(libConverter STATIC ${libConverterFiles})

target_include_directories(libConverter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )