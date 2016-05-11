#pragma once
#include <iostream>
#include <string>
class Card
{
public:
	/* constructor & destructor */
	virtual ~Card();
	Card(const std::string& cardID, const std::string& issueDate,
		const std::string& holderName, double balance);
	
	/* query & pay */
	virtual void query() = 0;
	virtual void pay() = 0;	

	/* Getter & Setter */
	std::string getCardID() const;
	std::string getIssueDate() const;
	std::string getCardholderName() const;
	double getBalance() const;

	void setCardID(const std::string& cardID);
	void setIssueDate(const std::string& issueDate);
	void setCardholderName(const std::string& holderName);
	void setBalance(double balance);
private:
	std::string __cardID;
	std::string __issueDate;
	std::string __holderName;
	double __balance;
};
