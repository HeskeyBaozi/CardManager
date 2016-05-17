#include "Card.h"
using namespace std;

Card::Card(const std::string& cardID, const std::string& issueDate, const std::string& holderName, double balance)
{
	setCardID(cardID);
	setCardholderName(holderName);
	setIssueDate(issueDate);
	setBalance(balance);
}

Card::~Card()
{
}

inline std::string Card::getCardID() const
{
	return __cardID;
}

inline std::string Card::getIssueDate() const
{
	return __issueDate;
}

inline std::string Card::getCardholderName() const
{
	return __holderName;
}

double Card::getBalance() const
{
	return __balance;
}

inline void Card::setCardID(const std::string& cardID)
{
	__cardID = cardID;
}

inline void Card::setIssueDate(const std::string& issueDate)
{
	__issueDate = issueDate;
}

inline void Card::setCardholderName(const std::string& holderName)
{
	__holderName = holderName;
}

inline void Card::setBalance(double balance)
{
	__balance = balance;
}
