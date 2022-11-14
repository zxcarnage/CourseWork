#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include "Authorization.h"
#include "Panels.h"
#include "Input.h"
#include "User.h"
#include "Hash.h"
using namespace std;

void SignUpAdmin()
{
    ofstream fout;
    char login[50] = "admin";
    char password[50] = "1235";
    User admin(login, password);
    fout.open("userDataBase.txt", ofstream::app);
    fout.write((char*)&admin, sizeof(User));
}

//ПОЛУЧЕНИЕ ДАННЫХ
void GetData(char login[], char password[])
{
    bool goes = true;
    while (goes)
    {
        try
        {
            CharInput(login, "a login");
            goes = false;
        }
        catch (const exception& ex)
        {
            cout << ex.what() << endl;
        }
    }
    cout << "Enter a password:" << endl;
    int ch = 0;
    int i = 0;

    while (true)
    {
        ch = _getch();
        switch (ch)
        {
        default:
            cout << '*';
            password[i] = (char)ch;
            i++;
            break;
        case 13:
            return;
            break;
        case 27:
            exit(0);
            break;
        case 8:
            cout << '\b' << " " << '\b';
            i--;
            break;
        }
    }
    cout << endl;
}

void SignUp()
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

    fout.open("userDataBase_expected.txt", ofstream::app);
    fout.write((char*)&user, sizeof(User));
    fout.close();
    system("cls");
}

void LogIn()
{
    //Создание необходимых переменных
    ifstream fin;
    Role role;
    User user;
    unsigned int loginSize = 0;
    char login[50];
    char password[50] = { '\0' };
    char salt[50] = { '\0' };
    char hash[50] = { '\0' };
    bool failed = false;

    GetData(login, password); //Получение данных

    fin.open("userDataBase.txt", ifstream::app);
    while (fin.read((char*)&user, sizeof(User))) //Обработка данных из файла
    {
        strcpy(salt, user.GetSalt());
        hashIt(hash, password, salt);
        if (strcmp(user.GetLogin(), login) == 0 && strcmp(user.GetHash(), hash) == 0 && user.GetAccess() != Access::Denied) //Проверка на совпадения
        {
            switch (user.GetRole())
            {
            default:
                cout << endl << "You are successfully logged in!" << endl;
                //Организовать юзер-панель
                break;
            case Role::Admin:
                cout << endl << "Hello admin! Here your Admin panel:" << endl;
                AdminPanel();
                break;
            }
        }
        else failed = true;
    }

    if (failed) cout << "You was banned, or your login or password uncorrect! Try again" << endl;
    fin.close();
    Sleep(3000); //Ожидание чтобы юзер успел прочитать сообщение
    system("cls");
}