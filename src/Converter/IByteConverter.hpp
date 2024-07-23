#pragma once

class IByteConverter {
    virtual void Process( ) = 0;

private:
	virtual void WaitForResults( ) = 0;
	virtual int WriteValueFromSource( ) = 0;
	virtual int GetByteValue( int position ) = 0;
	virtual void FillDataAndType( ) = 0;
};