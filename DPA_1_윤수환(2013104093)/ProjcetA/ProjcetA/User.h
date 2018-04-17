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
	int getId();// 아이디 리턴
	string getPW();  // 비밀번호 리턴
	string getName(); // 이름 리턴
	int getAccountNumber(); // 계좌번호 리턴
	int getBalance(); // 잔금 리턴
	int getCreditRating(); // 신용등급 리턴
	int PlusBalance(int amount);//잔금을 더해주는 함수
	int subBalance(int amount);//잔금을 뺴주는 함수
	void subcreditRating();//신용등급을 낮추는 함수
	void printUserInfo();// 사용자 정보 출력
	bool getTrasCache(transaction* transDB);// APP의 Transaction DB에서 ID가 일치하는 거래내역을 가져옴
	void setUser(int id, string password, string name, int accountNumber, int balance, int creditRating); // 사용자 정보 입력
	void printtransCache(int count);
};
#endif