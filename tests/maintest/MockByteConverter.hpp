#include "../../src/Converter/IByteConverter.hpp"

#include "gmock/gmock.h"

class MockByteConverter : IByteConverter {
public:
    MOCK_METHOD( void, Process, (), (override) );
    MOCK_METHOD( void, WaitForResults, ( ), ( override ) );
    MOCK_METHOD( int, FromCharArrayToInt, ( char from[ ], std::size_t array_size ), ( override ) );
    MOCK_METHOD( int, GetByteValue, ( int position ), ( override ) );
    MOCK_METHOD( void, FillDataAndType, ( ), ( override ) );

    MOCK_METHOD( int, Result, ( ), ( ) );
    MOCK_METHOD( void, SetSource, ( int source ), ( ) );

};