#define _CRT_SECURE_NO_WARNINGS
#include "User.h"
#include "Hash.h"

//–≈¿À»«¿÷»ﬂ √≈““≈–Œ¬ »  ŒÕ—“–” “Œ–Œ¬  À¿——¿ ﬁ«≈–
User::User()
{
	memset(_login, '\0', sizeof(_login));
	memset(_hashPass, '\0', sizeof(_hashPass));
	memset(_salt, '\0', sizeof(_salt));
	_expectedRole = Role::User;
	_role = Role::Admin;
	_access = Access::OnReview;
}

User::User(char login[], char password[], Role expectedRole, char salt[])
{
	strcpy(_login, login);
	hashIt(_hashPass, password, salt);
	strcpy(_salt, salt);

	_expectedRole = expectedRole;
	_role = (enum::Role)1;
	_access = Access::OnReview;
}

User::User(char login[], char password[])
{
	strcpy(_login, login);
	hashIt(_hashPass, password, login);
	strcpy(_salt, login);
	_role = Role::Admin;
	_expectedRole = Role::Admin;
	_access = Access::Allowed;
}

char* User::GetLogin() { return _login; }
char* User::GetSalt() { return _salt; }
char* User::GetHash() { return _hashPass; }
Role User::GetRole() { return _role; }
Access User::GetAccess() { return _access; }