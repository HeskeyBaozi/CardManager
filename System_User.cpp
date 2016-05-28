#include "System_User.h"
using namespace std;

UserSystem::UserSystem()
{	
	string cardID;
	cout << "��������Ŀ���, �װ����û�:" << endl;
	cout << ">>> ";
	getline(cin, cardID, '\n');
	
}

UserSystem::UserSystem(string cardNumber)
{
	string cardID = cardNumber;
	while (__cardDictionary.find(cardID) == __cardDictionary.end())
	{
		cout << "�Բ���, ���Ų�����, ����������Ŀ���, �װ����û�" << endl;
		getline(cin, cardID, '\n');
	}
	User_ptr = __cardDictionary.at(cardID);
	UserSystem::displayWelcome();
}

void UserSystem::displayWelcome()
{
	cout << "======= ��ӭʹ��, �װ���" << User_ptr->getCardholderName() << " =======" << endl;
}

void UserSystem::displayFunction()
{
	cout << "[0] �˳�ϵͳ\n";
	cout << "[1] �鿴������Ϣ\n";
	cout << "[2] ����\n";
	cout << "[3] ת�����ֵ\n";
}

void UserSystem::moneyDeal()
{
	cout << "��ǰ������Ϣ:" << User_ptr->toJson().toStyledString() << endl;
	if (User_ptr->getClassName() == "Campus_Card")
	{
		cout << "У԰����֧���ֽ��ֵ, ��Ӵ����ֵ" << endl;
	}
	else if(User_ptr->getClassName() == "Deposit_Card")
	{
		shared_ptr<Deposit_Card> ptr = dynamic_pointer_cast<Deposit_Card>(User_ptr);
		cout << "���֧���ֽ��ֵ��ת��? ���������" << endl;
		cout << "[1] �ֽ��ֵ      | [2] ת��      | [0] �˳�" << endl;
		int myChoose = getValidNumber(0, 3);
		if(myChoose == 1)
		{
			double money;
			cout << "������Ҫ��ֵ�Ľ��:\n>>> ";
			cin >> money;
			cin.ignore();
			cin.clear();
			ptr->receiveMoney(money);
		}
		else if (myChoose == 2)
		{
			cout << "Ŀǰϵͳ���д��ڵĿ���ID��: " << endl;
			for (const auto& name : this->toJson().getMemberNames())
			{
				cout << name << endl;
			}
			cout << "������Ҫת�˵Ŀ���:\n>>> ";
			string cardID;
			getline(cin, cardID, '\n');
			if(__cardDictionary.find(cardID)!=__cardDictionary.end())
			{
				double money;
				cout << "������Ҫ��ֵ�Ľ��:\n>>> ";
				cin >> money;
				cin.ignore();
				cin.clear();
				ptr->receiveMoney(money);
				ptr->transfer(*__cardDictionary.at(cardID), money);
			}			
		}
	}else if(User_ptr->getClassName() == "Binding_Card")
	{
		shared_ptr<Binding_Card> ptr = dynamic_pointer_cast<Binding_Card>(User_ptr);
		cout << "���������" << endl;
		cout << "[1] ������ת��У԰��      | [2] ����ֽ��ֵ  | [3] ���ת��    | [0] �˳�" << endl;
		int myChoose = getValidNumber(0, 4);
		switch(myChoose)
		{
		case 1:
		{
			cout << "У԰�����: " << ptr->Campus_Card::getBalance() << " Ԫ\n";
			cout << "������: " << ptr->Deposit_Card::getBalance() << " Ԫ\n";
			cout << "������ת�˽��:\n>>> " << endl;
			double money = 0.0;
			cin >> money;
			cin.ignore();
			cin.clear();
			if (money > ptr->Deposit_Card::getBalance())
			{
				cout << "�Բ���, ����ת����ô��Ǯ, ��Ϊ����û����ô��Ǯ.." << endl;
			}else
			{
				ptr->Deposit_Card::setBalance(ptr->Deposit_Card::getBalance() - money);
				ptr->Campus_Card::setBalance(ptr->Campus_Card::getBalance() + money);
			}
			break;
		}
		case 2: 
		{
			double money;
			cout << "������Ҫ��ֵ�Ľ��:\n>>> ";
			cin >> money;
			cin.ignore();
			cin.clear();
			ptr->receiveMoney(money);
			break;
		}
		case 3:
		{
			cout << "Ŀǰϵͳ���д��ڵĿ���ID��: " << endl;
			for (const auto& name : this->toJson().getMemberNames())
			{
				cout << name << endl;
			}
			cout << "������Ҫת�˵Ŀ���:\n>>> ";
			string cardID;
			getline(cin, cardID, '\n');
			if (__cardDictionary.find(cardID) != __cardDictionary.end())
			{
				double money;
				cout << "������Ҫ��ֵ�Ľ��:\n>>> ";
				cin >> money;
				cin.ignore();
				cin.clear();
				ptr->transfer(*__cardDictionary.at(cardID), money);
			}
			break;
		}
		}
	}
	cout << "�������!\n��ǰ������Ϣ:" << User_ptr->toJson().toStyledString() << endl;
}
