#pragma once
#include <string>
using namespace std;
class Mail
{
private:
	string senderId;
	string recieverId;
	string senderAddr;
	string recieverAddr;
	int mailType;
	int cost;

	virtual int calculateCost(int distance) = 0;

public:
	Mail();
	~Mail();
	int Getcost();
	int GetmailType();
	void changeCost(int distance,int weight);
};

class Letter :
	public Mail
{
public:
	virtual int calculateCost(int distance);

public:
	Letter();
	~Letter();
};

class Package :
	public Mail
{
public:	
	virtual int calculateCost(int distance);

	Package();
	~Package();
private:
	int weight;
};