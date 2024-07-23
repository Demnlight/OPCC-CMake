#pragma once

template<typename T>
class ISource {
public:
	virtual void SetSource( int source ) = 0;

	virtual ~ISource( ) noexcept { };

protected:
	T source;
};