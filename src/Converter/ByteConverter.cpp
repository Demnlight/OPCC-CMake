#include "ByteConverter.hpp"

#include <iostream>
#include <cstddef>

using namespace CByteConverterConsts;

void CByteConverter::Process( ) {
	this->FillDataAndType( );

	/*
	@TODO:
	Pattern design Strategy
	*/

	if ( aType[ 0 ] == 0 && aType[ 1 ] == 0 ) {
		this->m_Result = 0;
	}
	else if ( aType[ 0 ] == 1 && aType[ 1 ] == 0 ) {
		this->m_Result = this->FromCharArrayToInt( aData, DATA_SIZE );
	}
	else if ( aType[ 0 ] == 0 && aType[ 1 ] == 1 ) {
		int nConvertedResult = this->FromCharArrayToInt( aData, DATA_SIZE );
		this->m_Result = nConvertedResult + 'a';
	}
}

void CByteConverter::WaitForResults( ) {
	if ( this->thLocalThread.joinable( ) ) {
		this->thLocalThread.join( );
		this->bThreadReleased = true;
	}
}

int CByteConverter::GetByteValue( int position ) {
	return ( this->m_Source >> position ) & 1u;
}

void CByteConverter::FillDataAndType( ) {
	for ( std::size_t i = 0; i < TYPE_SIZE; ++i )
		aType[ i ] = GetByteValue( i );

	for ( std::size_t i = 0; i < DATA_SIZE; i++ )
		aData[ i ] = GetByteValue( i + TYPE_SIZE );
}

int CByteConverter::FromCharArrayToInt( char from[ ], std::size_t array_size ) {
	int nResult = 0;

	for ( std::size_t i = 0; i < array_size; ++i ) {
		if ( from[ i ] == 1 )
			nResult |= ( 1 << i );
		else
			nResult &= ~( 1 << i );
	}

	return nResult;
}

void CByteConverter::SetSource( int m_Source ) {
	this->m_Source = m_Source;
}

int CByteConverter::Result( ) {
	this->WaitForResults( );
	return this->m_Result;
}