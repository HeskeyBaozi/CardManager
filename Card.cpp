#include "Card.h"
using namespace std;

Card::Card(const std::string& issueDate, const std::string& holderName, double balance)
{
	setCardholderName(holderName);
	setIssueDate(issueDate);
	setBalance(balance);
	cout << "恭喜您, 卡办理成功!" << endl;
	cout << "持卡人: " << getCardholderName() << " | 发卡日期: " << getIssueDate() << endl;
}

Card::~Card()
{
	cout << "注销了 " << getCardholderName() << " 的卡" 
		<< endl;
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

string Card::getClassName()
{
	return "Card";
}
