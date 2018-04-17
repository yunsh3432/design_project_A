#pragma once
#include "User.h"
#include "MailCenter.h"

#include <iostream>
#include <sstream>
using namespace std;

#define N 12
#define IN 99 
//IN = INTMAX

class User;

class mailDeilivery
{
private:
	User** pointerOfUsers;
	MailCenter* pointerOfMailCenters;
	int** pointerOfRouter;

	int getTotalDistance(int sourceId, int destinationId);
	int getNextMailCenterId(int currentPos, int destinationId);
	int getMailCenterIdByCityName(string cityName);

public:
	mailDeilivery();
	~mailDeilivery();

	bool clientSendMail(User* curUser);
	bool managerSendMail(string cityName);
	bool managerReceiveMail(string cityName);

	void setDBPointers(User** pUser, MailCenter* pMailCenter, int** pRouter)
	{ 
		pointerOfUsers = pUser; 
		pointerOfMailCenters = pMailCenter;
		pointerOfRouter = pRouter;
	}
};

