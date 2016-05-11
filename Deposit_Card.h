#pragma once
#include "Card.h"
class Deposit_Card:virtual public Card
{
public:
	/* constructor & destructor */
	~Deposit_Card() override;
	Deposit_Card(const std::string& cardID, const std::string& issueDate, const std::string& holderName, double balance, double overdraft);

	/* pay & query */
	void pay() override;
	void query() override;

	/* Getter & Setter */
	double getOverdraft() const;

	void setOverdraft(double overdraft);
private:
	double __overdraft;
};