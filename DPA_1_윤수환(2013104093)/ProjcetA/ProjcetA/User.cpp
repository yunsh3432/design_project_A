#include"User.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


int User::getId()
{
	return id;
}

int User::getAccountNumber()
{
	return accountNumber;
}

string User::getName()
{
	return name;
}

string User::getPW()
{
	return password;
}

int User::getBalance()
{
	return balance;
}

int User::getCreditRating()
{
	return creditRating;
}

int User::PlusBalance(int amount)
{
	balance = balance+amount;
	return balance;
}

int User::subBalance(int amount)
{
	balance = balance - amount;
	return balance;
}

void User::subcreditRating()
{
	creditRating++;
	if(creditRating > 10)
	{
		creditRating = 10;
	}
}
void User::printUserInfo()
{
	cout << "사용자 이름: " << name << endl;
	cout << "계좌번호   : " << accountNumber << endl;
	cout << "잔액       : " << balance << endl;
	cout << "신용등급   : " << creditRating << endl;
}

bool User::getTrasCache(transaction* transDB)
{
	int count = 0;
	int i = 99;
	while (count != 100)
	{
		if (getId() == transDB->getFromId() || getId() == transDB->getToId())
		{
			transCache[i] = &transDB[count];
			i--;
			count++;
			if (i >= 5)
			{
				return true;
			}

		}
		else
			count++;
	}
}

void User::setUser(int _id, string _password, string _name, int _accountnumber,int _balance, int _creditRating)
{
	id = _id;
	password = _password;
	name= _name;
	accountNumber = _accountnumber;
	balance = _balance;
	creditRating = _creditRating;
}

void User::printtransCache(int count)
{
	for(int i = 0 ; i < count ; i++ )
		cout<< "처리됨: " << transCache[i]->getFromId() << " -> " <<  transCache[i]->getToId() << " -> " <<  transCache[i]->getAmount() << endl;
}