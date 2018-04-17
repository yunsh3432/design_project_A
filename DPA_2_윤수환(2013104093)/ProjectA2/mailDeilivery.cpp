#include"mailDeilivery.h"
#include"Mail.h"
#include"MailCenter.h"
#include<iostream>
#include<string>

using namespace std;

mailDeilivery::mailDeilivery()
{
	pointerOfUsers = NULL;
	pointerOfMailCenters = NULL;
	pointerOfRouter = NULL;
}

mailDeilivery::~mailDeilivery()
{
}


int mailDeilivery::getMailCenterIdByCityName(string cityName)
{
}

int mailDeilivery::getTotalDistance(int sourceId, int destinationId)
{
	int dist[N], prev[N], selected[N] = { 0 }, i, m, min, start, d, j;
	int path[N];
	for (i = 1; i< N; i++)
	{
		dist[i] = IN;
		prev[i] = -1;
	}
	start = sourceId;
	selected[start] = 1;
	dist[start] = 0;
	while (selected[destinationId] == 0)
	{
		min = IN;
		m = 0;
		for (i = 1; i< N; i++)
		{
			if(pointerOfRouter[start][i] == 0)
				pointerOfRouter[start][i] = 99;
			d = dist[start] + pointerOfRouter[start][i];
			if (d< dist[i] && selected[i] == 0)
			{
				dist[i] = d;
				prev[i] = start;
			}
			if (min>dist[i] && selected[i] == 0)
			{
				min = dist[i];
				m = i;
			}
		}
		start = m;
		selected[start] = 1;
	}
	start = destinationId;
	j = 0;
	return dist[destinationId];
}

int mailDeilivery::getNextMailCenterId(int currentPos, int destinationId)
{
	int pathStartPoint = currentPos;
	int dist[N], prev[N], selected[N] = { 0 }, i, m, min, start, d, j;
	int path[N] = {-1,};
	for (i = 1; i< N; i++)
	{
		dist[i] = IN;
		prev[i] = -1;
	}
	start = currentPos;
	selected[start] = 1;
	dist[start] = 0;
	while (selected[destinationId] == 0)
	{
		min = IN;
		m = 0;
		for (i = 1; i< N; i++)
		{
			if(pointerOfRouter[start][i] == 0)
				pointerOfRouter[start][i] = 99;
			d = dist[start] + pointerOfRouter[start][i];
			if (d< dist[i] && selected[i] == 0)
			{
				dist[i] = d;
				prev[i] = start;
			}
			if (min>dist[i] && selected[i] == 0)
			{
				min = dist[i];
				m = i;
			}
		}
		start = m;
		selected[start] = 1;
	}
	start = destinationId;
	j = 0;
	while (start != pathStartPoint)
	{
		path[j++] = start;
		start = prev[start];
	}
	return path[j-1];
}

bool mailDeilivery::clientSendMail(User* curUser)
{
	string _name;
	string _address;
	int selec;
	Mail* mail;
	MailCenter* mailcenterPtr;
	stringstream isf;
	Client* client = (Client*)(curUser);
	cout << "� ������ ������ �����ʴϱ�?(1.����, 2.����):";
	cin >> selec;
	if(selec == 1)
	{
		Letter* letter = (Letter*)(mail);
		cout << "������ �޴� ����� �̸��� �Է��� �ּ���:";
		cin >> _name;
		cout << "������ �޴� ����� �ּҸ� �Է��� �ּ���: ";
		cin >> _address;
		if(isf >> client->getaddress() == "������"||isf >> client->getaddress() == "���󳲵�")
		{
			isf >> client->getaddress();
	
		}
		if(client->getaddress() == mailcenterPtr->getCityName());
		letter->calculateCost(getTotalDistance(,));
	}
	else if(selec == 2)
	{
		Package* package = (Package*)(mail);
		cout << "������ �޴� ����� �̸��� �Է��� �ּ���:";
		cin >> _name;
		cout << "������ �޴� ����� �ּҸ� �Է��� �ּ���: ";
		cin >> _address;
	
	}
	else
}

bool mailDeilivery::managerSendMail(string cityName)
{
}

bool mailDeilivery::managerReceiveMail(string cityName)
{
}
