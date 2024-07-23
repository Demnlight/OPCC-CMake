#pragma once

#include "ISink.hpp"
#include "ISource.hpp"
#include "IByteConverter.hpp"

#include <thread>
#include <iostream>

//Размерные контстанты, которые отвечают за количество битов числа, выделенных под обработку нужных нам данных.
namespace CByteConverterConsts {
	static const int TypeSize = 2;
	static const int DataSize = 6;
}

/*
	Родители
		ISource<typename> - 
			интерфейс, который объявляет абстрактную функцию,
		 	которая в наследниках отвечает за считывания необходимых данных.
		ISink<typename> -
			интерфейс, который объявляет абстрактную функцию,
		 	которая в наследниках отвечает за вывод данных.

	Основной класс, который отвечает за создание отдельного потока при создании объекта, так же его контроль и освобождение.
*/
class CByteConverter : ISource<int>, ISink<int>, IByteConverter {
public:

	//выделяем отдельный поток для обработки наших данных
	CByteConverter( ) {
		local_thread = std::thread( &CByteConverter::Process, this );
	}

	/*
	Бросать исключение в деструкторе опасно, поэтому noexcept.
	Так же стоит проверить освободили ли мы поток, выделенный ранее. 
	*/
	~CByteConverter( ) noexcept {
		if ( !ThreadReleased ) {
			std::cerr << "~CByteConverter() Thread not released\n";

			if ( this->local_thread.joinable( ) ) {
				this->local_thread.join( );
				this->ThreadReleased = true;
			}
			else
				std::cerr << "~CByteConverter() cant release thread\n";
		}
	}

	/*
	ISource::SetSource override
		@param int source - наше входное значение, которое будет использоваться далее.
		устанавливает значение приватного поля ISource::source.
	*/
	void SetSource( int source ) override;

	/*
	ISink::Result override
		@return Возвращает результат конвертации.
	*/
	int Result( ) override;

	/*
	Функция для конвертации наших данных в выделенном потоке.
	*/
	void Process( );
private:
	/*
	Функция для конвертации наших данных в выделенном потоке.
	*/
	void WaitForResults( );
	/*
	Функция, которая отвечает за конвертацию наших битов в число.
	@return возвращает значения типа int, которое является результатом конвертации chData -> int.
	*/
	int WriteValueFromSource( );
	/*
	@return Возвращает значения бита {position}, в диапазоне 0-1.
	*/
	int GetByteValue( int position );
	/*
	Вспомогательная функция, которая отвечает за заполнение массивов chType и chData.
	*/
	void FillDataAndType( );

	std::thread local_thread;

	char chType[ CByteConverterConsts::TypeSize ]{ };
	char chData[ CByteConverterConsts::DataSize ]{ };

	//Переменная, которая становиться true, если поток был освобожден
	bool ThreadReleased = false;
};