#pragma once
#include "Card.h"


class Deposit_Card:virtual public Card
{
public:
	/* constructor & destructor */
	explicit Deposit_Card(
		const std::string& issueDate = "",
		const std::string& holderName = "",
		double balance = 0.0,
		double overdraft = 0.0);
	explicit Deposit_Card(const Json::Value& json);
	~Deposit_Card() override;

	/* deposit in*/
	void deposit(const double money);

	/* transfer */
	void transfer(Card& otherCard, const double money);

	/* pay & query */
	void pay() override;
	void query() override;

	/* receive Money */
	void receiveMoney(const double money) override;

	/* to Json */
	Json::Value toJson() override;
	std::shared_ptr<Card> toCard(const Json::Value& json) override;

	/* Getter & Setter */
	double getOverdraft() const;
	double getBalance() const override;

	void setOverdraft(double overdraft);
	void setBalance(double balance) override;


	std::string getClassName() override;
private:
	/*
	* __overdraft: Í¸Ö§¶î¶È
	*/
	double __overdraft;
	double __balance;
};