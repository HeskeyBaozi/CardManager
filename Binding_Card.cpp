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

std::string Binding_Card::getClassName()
{
	return "Binding_Card";
}
