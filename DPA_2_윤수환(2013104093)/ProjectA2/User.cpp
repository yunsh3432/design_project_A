#include<iostream>
#include"User.h"
#include<string>

using namespace std;


//User

User::User()
{
	userType = -1;
	id = "";
	password= "";
}

User::~User()
{

}
string User::getId()
{
	return id;
}

string User::getPW()
{
	return password;
}

int User::getUserType()
{
	return userType;
}

void User::setid(string _id)
{
	id = _id;
}

void User::setPW(string _password)
{
	password = _password;
}

void User::setUserType(int _userType)
{
	userType = _userType;
}

//Client

Client::Client()
{
	name = "";
	address = "";
}


void Client::setname(string _name)
{
	name = _name;
}

void Client::setaddress(string _address)
{
	address = _address;
}

string Client::getName()
{
	return name;
}

string Client::getaddress()
{
	return address;
}

Mail* Client::GetsentMailList()
{
	return *sentMailList;
}

Mail* Client::GetrecivedMailList()
{
	return *reciedvedMailList;
}

bool Client::send(mailDeilivery& md)
{
	return 1;
}

bool Client::receive(mailDeilivery& md)
{
	return 1;
}

bool Client::send(mailDeilivery& md)
{
	md.clientSendMail(this);
	return 0;
}
//Manager

Manager::Manager()
{
	currentCityName = "";
}

void Manager::setManager(int _userType,string _id,string _password)
{
	setUserType(_userType);
	setid(_id);
	setPW(_password);
}

bool Manager::send(mailDeilivery& md)
{
	md.managerSendMail();
	return 0;
}

bool Manager::receive(mailDeilivery& md)
{
	md.managerReceiveMail();
	return 0;
}