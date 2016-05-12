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

Deposit_Card::Deposit_Card(const std::string& cardID, const std::string& issueDate, const std::string& holderName, double balance, double overdraft)
	:Card(cardID, issueDate, holderName, balance)
{
	setOverdraft(overdraft);
}

void Deposit_Card::pay()
{
	cout << "Call pay() from Deposit" << endl;
}

void Deposit_Card::query()
{
	cout << "Call query() from Deposit" << endl;
}

double Deposit_Card::getOverdraft() const
{
	return __overdraft;
}

void Deposit_Card::setOverdraft(double overdraft)
{
	__overdraft = overdraft;
}
