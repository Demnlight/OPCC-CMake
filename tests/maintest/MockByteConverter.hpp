#include "../../src/Converter/IByteConverter.hpp"

#include "../../src/Converter/ISource.hpp"
#include "../../src/Converter/ISink.hpp"

#include "gmock/gmock.h"

class MockByteConverter : IByteConverter, ISink<int>, ISource<int> {
public:
    MOCK_METHOD( void, Process, (), (override) );
    MOCK_METHOD( void, WaitForResults, ( ), ( override ) );
    MOCK_METHOD( int, WriteValueFromSource, ( ), ( override ) );
    MOCK_METHOD( int, GetByteValue, ( int position ), ( override ) );
    MOCK_METHOD( void, FillDataAndType, ( ), ( override ) );

    MOCK_METHOD( int, Result, ( ), ( ) );
    MOCK_METHOD( void, SetSource, ( int source ), ( ) );

};