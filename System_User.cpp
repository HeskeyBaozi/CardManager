#include "System_User.h"
using namespace std;

UserSystem::UserSystem()
{
	UserSystem::displayWelcome();
	string cardID;
	cout << "��������Ŀ���, �װ����û�" << endl;
	getline(cin, cardID, '\n');
	while (__cardDictionary.find(cardID) == __cardDictionary.end())
	{
		cout << "�Բ���, ���Ų�����, ����������Ŀ���, �װ����û�" << endl;
		getline(cin, cardID, '\n');
	}
	User_ptr = __cardDictionary.at(cardID);
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
