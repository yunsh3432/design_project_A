#include"APP.h"
#include<iostream>
#include<string>
#include<fstream>
#include<cctype>

using namespace std;

APP::APP()
{
	load_user_file();
	load_transaction_log_file();
	load_loan_list_file();
}

void APP::load_user_file()
{
	ifstream ifs;
	ifs.open("users.txt");
	int _id;
	string _password;
	string _name;
	int _account;
	int _balance;
	int _creditRating;
	Uidx = 0;
	while (!ifs.eof())
	{
		ifs >> _id >> _password >> _name >> _account >> _balance >> _creditRating;
		users[Uidx].setUser(_id, _password, _name, _account, _balance, _creditRating);
		Uidx++;
	}
}

void APP::load_transaction_log_file()
{
	ifstream ifs;
	ifs.open("transactions.txt");
	int _fromId;
	int _toId;
	int _amount;
	Tidx = 0;
	while (!ifs.eof())
	{
		ifs >> _fromId >> _toId >> _amount;
		transactions[Tidx].setTransaction(_fromId, _toId, _amount);
		Tidx++;
	}
}

void APP::load_loan_list_file()
{
	ifstream ifs;
	ifs.open("loans.txt");
	int _userId;
	int _amount;
	int _repayment_proid_month;
	Lidx = 0;
	while (!ifs.eof())
	{
		ifs >> _userId >> _amount >> _repayment_proid_month;
		loans[Lidx].setLoan(_userId, _amount, _repayment_proid_month);
		Lidx++;
	}
}

void APP::saveFiles()
{
	ofstream ofs;
	ofs.open("users.txt");
	for(int i = 0; i < Uidx-1 ; i++)
	{
		ofs << users[i].getId() << "	" <<users[i].getPW() << "	" << users[i].getName() << "	" << users[i].getAccountNumber() << "	" << users[i].getBalance() << "	"<< users[i].getCreditRating() << endl;
	}
	ofs.close();
	ofs.open("transactions.txt");
	for(int i = 0; i < Tidx-1 ; i++)
	{
		ofs << transactions[i].getFromId() << "	" << transactions[i].getToId() << "	" << transactions[i].getAmount() << endl;
	}
	ofs.close();
	ofs.open("loans.txt");
	for(int i = 0; i < Lidx-1; i++)
	{
		ofs << loans[i].getUserId() << "	" << loans[i].getAmount() << "	" << loans[i].getRepayment_Priod_Month() << "	" << endl;
	}
	ofs.close();

}

void APP::run()
{
	int selec = 0;
	int User;
	string pass;
	while (selec != 3)
	{
		cout << "------------------------" << endl;
		cout << "1. 로그인" << endl;
		cout << "2. 로그아웃" << endl;
		cout << "3. 종료" << endl;
		cout << "------------------------" << endl;
		cout << "->";
		cin >> selec;
		if (selec == 1)
		{
			cout << "사용자 아이디 입력 : ";
			User = getNumber();
			cout << "비밀번호 :";
			cin >> pass;
			login(User, pass);
			print_menu();
		}
		else if (selec == 2)
		{
			logout();
		}
		else if (selec == 3)
		{
			cout << "감사합니다 " << endl;
			saveFiles();
			break;
		}
		else
		{
			cout << "잘못입력하셨습니다. 다시 입력해 주세요 " << endl;
		}
	}

}

User* APP::login(int User_id, string password)
{
	loginedUser = NULL;

	while (true)
	{
		for (int i = 0; i < 20; i++)
		{
			if (User_id == users[i].getId())
			{
				if (password == users[i].getPW())
				{
					loginedUser = &users[i];
					users[i].getTrasCache(transactions);
					return loginedUser;
				}
				else
				{
					cout << " 비밀번호를 잘못 입력하셨습니다." << endl;
					run();
				}
			}
		}
		if (loginedUser == NULL)
		{	
			cout << "아이디혹은 비밀번호를 잘못 입력하셨습니다. 다시 로그인 해주세요" <<endl;
			run();
		}
	}
}

void APP::logout()
{
	loginedUser = NULL;
}

bool APP::sendMoney(int _toAccount, int _amount)
{
	for (int i = 0; i < 100; i++)
	{
		if (_toAccount == users[i].getAccountNumber())
		{
			if(loginedUser->getBalance() < _amount)
			{
				cout << " 돈이 없습니다. "<< endl;
				return false;
			}
			users[i].PlusBalance(_amount);
			loginedUser->subBalance(_amount);
			transactions[Tidx].setTransaction(loginedUser->getId(),users[i].getId(), _amount);
			Tidx++;
			return true;
		}
		else if(i >= 100)
		{
			cout << "찾으시는 계좌번호가 없습니다." << endl;
			return false;
	
		}
	}

}

bool APP::deposit(int _amount)
{
	for (int i = 0; i < 20; i++)
	{
		if (loginedUser->getId() == users[i].getId())
		{
			loginedUser->PlusBalance(_amount);
			transactions[Tidx].setTransaction(-1, loginedUser->getId(), _amount);
			Tidx++;
			return true;
		}
	}
	return false;
}

bool APP::withdraw(int _amount)
{
	for (int i = 0; i < 20; i++)
	{
		if (loginedUser->getId() == users[i].getId() )
		{
			if(loginedUser->getBalance() < _amount)
			{
				cout << "돈이 부족합니다." << endl;
				return false;
			}
			loginedUser->subBalance(_amount);
			transactions[Tidx].setTransaction(loginedUser->getId(), -1 , _amount);
			Tidx++;
			return true;
		}		
	}
	return false;
}

