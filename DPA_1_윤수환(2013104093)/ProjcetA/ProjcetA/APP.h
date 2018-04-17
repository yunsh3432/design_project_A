#include"loan.h"
#include"transaction.h"
#include"User.h"
#include<string>

using namespace std;

class APP
{
public:
	APP();
	void run();

private:
	User users[20];
	transaction transactions[100];
	loan loans[100];
	User* loginedUser;
	int Uidx;
	int Tidx;
	int Lidx;

	void load_user_file();
	void load_transaction_log_file();
	void load_loan_list_file();
	void saveFiles();
	User* login(int User_id, string password);
	void logout();
	bool sendMoney(int _toAccount, int _amount); // �۱� 
	bool deposit(int _amount); // �Ա�
	bool withdraw(int _amount);// ���
	bool loan_money(int _amount, int _repayment_priod_month);// ����
	bool repayment();// ����� ��ȯ
	void print_menu();
	void print_deposit_withdraw_menu();
	void print_send_money_menu();
	void print_loan_money();
	void print_repayment_menu();
	void print_logined_user_transactions();
	int getNumber();

};
#pragma once
