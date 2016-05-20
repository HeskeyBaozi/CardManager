#include "Deposit_Card.h"
using namespace std;

Deposit_Card::~Deposit_Card()
{
}

void Deposit_Card::deposit(const double money)
{
	setBalance(getBalance() + money);
}

void Deposit_Card::transfer(Card& otherCard, const double money)
{
	setOverdraft(getOverdraft() - money);
	otherCard.setBalance(otherCard.getBalance() + money);
}

Deposit_Card::Deposit_Card(
	const std::string& issueDate, 
	const std::string& holderName, 
	double balance, 
	double overdraft)
	:Card(issueDate, holderName, balance)
{
	setOverdraft(overdraft);
}

Deposit_Card::Deposit_Card(const Json::Value& json)
	:Card(json)
{
	setOverdraft(json["overdraft"].asDouble());
}

void Deposit_Card::pay()
{
	cout << "Call pay() from Deposit" << endl;
}

void Deposit_Card::query()
{
	cout << "Call query() from Deposit" << endl;
}

Json::Value Deposit_Card::toJson()
{
	Json::Value object;
	object["issueDate"] = Json::Value(getIssueDate());
	object["holderName"] = Json::Value(getCardholderName());
	object["balance"] = Json::Value(getBalance());
	object["overdraft"] = Json::Value(getOverdraft());
	return object;
}

shared_ptr<Card> Deposit_Card::toCard(const Json::Value& json)
{
	/* 基类卡信息 */
	string issueDate = "None";
	string holderName = "None";
	double balance = 0.0;

	/* 储蓄卡信息 */
	double overdraft = 0.0;

	/* json读入信息 */
	issueDate = json["issueDate"].asString();
	holderName = json["holderName"].asString();
	balance = json["balance"].asDouble();
	overdraft = json["overdraft"].asDouble();

	/* 创建卡片对象智能指针 */
	shared_ptr<Card> smart_ptr
		(new Deposit_Card(issueDate, holderName, balance, overdraft));
	return smart_ptr;
}

double Deposit_Card::getOverdraft() const
{
	return __overdraft;
}

void Deposit_Card::setOverdraft(double overdraft)
{
	__overdraft = overdraft;
}

std::string Deposit_Card::getClassName()
{
	return "Deposit_Card";
}
