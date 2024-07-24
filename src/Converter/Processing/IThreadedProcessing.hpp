#include "IProcessing.hpp"

class IThreadedProcessing : IProcessing {
public:
	virtual ~IThreadedProcessing( ) noexcept { };

	virtual void WaitForResults( ) = 0;
};