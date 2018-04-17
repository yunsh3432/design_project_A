#pragma once
#ifndef USER_H
#define USER_H
#include<string>
#include"transaction.h"

using namespace std;

class User
{
private:
	int id;
	string password;
	string name;
	int accountNumber;
	int balance;
	int creditRating;
	int cacheSize;
	transaction* transCache[5];
public:
	int getId();// ���̵� ����
	string getPW();  // ��й�ȣ ����
	string getName(); // �̸� ����
	int getAccountNumber(); // ���¹�ȣ ����
	int getBalance(); // �ܱ� ����
	int getCreditRating(); // �ſ��� ����
	int PlusBalance(int amount);//�ܱ��� �����ִ� �Լ�
	int subBalance(int amount);//�ܱ��� ���ִ� �Լ�
	void subcreditRating();//�ſ����� ���ߴ� �Լ�
	void printUserInfo();// ����� ���� ���
	bool getTrasCache(transaction* transDB);// APP�� Transaction DB���� ID�� ��ġ�ϴ� �ŷ������� ������
	void setUser(int id, string password, string name, int accountNumber, int balance, int creditRating); // ����� ���� �Է�
	void printtransCache(int count);
};
#endif