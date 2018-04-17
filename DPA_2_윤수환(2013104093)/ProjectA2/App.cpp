#include<iostream>
#include"App.h"
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

App::App()
{
	load_files();
	md.setDBPointers(users,mailCenters,router);
}

App::~App()
{

}

bool App::load_files()
{
	//userDB_load
	fstream ifs;
	int _userType;
	string _id;
	string _password;
	string _address;
	string _name;
	string record;
	ifs.open("users.txt");
	int idx = 0;
	istringstream isf;
	while(!ifs.eof())
	{
		ifs >> _userType;
		if(_userType == 0)
		{	
			while(getline(ifs,record))
				isf >> record;
			
			ifs>>_userType >> _id >> _password >> _name;
			users[idx] = new Client();
			users[idx]->setid(_id);
			users[idx]->setPW(_password);
			users[idx]->setUserType(_userType);
			Client* downcast;
			downcast = (Client*)(users[idx]);
			downcast->setname(_name);
			while(isf >> _address)
				downcast->setaddress(_address);
			idx++;
		}
		else if(_userType == 1)
		{
			ifs >>_userType >> _id >> _password;
			users[idx] = new Manager();
			Manager* downcast;
			downcast = (Manager*)(users[idx]);
			downcast->setManager(_userType,_id,_password);
			idx++;
		}
	}
	ifs.close();
	//userDB_load_end

	//routerDB_load
	ifstream ifs1;
	ifs1.open("Router.txt");
	int number;

	router = new int*[12];
	for(int i = 0; i < 12 ; i++)
	{
		router[i] = new int[12];
	}
	while(!ifs1.eof())
	{

		for(int i = 0; i <12 ; i++)
		{
			for(int j = 0; j < 12; j++)
			{
				ifs1 >> number;
				router[i][j] = number;
			}
		}
	}

	ifs1.close();
	//routerDB_load_end

	//MailCenterDB_load
	ifstream ifs2; 
	ifs2.open("MailCenterId.txt");
	string _cityName;
	int midx = 0;
	int Cityid = 0;

	 while (!ifs2.eof())
	 {
		ifs2 >> Cityid >> _cityName;
		mailCenters[midx].setMailCenter(Cityid, _cityName);
		midx++;
	 }
	 for(midx = 0 ; midx < 12; midx++)
	 {
		mailCenters[midx].setNeighborMailCenter(router,midx);
	 }
	 ifs2.close();
	//MailCenterDB_load_end
	 return true;
}

void App::run()
{
	int selec;
	while(1)
	{
		cout << "----------------------" << endl;
		cout << "1.고객 로그인" << endl;
		cout << "2.매니저 로그인" << endl;
		cout << "3.로그아웃" << endl;	
		cout << "4.종료" << endl;
		cout << "----------------------" << endl;
		cin >> selec;
		switch(selec)
		{
			case 1:
			case 2:
				login();
				break;
			case 3:
				logout();
				break;
			case 4:
				return;
			default:
				cout << "다시 입력해 주세요" << endl;
		}
	}
}

void App::login()
{
	string _id;
	string _password;
	cout << "아이디를 입력해 주세요";
	cin >> _id;
	cout << "비밀번호를 입력해 주세요";
	cin >> _password;
	for(int i = 0;i < 36;i++)
	{
		if(users[i]->getId() == _id && users[i]->getPW() == _password)
		{
			loginedUser = users[i];
			if(loginedUser->getUserType() == 0)
				printClientMenu();
			else
				printManagerMenu();
		}
	}
}

void App::logout()
{
	loginedUser = NULL;
}

void App::printClientMenu()
{
	int selec;
	Client* client;
	client = (Client*)(loginedUser);
	while(1)
	{
		cout <<"사용자 이름:" << client->getName() << endl;
		cout << "주소: " << client->getaddress() << endl;
		cout << "-------------------------------------" << endl;
		cout << "1.우편물 보내기" << endl;
		cout << "2.우편물 받기 " << endl;
		cout << "3.보낸 우편물 목록" << endl;
		cout << "-------------------------------------" << endl;
		cout << "수행할 작업을 선택하세요 - > ";
		cin >> selec;

		switch(selec)
		{
		case 1:
			{
				client->send(md);
			}
		}
	}

}
void App::printManagerMenu()
{
}