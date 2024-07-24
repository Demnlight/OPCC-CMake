#pragma once

#include "IByteConverter.hpp"

#include <thread>
#include <iostream>

//Размерные контстанты, которые отвечают за количество битов числа, выделенных под обработку нужных нам данных.
namespace CByteConverterConsts {
	static const int TYPE_SIZE = 2;
	static const int DATA_SIZE = 6;
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
class CByteConverter : IByteConverter {
public:

	//выделяем отдельный поток для обработки наших данных
	CByteConverter( ) {
		thLocalThread = std::thread( &CByteConverter::Process, this );
	}

	/*
	Бросать исключение в деструкторе опасно, поэтому noexcept.
	Так же стоит проверить освободили ли мы поток, выделенный ранее. 
	*/
	~CByteConverter( ) noexcept {
		if ( !bThreadReleased ) {
			std::cerr << "~CByteConverter() Thread not released\n";

			if ( this->thLocalThread.joinable( ) ) {
				this->thLocalThread.join( );
				this->bThreadReleased = true;
			}
			else
				std::cerr << "~CByteConverter() cant release thread\n";
		}
	}

	/*
	ISource::SetSource override
		@param int m_Source - наше входное значение, которое будет использоваться далее.
		устанавливает значение приватного поля ISource::m_Source.
	*/
	void SetSource( int m_Source ) override;

	/*
	ISink::Result override
		@return Возвращает результат конвертации.
	*/
	int Result( ) override;

	/*
	Функция для конвертации наших данных в выделенном потоке.
	*/
	void Process( ) override;
private:
	/*
	Функция, которая дожидается результата конвертации. Так же проверяет thread::joinable и освобождает поток если это возможно. 
	*/
	void WaitForResults( ) override;

	/*
	Функция, которая отвечает за конвертацию наших битов в число.
	@return возвращает значения типа int, которое является результатом конвертации aData -> int.
	*/
	int FromCharArrayToInt( char from[], std::size_t array_size ) override;

	/*
	@return Возвращает значения бита {position}, в диапазоне 0-1.
	*/
	int GetByteValue( int position ) override;

	/*
	Вспомогательная функция, которая отвечает за заполнение массивов aType и aData.
	*/
	void FillDataAndType( ) override;

	/*
	отдельный поток для обработки {Process}
	Создается в конструкторе.
	Освобождается в методе WaitForResults или деструкторе.
	Меняет значение CByteConverter::bThreadReleased
	*/
	std::thread thLocalThread;

	//Массив битов, отвечающих за тип обработки.
	char aType[ CByteConverterConsts::TYPE_SIZE ];

	//Массив битов, отвечающих за исходные данные.
	char aData[ CByteConverterConsts::DATA_SIZE ];

	//Переменная, которая становиться true, если поток был освобожден
	bool bThreadReleased = false;
};