#include "Converter/ByteConverter.hpp"
#include <iostream>

int main( ) {
	CByteConverter byteConverter;
	byteConverter.SetSource( 50 ); //0b0011'0010
	int m_Result = byteConverter.Result( ); //m_Result = 109; 'm'

	return 0;
}