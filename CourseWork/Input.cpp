#include "Input.h"

void AgeInput(float tempData)
{
	if (tempData < 0 || tempData > 120)
		throw InputException("Incorrect age amount", tempData);
}

void NumberInput(float tempData)
{
	if (tempData < 0 || tempData > INT_MAX)
		throw InputException("Incorrect data", tempData);
}

void AnswerInput(float tempData, int highBorder)
{
	NumberInput(tempData);
	if ((int)tempData != tempData)
		throw InputException("Incorrect type of answer, try int num", tempData);
	else if ((int)tempData > highBorder)
		throw InputException("Answer higher then then higher border");
}

void Input(float* data, string dataName, InputType inputType, int higherBorder)
{
	float tempData;
	cout << "Enter " << dataName << endl;
	cin >> tempData;
	if (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw exception("Incorrect data type input!");
	}
	switch (inputType)
	{
	case Number:
		NumberInput(tempData);
		*data = tempData;
		break;
	case Age:
		AgeInput(tempData);
		*data = tempData;
		break;
	case Answer:
		AnswerInput(tempData, higherBorder);
		*data = tempData;
		break;
	default:
		throw exception("Incorrect InputType!!!");
		break;
	}
}

void CharInput(char data[], string dataName)
{
	char tempData[20];
	cout << "Enter " << dataName << endl;
	memset(tempData, 0, sizeof tempData);
	memset(data, 0, sizeof data);
	cin.get();
	cin.getline(tempData, 20);
	strcpy(data,tempData);
}

void StringInput(string* data, string dataName)
{
	string tempData;
	cout << "Enter " << dataName << endl;
	cin >> tempData;
	*data = tempData;
}

float InputException::GetErrorData()
{
	return _errorData;
}