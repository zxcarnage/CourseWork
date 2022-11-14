#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Hash.h"

//Преобразование контрольной суммы в число равное Букве или Цифре
int receivingExistCode(int charNum)
{
	charNum += 256;
	while (!((charNum <= 57 && charNum >= 48) || (charNum <= 90 && charNum >= 65) || (charNum <= 122 && charNum >= 97)))
	{
		if (charNum < 48) charNum += 24;
		else charNum -= 47;
	}
	return charNum;
}

void hashIt(char hashPassword[], char password[], char salt[])
{
	char hash[50] = { '\0' };
	unsigned int mply;
	unsigned int div;
	unsigned int rotateLeft;
	unsigned int passwordSize;


	strcat(password, salt);
	passwordSize = strlen(password);

	if (passwordSize % 2 != 0) strcat(password, "s");

	for (unsigned int i = 0, j = 0; i < passwordSize; i += 2)
	{

		mply = password[i] * password[i + 1];
		div = password[i] / password[i + 1];
		rotateLeft = (mply + div) << 4; //Некоторые операции для получения контрольной суммы (КС)

		hash[j] = receivingExistCode(rotateLeft); //Создание непосредственно хеша
		j++;
	}
	strcpy(hashPassword, hash);
}