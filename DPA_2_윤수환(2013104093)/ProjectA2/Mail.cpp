#include<iostream>
#include"Mail.h"

using namespace std;

//Mail
Mail::Mail()
{
	mailType = 0;
	cost = 0;
}

Mail::~Mail()
{
}

void Mail::changeCost(int distance,int weight)
{
	if(distance == 0)
	{
		cost = 1000;
	}

	else
	cost = (1000*distance) + (500*weight);
}

int Mail::Getcost()
{
	return cost;
}

int Mail::GetmailType()
{
	return mailType;
}
//Letter
Letter::Letter()
{
}

Letter::~Letter()
{
}

int Letter::calculateCost(int distance)
{
	changeCost(distance,0);
}



//package

Package::Package()
{
	weight = 0;
}

Package::~Package()
{
}

int Package::calculateCost(int distance)
{
	cout << "소포의 무게가 얼마인가요? ";
	cin >> weight;
	changeCost(distance,weight);
	
}