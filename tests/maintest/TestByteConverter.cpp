#include "TestByteConverter.hpp"

using ::testing::Return;

void SetBit( int& source, int n, bool one ) {
	if ( one )
		source |= 1 << n;
	else
		source &= ~( 1 << n );
}

TestByteConverterTest::TestByteConverterTest( ) {
}

TestByteConverterTest::~TestByteConverterTest( ) {
};

void TestByteConverterTest::SetUp( ) { };

void TestByteConverterTest::TearDown( ) { };

TEST_F( TestByteConverterTest, CheckInAlphabetRange1 ) {
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
	for ( int i = -255; i < 255; i++ ) {
		int temp = i;
		SetBit( temp, 0, 1 );
		SetBit( temp, 1, 0 );

		byteConverter.SetSource( temp );
		int result = byteConverter.Result( ) + 'a';
		EXPECT_TRUE( ( result >= 'a' ) && ( result <= 'z' ) );
	}
}

TEST_F( TestByteConverterTest, CheckGetBitValueOne ) {
	for ( int i = 0; i < 8; i++ ) {
		mockByteConverter.SetSource( 0b1111'1111 );

		EXPECT_CALL( mockByteConverter, GetByteValue( i ) ).WillOnce( Return( 1 ) );
		EXPECT_EQ( mockByteConverter.GetByteValue( i ), 1 );
	}
}

TEST_F( TestByteConverterTest, CheckGetBitValueZero ) {
	for ( int i = 0; i < 8; i++ ) {
		mockByteConverter.SetSource( 0b0000'0000 );

		EXPECT_CALL( mockByteConverter, GetByteValue( i ) ).WillOnce( Return( 0 ) );
		EXPECT_EQ( mockByteConverter.GetByteValue( i ), 0 );
	}
}

TEST_F( TestByteConverterTest, CheckGetBitValueZeroOne ) {
	for ( int i = 0; i < 8; i++ ) {
		mockByteConverter.SetSource( 0b0000'1111 );
		if ( i < 4 ) {
			EXPECT_CALL( mockByteConverter, GetByteValue( i ) ).WillOnce( Return( 1 ) );
			EXPECT_EQ( mockByteConverter.GetByteValue( i ), 1 );
		} else {
			EXPECT_CALL( mockByteConverter, GetByteValue( i ) ).WillOnce( Return( 0 ) );
			EXPECT_EQ( mockByteConverter.GetByteValue( i ), 0 );
		}
	}
}