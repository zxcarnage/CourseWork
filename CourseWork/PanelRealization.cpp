#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <conio.h>
#include "PanelRealization.h"
#include "table_printer.h"
#include "User.h"
#include "Input.h"
#include "Authorization.h"
using namespace std;

void ShowAllAccounts()
{
	ifstream fin;
	User user;
	bprinter::TablePrinter tp(&cout);
	int counter = 0;
	fin.open("userDataBase.txt", ifstream::app);
	tp.AddColumn("Number", 7);
	tp.AddColumn("Login", 10);
	tp.PrintHeader();
	while (fin.read((char*)&user, sizeof(User)))
	{
		counter++;
		tp << counter << user.GetLogin();
	}
	tp.PrintFooter();
	fin.close();
}

void DeleteAccount()
{
	ifstream fin;
	ofstream fout;
	User user;
	char username[50];
	try
	{
		CharInput(username, "a username of user, which you want to delete");
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
		return;
	}
	fin.open("userDataBase.txt", ifstream::app);
	fout.open("userDataBase_copy.txt", ofstream::app);
	while (fin.read((char*)&user, sizeof(User)))
	{
		if (user.GetRole() == Role::Admin && strcmp(username, user.GetLogin()) == 0)
		{
			cout << "You cannot delete an admin account!" << endl;
			fin.close();
			fout.close();
			return;
		}
		if (strcmp(user.GetLogin(), username) != 0)
			fout.write((char*)&user, sizeof(User));
	}
	ofstream("userDataBase.txt");
	fin.close();
	fout.close();
	fin.open("userDataBase_copy.txt", ifstream::app);
	fout.open("userDataBase.txt", ofstream::app);
	while (fin.read((char*)&user, sizeof(User)))
	{
		fout.write((char*)&user, sizeof(User));
	}
	ofstream("userDataBase_copy.txt");
	fin.close();
	fout.close();
}

void ChangeAccess()
{
	ifstream fin;
	ofstream fout;
	bprinter::TablePrinter tp(&cout);
	User user;
	bool success = false;
	int counter = 0;
	fin.open("userDataBase_expected.txt", ifstream::app);
	fout.open("userDataBase.txt", ofstream::app);
	tp.AddColumn("Number", 7);
	tp.AddColumn("Login", 10);
	tp.AddColumn("Expected Role", 20);
	tp.PrintHeader();
	while (fin.read((char*)&user, sizeof(User)))
	{
		float answer = 0;
		counter++;
		tp << counter << user.GetLogin();
		switch (user.GetRole())
		{
		case Role::User:
			tp << "User";
			break;
		case Role::Admin:
			tp << "Admin";
			break;
		}
		cout << "Do you want to give an access to this account, or deny?" << endl;
		cout << "1.Give Access" << endl;
		cout << "2.Deny" << endl;
		try
		{
			Input(&answer, "Answer", InputType(Answer), 2);
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
			return;
		}
		if (answer == 1) 
			fout.write((char*)&user, sizeof(User));
		success = true;
	}
	if (!success) 
		cout << "There is no new waited users" << endl;
	ofstream("userDataBase_expected.txt");
	fin.close();
	fout.close();
}

void AddAccount()
{
	unsigned int loginSize = 0;
	bool whileTemp = true;
	char login[50];
	char password[50] = { '\0' };
	char salt[50];
	ofstream fout;
	Role role;
	float intedRole;

	GetData(login, password);

	cout << "Which role do you want?\n1.Admin\n2.User" << endl;
	while (whileTemp)
	{
		try
		{
			Input(&intedRole, "", InputType(Answer), 2);
			whileTemp = false;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
	role = (enum Role)(intedRole - 1);

	strcpy(salt, login); // Создание уникальной соли
	User user(login, password, role, salt);

	fout.open("userDataBase.txt", ofstream::app);
	fout.write((char*)&user, sizeof(User));
	fout.close();
	system("cls");
}