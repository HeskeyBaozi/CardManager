#include "Binding_Card.h"
using namespace std;


double Binding_Card::getBalance() const
{
	return 0.0;
}

void Binding_Card::setBalance(double balance)
{
}

Binding_Card::Binding_Card(
	const string& issueDate,
	const string& studentID,
	const string& holderName,
	const string& school,
	double balance, double overdraft)
	:Card(issueDate,holderName),
	Campus_Card(issueDate, holderName, 
		balance, studentID, school),
	Deposit_Card(issueDate, holderName, 
		balance, overdraft)
{
}

Binding_Card::Binding_Card(const Json::Value& json)
	:Campus_Card(json),Deposit_Card(json),Card(json)
{
}

Binding_Card::~Binding_Card()
{
}

void Binding_Card::query()
{
	cout << "query() from Binding_Card" << endl;
}

void Binding_Card::pay()
{
	cout << "���, " << getCardholderName() << ", ��ӭʹ�ð󶨿�����֧��" << endl;
	cout << "У԰�����: " << Campus_Card::getBalance() << " Ԫ\n";
	cout << "������: " << Deposit_Card::getBalance() << " Ԫ\n";
	cout << "��ѡ��ʹ����һ�ֿ�֧��:\n"
		<<"[1] У԰��      | [2] ���      | [0] ȡ��֧��" << endl;
	int myChoose = getValidNumber(0, 3);
	if(myChoose == 1)
	{
		this->Campus_Card::pay();
	}
	else if (myChoose == 2)
	{
		this->Deposit_Card::pay();
	}
}

void Binding_Card::receiveMoney(const double money)
{
	Deposit_Card::setBalance(Deposit_Card::getBalance() + money);
}

Json::Value Binding_Card::toJson()
{
	Json::Value object;
	object["issueDate"] = Json::Value(Campus_Card::getIssueDate());
	object["holderName"] = Json::Value(Campus_Card::getCardholderName());
	
	Json::Value balanceArray(Json::arrayValue);
	balanceArray.append(Json::Value(Campus_Card::getBalance()));
	balanceArray.append(Json::Value(Deposit_Card::getBalance()));
	object["balance"] = balanceArray;

	object["studentID"] = Json::Value(getStudentID());
	object["school"] = Json::Value(getSchool());
	object["overdraft"] = Json::Value(getOverdraft());
	object["record"] = _record;
	return object;
}

std::shared_ptr<Card> Binding_Card::toCardSmartPtr(const Json::Value& json)
{
	/* ���࿨��Ϣ */
	string issueDate = "None";
	string holderName = "None";
	double balance = 0.0;

	/* У԰����Ϣ */
	string studentID = "None";
	string school = "None";

	/* �����Ϣ */
	double overdraft = 0.0;

	/* json������Ϣ */
	issueDate = json["issueDate"].asString();
	holderName = json["holderName"].asString();
	balance = json["balance"].asDouble();
	studentID = json["studentID"].asString();
	school = json["school"].asString();
	overdraft = json["overdraft"].asDouble();

	/* ������Ƭ��������ָ�� */
	shared_ptr<Card> smart_ptr
		(new Binding_Card(issueDate, studentID, holderName, school, balance, overdraft));
	return smart_ptr;
}

std::string Binding_Card::getClassName()
{
	return "Binding_Card";
}
