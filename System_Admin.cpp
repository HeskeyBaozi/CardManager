#include "System_Admin.h"
using namespace std;

void AdminSystem::displayWelcome()
{
	cout << "欢迎使用, 我的主人!" << endl;
}

void AdminSystem::displayFunction()
{
}

void AdminSystem::pushCard()
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

		/* 生成校园卡 */
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
			(dateString, myName,
				myBalance, myStudentID, mySchool));

		/* 将智能指针压入卡字典中 */
		__cardDictionary.emplace(myCardID, smartPoint);
		break;
	}

	/* 生成储蓄卡 */
	case 2:
	{
		/* 获取透支额度 */
		cout << "您的透支额度?" << endl;
		double myOverdraft = 0.0;
		cin >> myOverdraft;
		cin.ignore();
		cin.clear();

		/* 创建基类智能指针指向派生类(动态绑定) */
		shared_ptr<Card> smartPoint(
			new Deposit_Card
			(dateString, myName,
				myBalance, myOverdraft));

		/* 将智能指针压入卡字典中 */
		__cardDictionary.emplace(myCardID, smartPoint);
		break;
	}

	/* 生成绑定卡 */
	case 3:
	{
		/* 获取学号 */
		cout << "您的学号?" << endl;
		string myStudentID;
		getline(cin, myStudentID, '\n');

		/* 获取学院 */
		cout << "您的学院?" << endl;
		string mySchool;
		getline(cin, mySchool, '\n');

		/* 获取透支额度 */
		cout << "您的透支额度?" << endl;
		double myOverdraft = 0.0;
		cin >> myOverdraft;
		cin.ignore();
		cin.clear();

		/* 创建基类智能指针指向派生类(动态绑定) */
		shared_ptr<Card> smartPoint(
			new Binding_Card
			(dateString, myStudentID,
				myName, mySchool, myBalance, myOverdraft));

		/* 将智能指针压入卡字典中 */
		__cardDictionary.emplace(myCardID, smartPoint);
		break;
	}

	/* 选择错误 */
	default:
		cout << "选择错误, 办理卡失败" << endl;
		break;
	}
}

void AdminSystem::pop()
{
	__cardDictionary.clear();
}

