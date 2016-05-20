#include "System_User.h"
using namespace std;

UserSystem::UserSystem()
	:SystemBase()
{
	UserSystem::displayWelcome();
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
