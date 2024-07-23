#include "ByteConverter.hpp"

#include <iostream>
#include <cstddef>

using namespace CByteConverterConsts;

void CByteConverter::Process( ) {
	this->FillDataAndType( );

	//�������.����� 
	if ( chType[ 0 ] == 0 && chType[ 1 ] == 0 ) {
		this->result = 0;
	}
	//�������� �����
	else if ( chType[ 0 ] == 1 && chType[ 1 ] == 0 ) {
		this->result = WriteValueFromSource( );
	}
	//����� ���.���
	else if ( chType[ 0 ] == 0 && chType[ 1 ] == 1 ) {
		int value = WriteValueFromSource( );
		this->result = value + 97;
	}
}

void CByteConverter::WaitForResults( ) {
	if ( this->local_thread.joinable( ) )
		this->local_thread.join( );
}

int CByteConverter::GetByteValue( int position ) {
	return ( this->source >> position ) & 1u;
}

void CByteConverter::FillDataAndType( ) {
	for ( std::size_t i = 0; i < TypeSize; ++i )
		chType[ i ] = GetByteValue( i );

	for ( std::size_t i = 0; i < DataSize; i++ )
		chData[ i ] = GetByteValue( i + TypeSize );
}

int CByteConverter::WriteValueFromSource( ) {
	int result = 0;

	for ( std::size_t i = 0; i < DataSize; ++i ) {
		if ( chData[ i ] == 1 )
			result |= ( 1 << i );
		else
			result &= ~( 1 << i );
	}

	return result;
}

void CByteConverter::SetSource( int source ) {
	this->source = source;
}

int CByteConverter::Result( ) {
	this->WaitForResults( );
	return this->result;
}