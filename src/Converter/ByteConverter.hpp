#pragma once

#include "ISink.hpp"
#include "ISource.hpp"

#include <thread>

namespace CByteConverterConsts {
	static const int TypeSize = 2;
	static const int DataSize = 6;
}
class CByteConverter : ISource<int>, ISink<int> {
public:

	CByteConverter( ) {
		local_thread = std::thread( &CByteConverter::Process, this );
	}

	~CByteConverter( ) noexcept {
		
	}

	void Process( );
	
	void SetSource( int source ) override;

	int Result( ) override;

private:
	void WaitForResults( );
	int WriteValueFromSource( );
	int GetByteValue( int position );
	void FillDataAndType( );

	std::thread local_thread;

	char chType[ CByteConverterConsts::TypeSize ]{ };
	char chData[ CByteConverterConsts::DataSize ]{ };
};