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
		cout << "1. �α���" << endl;
		cout << "2. �α׾ƿ�" << endl;
		cout << "3. ����" << endl;
		cout << "------------------------" << endl;
		cout << "->";
		cin >> selec;
		if (selec == 1)
		{
			cout << "����� ���̵� �Է� : ";
			User = getNumber();
			cout << "��й�ȣ :";
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
			cout << "�����մϴ� " << endl;
			saveFiles();
			break;
		}
		else
		{
			cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ��� " << endl;
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
					cout << " ��й�ȣ�� �߸� �Է��ϼ̽��ϴ�." << endl;
					run();
				}
			}
		}
		if (loginedUser == NULL)
		{	
			cout << "���̵�Ȥ�� ��й�ȣ�� �߸� �Է��ϼ̽��ϴ�. �ٽ� �α��� ���ּ���" <<endl;
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
				cout << " ���� �����ϴ�. "<< endl;
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
			cout << "ã���ô� ���¹�ȣ�� �����ϴ�." << endl;
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
				cout << "���� �����մϴ�." << endl;
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
			cout << "�̹� ������ �Ͽ����Ƿ� ���̻��� ������ �Ұ��� �մϴ�." << endl;
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
		cout << "1.��, ���" << endl;
		cout << "2. �۱�" << endl;
		cout << "3. ����" << endl;
		cout << "4. ����� ��ȯ" << endl;
		cout << "5.�ŷ����� ��ȸ" << endl;
		cout << "6. �����޴��� " << endl;
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
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ��Է��� �ּ���" << endl;
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
		cout << "1, �Ա� " << endl;
		cout << "2. ��� " << endl;
		cout << "3. ������" <<endl;
		cout << "-----------------------------" << endl;
		cout << "->";
		cin >> selec;
		if(selec == 1)
		{
			cout << "�Ա��� ��:";
			amount = getNumber();
			deposit(amount);
		}
		else if(selec == 2)
		{
			cout << "����� ��: ";
			amount = getNumber();
			withdraw(amount);
		}
		else if(selec == 3)
		{
			return;
		}
		else
		{
			cout << "�߸��Է��ϼ˽��ϴ�. �ٽ��Է��� �ּ���"<< endl;
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
		cout << "1.�۱��ϱ� " << endl;
		cout << "2.������ " << endl;
		cout<<"----------------------------------------------"<< endl;
		cout << " -> " ;
		cin >> selec;
		if(selec == 1)
		{
			cout << "�޴� ����� ���¹�ȣ�� �Է��ϼ���: ";
			cin >> toaccount;
			cout << "���� �ݾ��� �Է��ϼ���: ";
			amount = getNumber();
			sendMoney(toaccount,amount);;
		}
		else if(selec == 2)
		{
			return ;
		}
		else
		{
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���" << endl;
		}
	}
}

void APP::print_loan_money()
{
	int repayment_priod_month;
	int loanMoney;
	loginedUser->printUserInfo();
	cout << "-------------------------" << endl;
	cout << "������� �ݾ��� �Է��� �ּ���: ";
	loanMoney=getNumber();
	cout<< "��ȯ�� �Ⱓ�� �Է��� �ּ���<n��>: ";
	cin >> repayment_priod_month;
	loan_money(loanMoney,repayment_priod_month);

}

void APP::print_repayment_menu()
{
	int selec;
	loginedUser->printUserInfo();
	cout << "-----------------------------" << endl;
	cout << "������� ��ȯ �մϴ�, " << endl;
	for(int i = 0; i < Lidx;i++)
	{
		if(loginedUser->getId() == loans[i].getUserId())
		{
			if(loginedUser->getBalance() >= loans[i].getRepay())
			{
				loginedUser->subBalance(loans[i].getRepay());
				loans[i].repayment(loginedUser,transactions);
				cout << "��ȯ�Ǿ����ϴ�."<<endl;
				cout << "-----------------------------" << endl;
				if(loans[i].getAmount() > 0)
				cout << loans[i].getAmount() << "���� ��ȯ�ϴµ� " << loans[i].getRepayment_Priod_Month() << "�� ���ҽ��ϴ�." << endl;
				else
				{
					cout << "��� ������� ��ȯ�Ͽ����ϴ�." << endl;
					loans[i].setLoan(0,0,1);
				}
			}
			else
			{
				cout << "��ȯ�ؾ� �� ���� ���ڶ��ϴ�." << endl;
				cout << "---------------------------" << endl;
				loginedUser->subcreditRating();

			}
		}
	}
}

void APP::print_logined_user_transactions()
{
	int count;
	cout << "��� �ŷ������� ���� �����ʴϱ�?  ";
	count = getNumber();
	if(count <= 5)
		loginedUser->printtransCache(count);
	else
	{
	for(int i = 0 ; i < count ; i++)
	if(loginedUser->getTrasCache(&transactions[i]) == true)
		cout << "ó����:"<< transactions[i].getFromId() << " -> " << transactions[i].getToId() << "->" << transactions[i].getAmount() << endl;
	}
}

int APP::getNumber()
{
	int retNum;
	cin >> retNum;

	if(cin.fail())
	{
		cout<< "�߸��� �Է��Դϴ�. ���ڷ� �Է��� �ּ���" << endl;
	cin.clear();
	cin.ignore(256,'\n');
	return getNumber();
	}
	return retNum;
}
