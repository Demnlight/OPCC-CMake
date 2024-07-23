#include "TestByteConverter.hpp"
#include "../../src/Converter/ByteConverter.hpp"

#pragma comment(lib, "gtest_main.lib")
#pragma comment(lib, "gmock_main.lib")

TestByteConverterTest::TestByteConverterTest() {

}

TestByteConverterTest::~TestByteConverterTest() {};

void TestByteConverterTest::SetUp() {};

void TestByteConverterTest::TearDown() {};

TEST_F(TestByteConverterTest, CheckInAlphabetRange) {
    CByteConverter byteConverter;
    for (int i = 0b0000'0000; i < 0b1111'1111; i++) {
        byteConverter.SetSource( 0b0000'1101 );
	    int result = byteConverter.Result( );
        EXPECT_TRUE((result >= 'a') && (result <= 'z'));
    }
}