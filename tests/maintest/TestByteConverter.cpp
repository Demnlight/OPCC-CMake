#include "TestByteConverter.hpp"
#include "../../src/Converter/ByteConverter.hpp"

void SetBit( int& source, int n, bool one ) {
	if ( one )
		source |= 1 << n;
	else
		source &= ~( 1 << n );
}

TestByteConverterTest::TestByteConverterTest( ) {

}

TestByteConverterTest::~TestByteConverterTest( ) { };

void TestByteConverterTest::SetUp( ) { };

void TestByteConverterTest::TearDown( ) { };

TEST_F( TestByteConverterTest, CheckInAlphabetRange1 ) {
	CByteConverter byteConverter;
	for ( int i = -255; i < 255; i++ ) {
		int temp = i;
		SetBit( temp, 0, 0 );
		SetBit( temp, 1, 0 );

		byteConverter.SetSource( temp );
		int result = byteConverter.Result( );
		EXPECT_TRUE( result == 0 );
	}
}

TEST_F( TestByteConverterTest, CheckInAlphabetRange2 ) {
	CByteConverter byteConverter;
	for ( int i = -255; i < 255; i++ ) {

		int temp = i;
		SetBit( temp, 0, 0 );
		SetBit( temp, 1, 1 );

		byteConverter.SetSource( temp );
		int result = byteConverter.Result( );
		EXPECT_TRUE( ( result >= 0 ) && ( result <= 255 ) );
	}
}

TEST_F( TestByteConverterTest, CheckInAlphabetRange3 ) {
	CByteConverter byteConverter;
	for ( int i = -255; i < 255; i++ ) {

		int temp = i;
		SetBit( temp, 0, 1 );
		SetBit( temp, 1, 0 );

		byteConverter.SetSource( temp );
		int result = byteConverter.Result( ) + 'a';
		EXPECT_TRUE( ( result >= 'a' ) && ( result <= 'z' ) );
	}
}