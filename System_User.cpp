#include "System_User.h"
using namespace std;

UserSystem::UserSystem()
	:SystemBase()
{
	UserSystem::displayWelcome();
}

void UserSystem::displayWelcome()
{
	cout << "======= ��ӭʹ��, �װ����û� =======" << endl;
}

void UserSystem::displayFunction()
{
	cout << "[1] �鿴������Ϣ\n";
	cout << "[2] ����\n";
}
