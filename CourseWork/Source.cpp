#include <iostream>
#include "InsuranceCompany.h"
#include "Authorization.h"
#include "User.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	while (true)
	{
		int answer = 0;
		cout << "What do you want to do?" << endl;
		cout << "1.Sing up" << endl;
		cout << "2.Log in" << endl;
		cout << "Or choose any other button to exit" << endl;
		cin >> answer;
		switch (answer)
		{
		case 1:
			system("cls");
			SignUp();
			break;
		case 2:
			system("cls");
			LogIn();
			break;
		default:
			return 0;
			break;
		}
	}
	return 0;
}