bool APP::loan_money(int _amount, int _repayment_priod_month)
{
	for(int i = 0 ; i < 100;i++)
	{
		if(loginedUser->getId() == loans[i].getUserId())
		{
			cout << "이미 대출을 하엿으므로 더이상의 대출이 불가능 합니다." << endl;
			return false;
		}
	}
	loans[Lidx].setLoan(loginedUser->getId(),_amount,_repayment_priod_month);
	loans[Lidx].loan_money(_amount,_repayment_priod_month,loginedUser,&transactions[Tidx]);
	Lidx++;
	Tidx++;
	return true;
}

bool APP::repayment()
{
	return 0;
}

void APP::print_menu()
{
	int selec = 0;
	while(selec != 6)
	{
	loginedUser->printUserInfo();
		cout << "-------------------------- " << endl;
		cout << "1.입, 출금" << endl;
		cout << "2. 송금" << endl;
		cout << "3. 대출" << endl;
		cout << "4. 대출금 반환" << endl;
		cout << "5.거래내역 조회" << endl;
		cout << "6. 이전메뉴로 " << endl;
		cout <<"----------------------------" << endl;
		cout << "->";
		cin >> selec;
		switch(selec)
		{
		case 1:
			print_deposit_withdraw_menu();
			break;
		case 2:
			print_send_money_menu();
			break;
		case 3:
			print_loan_money();
			break;
		case 4:
			print_repayment_menu();
			break;
		case 5:
			print_logined_user_transactions();
			break;
		case 6:
			logout();
			break;
		default:
			cout << "잘못 입력하셨습니다. 다시입력해 주세요" << endl;
			break;
		}
	}
}

void APP::print_deposit_withdraw_menu()
{
	int selec = 0;
	int amount;
	while(selec != 3)
	{
		cout << "-----------------------------" << endl;
		cout << "1, 입금 " << endl;
		cout << "2. 출금 " << endl;
		cout << "3. 나가기" <<endl;
		cout << "-----------------------------" << endl;
		cout << "->";
		cin >> selec;
		if(selec == 1)
		{
			cout << "입금할 돈:";
			amount = getNumber();
			deposit(amount);
		}
		else if(selec == 2)
		{
			cout << "출금할 돈: ";
			amount = getNumber();
			withdraw(amount);
		}
		else if(selec == 3)
		{
			return;
		}
		else
		{
			cout << "잘못입력하셧습니다. 다시입력해 주세요"<< endl;
		}
	}
}

void APP::print_send_money_menu()
{
	int selec = 0;
	int amount;
	int toaccount;
	while(selec != 2)
	{
		cout<<"----------------------------------------------"<< endl;
		cout << "1.송금하기 " << endl;
		cout << "2.나가기 " << endl;
		cout<<"----------------------------------------------"<< endl;
		cout << " -> " ;
		cin >> selec;
		if(selec == 1)
		{
			cout << "받는 사람의 계좌번호를 입력하세요: ";
			cin >> toaccount;
			cout << "보낼 금액을 입력하세요: ";
			amount = getNumber();
			sendMoney(toaccount,amount);;
		}
		else if(selec == 2)
		{
			return ;
		}
		else
		{
			cout << "잘못 입력하셨습니다. 다시 입력해 주세요" << endl;
		}
	}
}

void APP::print_loan_money()
{
	int repayment_priod_month;
	int loanMoney;
	loginedUser->printUserInfo();
	cout << "-------------------------" << endl;
	cout << "대출받을 금액을 입력해 주세요: ";
	loanMoney=getNumber();
	cout<< "반환할 기간을 입력해 주세요<n월>: ";
	cin >> repayment_priod_month;
	loan_money(loanMoney,repayment_priod_month);

}

void APP::print_repayment_menu()
{
	int selec;
	loginedUser->printUserInfo();
	cout << "-----------------------------" << endl;
	cout << "대출금을 상환 합니다, " << endl;
	for(int i = 0; i < Lidx;i++)
	{
		if(loginedUser->getId() == loans[i].getUserId())
		{
			if(loginedUser->getBalance() >= loans[i].getRepay())
			{
				loginedUser->subBalance(loans[i].getRepay());
				loans[i].repayment(loginedUser,transactions);
				cout << "반환되었습니다."<<endl;
				cout << "-----------------------------" << endl;
				if(loans[i].getAmount() > 0)
				cout << loans[i].getAmount() << "원을 상환하는데 " << loans[i].getRepayment_Priod_Month() << "달 남았습니다." << endl;
				else
				{
					cout << "모든 대출금을 상환하였습니다." << endl;
					loans[i].setLoan(0,0,1);
				}
			}
			else
			{
				cout << "반환해야 할 돈이 모자랍니다." << endl;
				cout << "---------------------------" << endl;
				loginedUser->subcreditRating();

			}
		}
	}
}

void APP::print_logined_user_transactions()
{
	int count;
	cout << "몇개의 거래내역을 보고 싶으십니까?  ";
	count = getNumber();
	if(count <= 5)
		loginedUser->printtransCache(count);
	else
	{
	for(int i = 0 ; i < count ; i++)
	if(loginedUser->getTrasCache(&transactions[i]) == true)
		cout << "처리됨:"<< transactions[i].getFromId() << " -> " << transactions[i].getToId() << "->" << transactions[i].getAmount() << endl;
	}
}

int APP::getNumber()
{
	int retNum;
	cin >> retNum;

	if(cin.fail())
	{
		cout<< "잘못된 입력입니다. 숫자로 입력해 주세요" << endl;
	cin.clear();
	cin.ignore(256,'\n');
	return getNumber();
	}
	return retNum;
}
