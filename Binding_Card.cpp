#include "Binding_Card.h"
using namespace std;


Binding_Card::Binding_Card(const string& cardID,
	const string& issueDate,
	const string& studentID,
	const string& holderName,
	const string& school,
	double balance, double overdraft)
	:Campus_Card(cardID, issueDate, holderName, balance, studentID, school),
	Deposit_Card(cardID, issueDate, holderName, balance, overdraft),
	Card(cardID, issueDate, holderName, balance)
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

