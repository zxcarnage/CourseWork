#include <iostream>
#include <fstream>
#include "Panels.h"
#include "User.h"
#include "Authorization.h"
#include "PanelRealization.h"
#include "Input.h"
using namespace std;

void AdminPanel()
{
	while (true)
	{
		float option;
		cout << "==========================" << endl;
		cout << "Choose the option:" << endl;
		cout << "1.Show all accounts" << endl;
		cout << "2.Add a new account" << endl;
		cout << "3.Delete an account" << endl;
		cout << "4.Accept/Deny an account" << endl;
		cout << "Or any other button to end a programm" << endl;
		cout << "==========================" << endl;

		try
		{
			Input(&option, "Answer", InputType(Answer), 4);
			switch ((int)option)
			{
			case 1:
				system("cls");
				ShowAllAccounts();
				break;
			case 2:
				system("cls");
				AddAccount();
				break;
			case 3:
				system("cls");
				DeleteAccount();
				break;
			case 4:
				system("cls");
				ChangeAccess();
				break;
			}
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
}

void UserPanel()
{
	cout << "You are user" << endl;
}