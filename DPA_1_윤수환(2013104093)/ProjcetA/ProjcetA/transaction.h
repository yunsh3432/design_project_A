class transaction
{
private:
	int fromId;
	int toId;
	int amount;
public:
	int getFromId(); //������ ��� ���̵�
	int getToId(); //�޴� ��� ���̵�
	int getAmount(); //�����ų� �޴� ��
	void setTransaction(int fromId, int ToId, int amount); //�ŷ� ���� �Է�
	void print(); //�ŷ� ���� ���

}; 
#pragma once
