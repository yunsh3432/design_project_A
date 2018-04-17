#pragma once
#include <fstream>
#include <string>
using namespace std;

#include "User.h"
#include "Mail.h"
#include "MailCenter.h"
#include "mailDeilivery.h"

class App
{
private:
	User* users[36];
	MailCenter mailCenters[12];
	int** router;

	User* loginedUser;
	mailDeilivery md;

private:
	bool load_files();

	void login();
	void logout();

	void printClientMenu();	
	void printManagerMenu();
public:
	App();
	~App();

	void run();
};

