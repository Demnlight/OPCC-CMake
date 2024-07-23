#include "../../src/Converter/IByteConverter.hpp"
#include "gmock/gmock.h"

class MockByteConverter : IByteConverter {
public:
    MOCK_METHOD( void, Process, (), (override) );
    MOCK_METHOD( void, WaitForResults, ( ), ( override ) );
    MOCK_METHOD( int, WriteValueFromSource, ( ), ( override ) );
    MOCK_METHOD( int, GetByteValue, ( int position ), ( override ) );
    MOCK_METHOD( void, FillDataAndType, ( ), ( override ) );
};