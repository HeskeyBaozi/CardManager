#include "Card.h"
using namespace std;

Card::Card(const std::string& issueDate, const std::string& holderName, double balance)
{
	setCardholderName(holderName);
	setIssueDate(issueDate);
	setBalance(balance);
	cout << "��ϲ��, ������ɹ�!" << endl;
	cout << "�ֿ���: " << getCardholderName() << " | ��������: " << getIssueDate() << endl;
}

Card::Card(const Json::Value& json)
{
	setIssueDate(json["issueDate"].asString());
	setCardholderName(json["holderName"].asString());
	setBalance(json["balance"].asDouble());
}

Card::~Card()
{
	cout << "ע���� " << getCardholderName() << " �Ŀ�" 
		<< endl;
}

std::string Card::getIssueDate() const
{
	return __issueDate;
}

std::string Card::getCardholderName() const
{
	return __holderName;
}

double Card::getBalance() const
{
	return __balance;
}

void Card::setIssueDate(const std::string& issueDate)
{
	__issueDate = issueDate;
}

void Card::setCardholderName(const std::string& holderName)
{
	__holderName = holderName;
}

void Card::setBalance(double balance)
{
	__balance = balance;
}

string Card::getClassName()
{
	return "Card";
}
