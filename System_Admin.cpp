#include "System_Admin.h"
using namespace std;

void AdminSystem::displayWelcome()
{
	cout << "======= ��ӭʹ��, �ҵ�����! =======" << endl;
}

void AdminSystem::displayFunction()
{
	cout << "[0] �˳�ϵͳ\n";
	cout << "[1] �鿴���п�����Ϣ\n";
	cout << "[2] ����\n";
	cout << "[3] ע����\n";
}

void AdminSystem::pushCard()
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

		/* ����У԰�� */
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
			(dateString, myName,
				myBalance, myStudentID, mySchool));

		/* ������ָ��ѹ�뿨�ֵ��� */
		__cardDictionary.emplace(myCardID, smartPoint);
		break;
	}

	/* ���ɴ�� */
	case 2:
	{
		/* ��ȡ͸֧��� */
		cout << "����͸֧���?" << endl;
		double myOverdraft = 0.0;
		cin >> myOverdraft;
		cin.ignore();
		cin.clear();

		/* ������������ָ��ָ��������(��̬��) */
		shared_ptr<Card> smartPoint(
			new Deposit_Card
			(dateString, myName,
				myBalance, myOverdraft));

		/* ������ָ��ѹ�뿨�ֵ��� */
		__cardDictionary.emplace(myCardID, smartPoint);
		break;
	}

	/* ���ɰ󶨿� */
	case 3:
	{
		/* ��ȡѧ�� */
		cout << "����ѧ��?" << endl;
		string myStudentID;
		getline(cin, myStudentID, '\n');

		/* ��ȡѧԺ */
		cout << "����ѧԺ?" << endl;
		string mySchool;
		getline(cin, mySchool, '\n');

		/* ��ȡ͸֧��� */
		cout << "����͸֧���?" << endl;
		double myOverdraft = 0.0;
		cin >> myOverdraft;
		cin.ignore();
		cin.clear();

		/* ������������ָ��ָ��������(��̬��) */
		shared_ptr<Card> smartPoint(
			new Binding_Card
			(dateString, myStudentID,
				myName, mySchool, myBalance, myOverdraft));

		/* ������ָ��ѹ�뿨�ֵ��� */
		__cardDictionary.emplace(myCardID, smartPoint);
		break;
	}

	/* ѡ����� */
	default:
		cout << "ѡ�����, ����ʧ��" << endl;
		break;
	}
}

void AdminSystem::pop()
{
	cout << "Ŀǰϵͳ���д��ڵĿ���ID��: " << endl;
	for(const auto& name: this->toJson().getMemberNames())
	{
		cout << name << endl;
	}
	cout << "\n������Ҫע���Ŀ���ID:(����quitȡ��)" << endl;
	string myAnswer;
	cout << ">>> ";
	getline(cin, myAnswer, '\n');
	if (myAnswer != "quit")
	{
		if (__cardDictionary.find(myAnswer) != __cardDictionary.end())
		{
			__cardDictionary.erase(myAnswer);
			cout << "�ɹ�ע��: " << myAnswer << endl;
		}
	}
}

