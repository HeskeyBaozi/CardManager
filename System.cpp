#include "System.h"
using namespace std;

SystemBase::~SystemBase()
{
}

void SystemBase::pushCard()
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

void SystemBase::pop()
{
	__cardDictionary.clear();
}

void SystemBase::save()
{
	ofstream fout;
	for (auto pair : __cardDictionary)
	{
		fout.open(string("./file/card/" + pair.first + ".dat"), ios::binary);
		if (fout)
		{
			/* 将基类指针安全转换为派生类指针 */
			shared_ptr<Card> basePtr = pair.second;
			if (basePtr->getClassName() == "Campus_Card")
			{
				shared_ptr<Campus_Card> campusPtr
					(dynamic_pointer_cast<Campus_Card>(basePtr));
				fout.write(reinterpret_cast<char*>(campusPtr.get()), sizeof *campusPtr);
			}
			else if(basePtr->getClassName() == "Deposit_Card")
			{
				shared_ptr<Deposit_Card> depositPtr
					(dynamic_pointer_cast<Deposit_Card>(basePtr));
				fout.write(reinterpret_cast<char*>(depositPtr.get()), sizeof *depositPtr);
			}
			else if (basePtr->getClassName() == "Binding_Card")
			{
				shared_ptr<Binding_Card> bindingPtr
					(dynamic_pointer_cast<Binding_Card>(basePtr));
				fout.write(reinterpret_cast<char*>(bindingPtr.get()), sizeof *bindingPtr);
			}
		}
		fout.close();
	}
}

void SystemBase::load()
{
	ifstream fin;
	fin.open("./file/card/1000.dat", ios::binary);
	if (fin)
	{
		Deposit_Card receiver;
		fin.read(reinterpret_cast<char*>(&receiver), sizeof Binding_Card);
		cout << receiver.getCardholderName() << endl;
	}
}

int SystemBase::getValidNumber(const int begin, const int end)
{
	cout << "请输入选择的数字:" << endl;
	cout << ">>> ";
	int myNumber = -1;
	cin >> myNumber;
	cin.ignore();
	cin.clear();
	while (!(myNumber >= begin&&myNumber < end))
	{
		cout << "输入无效, 请重新输入数字: " << endl;
		cout << ">>> ";
		cin >> myNumber;
		cin.ignore();
		cin.clear();
	}
	return myNumber;
}
