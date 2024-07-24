#pragma once

template<typename T>
class ISource {
public:
	virtual void SetSource( int m_Source ) = 0;

	virtual ~ISource( ) noexcept { };

protected:
	T m_Source;
};