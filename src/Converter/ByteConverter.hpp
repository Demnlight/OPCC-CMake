#pragma once

#include "ISink.hpp"
#include "ISource.hpp"
#include "IByteConverter.hpp"

#include <thread>
#include <iostream>

namespace CByteConverterConsts {
	//Размерные контстанты, которые отвечают за количество битов числа, выделенных под обработку нужных нам данных.
	static const int TypeSize = 2;
	static const int DataSize = 6;
}

/*
	Родители
		ISource - 
			интерфейс, который объявляет абстрактную функцию,
		 	которая в наследниках отвечает за считывания необходимых данных.
		ISink -
			интерфейс, который объявляет абстрактную функцию,
		 	которая в наследниках отвечает за вывод данных.
		Оба интерфейса являются параметрическими.
	
	Основной класс, который отвечает за создание отдельного потока при создании объекта, так же его контроль и освобождение.
*/
class CByteConverter : ISource<int>, ISink<int>, IByteConverter {
public:
	//выделяем отдельный поток для обработки наших данных
	CByteConverter( ) {
		local_thread = std::thread( &CByteConverter::Process, this );
	}
	
	~CByteConverter( ) noexcept {
		if ( !ThreadReleased )
			std::cerr << "~CByteConverter() Thread not released\n";
	}

	void SetSource( int source ) override;
	int Result( ) override;

	void Process( );
private:
	void WaitForResults( );
	int WriteValueFromSource( );
	int GetByteValue( int position );
	void FillDataAndType( );

	std::thread local_thread;

	char chType[ CByteConverterConsts::TypeSize ]{ };
	char chData[ CByteConverterConsts::DataSize ]{ };

	bool ThreadReleased = false;
};