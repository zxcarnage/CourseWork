#pragma once
#include<iostream>
/*TODO
* 1.����������� ����� ����� ��������
* 2.���� �� 1 friend ������� (����� ���� � �� �����)
* 3.���������� ���������� (����� ����)
* 4.������� � ������������ SmartPointer
* 5.������������� ��������(������ ����� ��� ��� ����� � SmartPointer)
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

