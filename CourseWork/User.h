#pragma once
#include <iostream>
//оепевхякемхе днярсою
enum class Access
{
	Allowed,
	OnReview,
	Denied
};

//оепевхякемхе пнкеи
enum class Role
{
	Admin,
	User
};

class User
{
	char _login[50];
	char _hashPass[50];
	char _salt[50];
	Role _role;
	Role _expectedRole;
	Access _access;
public:
	User();
	User(char _login[], char _password[], Role _expectedRole, char salt[]);
	User(char _login[], char _password[]);
	char* GetLogin();
	char* GetSalt();
	char* GetHash();
	Role GetRole();
	Access GetAccess();
};