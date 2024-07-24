#pragma once

template<typename T>
class ISink {
public:
	virtual T Result( ) = 0;

	virtual ~ISink( ) noexcept { };

protected:
	T m_Result;
};