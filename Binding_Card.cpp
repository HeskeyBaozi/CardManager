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
	cout << "你好, " << getCardholderName() << ", 欢迎使用绑定卡部分支付" << endl;
	cout << "校园卡余额: " << Campus_Card::getBalance() << " 元\n";
	cout << "储蓄卡余额: " << Deposit_Card::getBalance() << " 元\n";
	cout << "请选择使用哪一种卡支付:\n"
		<<"[1] 校园卡      | [2] 储蓄卡      | [0] 取消支付" << endl;
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
	/* 基类卡信息 */
	string issueDate = "None";
	string holderName = "None";
	double balance = 0.0;

	/* 校园卡信息 */
	string studentID = "None";
	string school = "None";

	/* 储蓄卡信息 */
	double overdraft = 0.0;

	/* json读入信息 */
	issueDate = json["issueDate"].asString();
	holderName = json["holderName"].asString();
	balance = json["balance"].asDouble();
	studentID = json["studentID"].asString();
	school = json["school"].asString();
	overdraft = json["overdraft"].asDouble();

	/* 创建卡片对象智能指针 */
	shared_ptr<Card> smart_ptr
		(new Binding_Card(issueDate, studentID, holderName, school, balance, overdraft));
	return smart_ptr;
}

std::string Binding_Card::getClassName()
{
	return "Binding_Card";
}
