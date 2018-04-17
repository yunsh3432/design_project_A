#include"loan.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int loan::getUserId()
{
	return userId;
}

int loan::getAmount()
{
	return amount;
}

int loan::getRepayment_Priod_Month()
{
	return repayment_priod_month;
}

int loan::getRepay()
{
	return repay;
}
int loan::setLoan(int id, int _amount, int _repayment_proid_month)
{
	userId = id;
	amount = _amount;
	repayment_priod_month = _repayment_proid_month;
	repay = (int)(_amount/_repayment_proid_month);
		
	return 0;
}

bool loan::loan_money(int _amount, int _repayment_proid_month, User* login_user, transaction* trans)
{
	switch(login_user->getCreditRating())
		case 1:
		{
			if(_amount <= 10000000)
			{
				login_user->PlusBalance(_amount);
				trans->setTransaction(0,login_user->getId(),_amount);
				return true;
			}
			else
			{
				cout << "대출이 불가능한 금액입니다." << endl;
				break;
			}
		
		case 2:
			if(_amount <= 9000000)
			{
				login_user->PlusBalance(_amount);
				trans->setTransaction(0,login_user->getId(),_amount);
				return true;
			}
			else
			{
				cout << "대출이 불가능한 금액입니다." << endl;
				break;
			}
		case 3:
			if(_amount <= 8000000)
			{
				login_user->PlusBalance(_amount);
				trans->setTransaction(0,login_user->getId(),_amount);
				return true;
			}
			else
			{
				cout << "대출이 불가능한 금액입니다." << endl;
				break;
			}
		case 4:
			if(_amount <= 7000000)
			{
				login_user->PlusBalance(_amount);
				trans->setTransaction(0,login_user->getId(),_amount);
				return true;
			}
			else
			{
				cout << "대출이 불가능한 금액입니다." << endl;
				break;
			}
		case 5:
			if(_amount <= 6000000)
			{
				login_user->PlusBalance(_amount);
				trans->setTransaction(0,login_user->getId(),_amount);
				return true;
			}
			else
			{
				cout << "대출이 불가능한 금액입니다." << endl;
				break;
			}
		case 6:
			if(_amount <= 5000000)
			{
				login_user->PlusBalance(_amount);
				trans->setTransaction(0,login_user->getId(),_amount);
				return true;
			}
			else
			{
				cout << "대출이 불가능한 금액입니다." << endl;
				break;
			}
		case 7:
			if(_amount <= 4000000)
			{
				login_user->PlusBalance(_amount);
				trans->setTransaction(0,login_user->getId(),_amount);
				return true;
			}
			else
			{
				cout << "대출이 불가능한 금액입니다." << endl;
				break;
			}
		case 8:
			if(_amount <= 3000000)
			{
				login_user->PlusBalance(_amount);
				trans->setTransaction(0,login_user->getId(),_amount);
				return true;
			}
			else
			{
				cout << "대출이 불가능한 금액입니다." << endl;
				break;
			}
		case 9:
			if(_amount <= 2000000)
			{
				login_user->PlusBalance(_amount);
				trans->setTransaction(0,login_user->getId(),_amount);
				return true;
			}
			else
			{
				cout << "대출이 불가능한 금액입니다." << endl;
				break;
			}
		case 10:
				cout << "대출이 불가능한 신용 등급입니다." << endl;
				break;
		default:
			cout << "잘못 입력하셧습니다."<< endl;
			break;
		}
	return false;
}

bool loan::repayment(User* login_user, transaction* trans)
{
	amount = login_user->getBalance();
	repayment_priod_month--;
	trans->setTransaction(login_user->getId(),0,repay);
	return false;
}

void loan::print()
{
	cout << "----------------------" << endl;
	cout << "고객님들의 대출현황" << endl;
	cout << "----------------------" << endl;
	cout << userId <<"님은	" << amount << "을 대출하였고	" << repayment_priod_month << "달 동안	" << repay << "만큼 상환하여야 합니다."<< endl;
	cout << "상환하지 못할시에는 신용등급이 강등됩니다. " << endl;
}