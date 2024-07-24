#pragma once
#include "ByteReader/IByteReader.hpp"
#include "Processing/IThreadedProcessing.hpp"
#include "Sink/ISink.hpp"
#include "SourceReader/ISource.hpp"

#include "IConverter.hpp"

class IByteConverter : public ISink<int>, public ISource<int>, IByteReader, IConverter, IThreadedProcessing {
protected:
	virtual ~IByteConverter( ) noexcept { };

	virtual void FillDataAndType( ) = 0;
};