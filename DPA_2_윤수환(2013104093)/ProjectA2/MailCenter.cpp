#include<iostream>
#include"MailCenter.h"
#include<string>

using namespace std;

void MailCenter::setMailCenter(int _id, string _cityName)
{
	id = _id;
	cityName = _cityName;
}

string MailCenter::getCityName()
{
	return cityName;
}

void MailCenter::setNeighborMailCenter(int** router,int midx)
{
	int indexList[12];
	int n = 0;
	for(int j = 0; j < 12; j++)
	{			
		neighborCnt = 0;
		n = 0;
		if(router[midx][j] == 1)
		{
			neighborCnt++;
			indexList[n] = j;
			n++;
		}
	}		
	
	neighborIds = new int[neighborCnt];
	n = 0;		
	
	for(int k = 0; k < neighborCnt; k++)
	{
		neighborIds[k] = indexList[n];			
		n++;
	}

}