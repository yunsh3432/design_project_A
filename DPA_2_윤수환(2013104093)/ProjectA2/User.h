#pragma once
#include <string>
#include "mailDeilivery.h"
#include "Mail.h"
using namespace std;

class mailDeilivery;

class User
{
private:
	int userType;
	string id;
	string password;
public:
	User();
	~User();
	void setUserType(int _userType);
	void setid(string _id);
	void setPW(string _password);
	int getUserType();
	string getId();
	string getPW();
	virtual bool send(mailDeilivery& md) = 0;
	virtual bool receive(mailDeilivery& md) = 0;
};

class Client : public User
{
private:
	string name;
	string address;

	Mail* sentMailList[10];
	Mail* reciedvedMailList[10];

public:
	Client();
	~Client();
	void setname(string _name);
	void setaddress(string _address);
	string getName();
	string getaddress();
	Mail* GetsentMailList();
	Mail* GetrecivedMailList();

	virtual bool send(mailDeilivery& md);
	virtual bool receive(mailDeilivery& md);	
};

class Manager : public User
{
public:
	Manager();
	~Manager();

	void setManager(int _userType,string _id,string _password);

	virtual bool send(mailDeilivery& md);
	virtual bool receive(mailDeilivery& md);
	
private:
	string currentCityName;
};

