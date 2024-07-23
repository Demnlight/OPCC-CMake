#include "src/ByteConverter.hpp"
#include <iostream>

int main( ) {
	CByteConverter byteConverter;
	byteConverter.SetSource( 0b0000'1101 );
	std::cout << byteConverter.Result( ) << std::endl;
	system( "pause" );
	return 0;
}