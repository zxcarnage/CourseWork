#include "InsuranceCompany.h"
using namespace InheritanceClasses;
Human::Human()
{
	_age = 0;
	_solvensy = true;
	memset(_name, '\0', 25);
	memset(_surname, '\0', 25);
}


Client::Client()
{
	Human();
	_objectForInsure = InsuranceObject::Life;
}


Insurance::Insurance()
{
	_insurancePrice = 0;
	_client = Client();
	memset(_signDate, '\0', 12);
}