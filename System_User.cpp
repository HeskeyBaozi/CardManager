#include "System_User.h"
using namespace std;

UserSystem::UserSystem()
{	
	string cardID;
	cout << "请输入你的卡号, 亲爱的用户:" << endl;
	cout << ">>> ";
	getline(cin, cardID, '\n');
	
}

UserSystem::UserSystem(string cardNumber)
{
	string cardID = cardNumber;
	while (__cardDictionary.find(cardID) == __cardDictionary.end())
	{
		cout << "对不起, 卡号不存在, 重新输入你的卡号, 亲爱的用户" << endl;
		getline(cin, cardID, '\n');
	}
	User_ptr = __cardDictionary.at(cardID);
	UserSystem::displayWelcome();
}

void UserSystem::displayWelcome()
{
	cout << "======= 欢迎使用, 亲爱的" << User_ptr->getCardholderName() << " =======" << endl;
}

void UserSystem::displayFunction()
{
	cout << "[0] 退出系统\n";
	cout << "[1] 查看卡的信息\n";
	cout << "[2] 消费\n";
	cout << "[3] 转账与充值\n";
}

void UserSystem::moneyDeal()
{
	cout << "当前卡的信息:" << User_ptr->toJson().toStyledString() << endl;
	if (User_ptr->getClassName() == "Campus_Card")
	{
		cout << "校园卡不支持现金充值, 请从储蓄卡充值" << endl;
	}
	else if(User_ptr->getClassName() == "Deposit_Card")
	{
		shared_ptr<Deposit_Card> ptr = dynamic_pointer_cast<Deposit_Card>(User_ptr);
		cout << "储蓄卡支持现金充值和转账? 请输入操作" << endl;
		cout << "[1] 现金充值      | [2] 转账      | [0] 退出" << endl;
		int myChoose = getValidNumber(0, 3);
		if(myChoose == 1)
		{
			double money;
			cout << "请输入要充值的金额:\n>>> ";
			cin >> money;
			cin.ignore();
			cin.clear();
			ptr->receiveMoney(money);
		}
		else if (myChoose == 2)
		{
			cout << "目前系统中中存在的卡的ID有: " << endl;
			for (const auto& name : this->toJson().getMemberNames())
			{
				cout << name << endl;
			}
			cout << "请输入要转账的卡号:\n>>> ";
			string cardID;
			getline(cin, cardID, '\n');
			if(__cardDictionary.find(cardID)!=__cardDictionary.end())
			{
				double money;
				cout << "请输入要充值的金额:\n>>> ";
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
		cout << "请输入操作" << endl;
		cout << "[1] 储蓄卡余额转到校园卡      | [2] 储蓄卡现金充值  | [3] 储蓄卡转账    | [0] 退出" << endl;
		int myChoose = getValidNumber(0, 4);
		switch(myChoose)
		{
		case 1:
		{
			cout << "校园卡余额: " << ptr->Campus_Card::getBalance() << " 元\n";
			cout << "储蓄卡余额: " << ptr->Deposit_Card::getBalance() << " 元\n";
			cout << "请输入转账金额:\n>>> " << endl;
			double money = 0.0;
			cin >> money;
			cin.ignore();
			cin.clear();
			if (money > ptr->Deposit_Card::getBalance())
			{
				cout << "对不起, 不能转出这么多钱, 因为卡里没有这么多钱.." << endl;
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
			cout << "请输入要充值的金额:\n>>> ";
			cin >> money;
			cin.ignore();
			cin.clear();
			ptr->receiveMoney(money);
			break;
		}
		case 3:
		{
			cout << "目前系统中中存在的卡的ID有: " << endl;
			for (const auto& name : this->toJson().getMemberNames())
			{
				cout << name << endl;
			}
			cout << "请输入要转账的卡号:\n>>> ";
			string cardID;
			getline(cin, cardID, '\n');
			if (__cardDictionary.find(cardID) != __cardDictionary.end())
			{
				double money;
				cout << "请输入要充值的金额:\n>>> ";
				cin >> money;
				cin.ignore();
				cin.clear();
				ptr->transfer(*__cardDictionary.at(cardID), money);
			}
			break;
		}
		}
	}
	cout << "操作完成!\n当前卡的信息:" << User_ptr->toJson().toStyledString() << endl;
}
