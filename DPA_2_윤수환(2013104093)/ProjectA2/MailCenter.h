#pragma once
#include "Mail.h"
class MailCenter
{
private:
	int id;
	string cityName;
	int neighborCnt;
	int* neighborIds;

	Mail* recievedMailList[10];
	Mail* localMailList[10];
	Mail*** externalMailList;
public:
	MailCenter();
	~MailCenter();

	string getCityName();
	void setMailCenter(int _id, string _cityName);
	void setNeighborMailCenter(int** router,int midx);
};

