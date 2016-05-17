#include "System.h"
using namespace std;

void CardSystem::displayWelcome()
{
	cout << "======= ��ӭʹ�� =======" << endl;
}

void CardSystem::pushCard()
{
	/* ��ð쿨ʱ�� */
	time_t issueDate = time(nullptr);
	string dateString = ctime(&issueDate);

	/* ��ȡ�ֿ������� */
	cout << "��������?" << endl;
	string myName;
	getline(cin, myName, '\n');

	/* ��ȡ���� */
	cout << "���Ŀ���?" << endl;
	string myCardID;
	getline(cin, myCardID, '\n');

	/* �������Ϊ0 */
	double myBalance = 0.0;

	cout << "�����������Ŀ���?" << endl;
	int myChoose = 0;
	cout << "[1] У԰��\n[2] ���\n[3] �󶨿�" << endl;
	cin >> myChoose;
	cin.ignore();
	cin.clear();
	switch (myChoose)
	{
	case 1:
	{
		/* ��ȡѧ�� */
		cout << "����ѧ��?" << endl;
		string myStudentID;
		getline(cin, myStudentID, '\n');

		/* ��ȡѧԺ */
		cout << "����ѧԺ?" << endl;
		string mySchool;
		getline(cin, mySchool, '\n');

		/* ������������ָ��ָ��������(��̬��) */
		shared_ptr<Card> smartPoint(
			new Campus_Card
			(myCardID, dateString, myName,
				myBalance, myStudentID, mySchool));

		/* ������ָ��ѹ�뿨ջ�� */
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
