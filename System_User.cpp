#include "System_User.h"
using namespace std;

UserSystem::UserSystem()
{
	UserSystem::displayWelcome();
	string cardID;
	cout << "请输入你的卡号, 亲爱的用户" << endl;
	getline(cin, cardID, '\n');
	while (__cardDictionary.find(cardID) == __cardDictionary.end())
	{
		cout << "对不起, 卡号不存在, 重新输入你的卡号, 亲爱的用户" << endl;
		getline(cin, cardID, '\n');
	}
	User_ptr = __cardDictionary.at(cardID);
}

void UserSystem::displayWelcome()
{
	cout << "======= 欢迎使用, 亲爱的用户 =======" << endl;
}

void UserSystem::displayFunction()
{
	cout << "[1] 查看卡的信息\n";
	cout << "[2] 消费\n";
}
