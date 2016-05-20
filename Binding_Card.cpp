#include "Binding_Card.h"
using namespace std;


Binding_Card::Binding_Card(
	const string& issueDate,
	const string& studentID,
	const string& holderName,
	const string& school,
	double balance, double overdraft)
	:Campus_Card(issueDate, holderName, 
		balance, studentID, school),
	Deposit_Card(issueDate, holderName, 
		balance, overdraft),
	Card(issueDate, holderName, balance)
{
}

Binding_Card::Binding_Card(const Json::Value& json)
	:Card(json),Campus_Card(json),Deposit_Card(json)
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
	cout << "pay() from Binding_Card" << endl;
}

Json::Value Binding_Card::toJson()
{
	Json::Value object;
	object["issueDate"] = Json::Value(getIssueDate());
	object["holderName"] = Json::Value(getCardholderName());
	object["balance"] = Json::Value(getBalance());
	object["studentID"] = Json::Value(getStudentID());
	object["school"] = Json::Value(getSchool());
	object["overdraft"] = Json::Value(getOverdraft());
	return object;
}

std::shared_ptr<Card> Binding_Card::toCard(const Json::Value& json)
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
