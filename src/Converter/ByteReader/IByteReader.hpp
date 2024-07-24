class IByteReader {
public:
	virtual ~IByteReader( ) noexcept { };

	virtual int GetByteValue( int position ) = 0;
};