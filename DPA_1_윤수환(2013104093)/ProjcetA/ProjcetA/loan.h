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
	int getUserId(); // ����� ���̵� ��ȯ
	int getAmount(); // ���� �ܱ� ��ȯ
	int getRepayment_Priod_Month(); // �ܿ� ��ȯ �Ⱓ ��ȯ
	int setLoan(int id, int amount, int repayment_proid_month);// �������� �Է�
	int getRepay();

	bool loan_money(int _amount,int _repayment_proid_month,User* logined_user, transaction* trans);// ���� ���� ��ŭ ���� ������ �ܾ��� �����ϰ�, �ŷ������� �߰�
	bool repayment(User* logined_user, transaction* trans);// ��ȯ�� �ݾ� ��ŭ ���� ������ �ܾ��� �����ϰ�, �ŷ������� �߰�

	void print(); //���� ���� ���

};
#endif
#pragma once
