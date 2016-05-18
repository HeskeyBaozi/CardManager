#include "System.h"
using namespace std;

SystemBase::~SystemBase()
{
}

void SystemBase::pushCard()
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
			/* ������ָ�밲ȫת��Ϊ������ָ�� */
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
	cout << "������ѡ�������:" << endl;
	cout << ">>> ";
	int myNumber = -1;
	cin >> myNumber;
	cin.ignore();
	cin.clear();
	while (!(myNumber >= begin&&myNumber < end))
	{
		cout << "������Ч, ��������������: " << endl;
		cout << ">>> ";
		cin >> myNumber;
		cin.ignore();
		cin.clear();
	}
	return myNumber;
}
