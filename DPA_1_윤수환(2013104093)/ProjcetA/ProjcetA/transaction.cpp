#include"transaction.h"
#include<iostream>
#include<fstream>
#include<string>


using namespace std;

int transaction::getFromId()
{
	return fromId;
}

int transaction::getToId()
{
	return toId;
}

int transaction::getAmount()
{
	return amount;
}

void transaction::setTransaction(int _fromId, int _toId, int _amount)
{
	fromId = _fromId;
	toId = _toId;
	amount = _amount;
}

void transaction::print()
{
	cout << "---------------" <<endl;
	cout << "거래내역 현황 " << endl;
	cout << "---------------" << endl;
	cout << fromId << " -> " << toId << " : " << amount << endl;
}