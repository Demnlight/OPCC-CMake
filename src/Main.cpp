#include "Converter/ByteConverter.hpp"
#include <iostream>

int main( ) {
	CByteConverter byteConverter;
	byteConverter.SetSource( 0b0000'0000 );
	std::cout << byteConverter.Result( ) << std::endl;

	return 0;
}