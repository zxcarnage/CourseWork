#pragma once
#include<iostream>
/*TODO
* 1.Проработать связи между классами
* 2.Хотя бы 1 friend функция (может быть и не здесь)
* 3.Перегрузка операторов (каких либо)
* 4.Создать и использовать SmartPointer
* 5.Использование шаблонов(Скорее всего это все будет в SmartPointer)
*/

namespace InheritanceClasses
{
	class Human
	{
	protected:
		int _age;
		bool _solvensy;
		char _name[25];
		char _surname[25];
	public:
		Human();
	};

	class Document
	{
	protected:
		char _signDate[12];
	public:
		void virtual Prepare() = 0;
		void virtual Show() = 0;
		void virtual Write() = 0;
		void virtual Read() = 0;
	};
}
enum class InsuranceObject
{
	Life,
	Car,
	House
};

class Client : public InheritanceClasses::Human
{
	InsuranceObject _objectForInsure;
public:
	Client();
};


class Insurance: public InheritanceClasses::Document
{
	Client _client;
	int _insurancePrice;
public:
	Insurance();
};

