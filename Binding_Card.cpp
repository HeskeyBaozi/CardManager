#include "Binding_Card.h"
using namespace std;


Binding_Card::Binding_Card(const std::string& cardID, const std::string& issueDate, const std::string& studentID, const std::string& holderName, const std::string& school, double balance, double overdraft)
	:Card(cardID, issueDate, holderName, balance),
	Campus_Card(cardID, issueDate, holderName, balance, studentID, school),
	Deposit_Card(cardID, issueDate, holderName, balance, overdraft)
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
