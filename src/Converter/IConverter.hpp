#include <cstddef> //std::size_t

class IConverter {
public:
	virtual ~IConverter( ) noexcept { };

	virtual int FromCharArrayToInt( char from[], std::size_t array_size ) = 0;
};