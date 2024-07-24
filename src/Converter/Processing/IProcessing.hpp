class IProcessing {
public:
	virtual ~IProcessing( ) noexcept { };

	virtual void Process( ) = 0;
};