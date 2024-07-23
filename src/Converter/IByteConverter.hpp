#pragma once

class IByteConverter {
protected:
	virtual ~IByteConverter( ) noexcept { };

    virtual void Process( ) = 0;
	virtual void WaitForResults( ) = 0;
	virtual int WriteValueFromSource( ) = 0;
	virtual int GetByteValue( int position ) = 0;
	virtual void FillDataAndType( ) = 0;
};