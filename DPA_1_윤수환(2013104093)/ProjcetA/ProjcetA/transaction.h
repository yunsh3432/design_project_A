class transaction
{
private:
	int fromId;
	int toId;
	int amount;
public:
	int getFromId(); //보내는 사람 아이디
	int getToId(); //받는 사람 아이디
	int getAmount(); //보내거나 받는 돈
	void setTransaction(int fromId, int ToId, int amount); //거래 정보 입력
	void print(); //거래 정보 출력

}; 
#pragma once
