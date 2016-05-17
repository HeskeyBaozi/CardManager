#include "System.h"
using namespace std;

void CardSystem::displayWelcome()
{
	cout << "======= 欢迎使用 =======" << endl;
}

void CardSystem::pushCard()
{
	/* 获得办卡时间 */
	time_t issueDate = time(nullptr);
	string dateString = ctime(&issueDate);

	/* 获取持卡人姓名 */
	cout << "您的姓名?" << endl;
	string myName;
	getline(cin, myName, '\n');

	/* 获取卡号 */
	cout << "您的卡号?" << endl;
	string myCardID;
	getline(cin, myCardID, '\n');

	/* 卡内余额为0 */
	double myBalance = 0.0;

	cout << "请输入想办理的卡类?" << endl;
	int myChoose = 0;
	cout << "[1] 校园卡\n[2] 储蓄卡\n[3] 绑定卡" << endl;
	cin >> myChoose;
	cin.ignore();
	cin.clear();
	switch (myChoose)
	{
	case 1:
	{
		/* 获取学号 */
		cout << "您的学号?" << endl;
		string myStudentID;
		getline(cin, myStudentID, '\n');

		/* 获取学院 */
		cout << "您的学院?" << endl;
		string mySchool;
		getline(cin, mySchool, '\n');

		/* 创建基类智能指针指向派生类(动态绑定) */
		shared_ptr<Card> smartPoint(
			new Campus_Card
			(myCardID, dateString, myName,
				myBalance, myStudentID, mySchool));

		/* 将智能指针压入卡栈中 */
		__system.push_back(smartPoint);
		break;
	}
	case 2:
		// todo
		break;
	case 3:
		// todo
		break;
	default:
		// todo
		break;

	}
}

void CardSystem::pop()
{
	__system.pop_back();
}
