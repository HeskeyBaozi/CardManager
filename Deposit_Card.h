#pragma once
#include "Card.h"
class Deposit_Card:virtual public Card
{
public:
	/* constructor & destructor */
	Deposit_Card(const std::string& cardID,
		const std::string& issueDate,
		const std::string& holderName,
		double balance,
		double overdraft);
	~Deposit_Card() override;

	/* deposit in*/
	void deposit(const double money);

	/* transfer */
	void transfer(Card& otherCard, const double money);

	/* pay & query */
	void pay() override;
	void query() override;

	/* Getter & Setter */
	double getOverdraft() const;

	void setOverdraft(double overdraft);

private:
	/*
	* __overdraft: Í¸Ö§¶î¶È
	*/
	double __overdraft;
};