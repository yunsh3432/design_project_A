#ifndef LOAN_H
#define LOAN_H

#include"transaction.h"
#include"User.h"

class loan
{
private:
	int userId;
	int amount;
	int repayment_priod_month;
	int repay;
public:
	int getUserId(); // 사용자 아이디 반환
	int getAmount(); // 대출 잔금 반환
	int getRepayment_Priod_Month(); // 잔여 상환 기간 반환
	int setLoan(int id, int amount, int repayment_proid_month);// 대출정보 입력
	int getRepay();

	bool loan_money(int _amount,int _repayment_proid_month,User* logined_user, transaction* trans);// 대출 받은 만큼 현재 유저의 잔액을 갱신하고, 거래내역을 추가
	bool repayment(User* logined_user, transaction* trans);// 상환한 금액 만큼 현재 유저의 잔액을 갱신하고, 거래내역을 추가

	void print(); //대출 정보 출력

};
#endif
#pragma once
