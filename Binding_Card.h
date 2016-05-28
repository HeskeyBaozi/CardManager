#pragma once
#include "Campus_Card.h"
#include "Deposit_Card.h"
class Binding_Card
	:public Campus_Card, public Deposit_Card
{
public:
	double getBalance() const override;
	void setBalance(double balance) override;
	/* constructor & destructor */
	explicit Binding_Card(
		const std::string& issueDate = "None",
		const std::string& studentID = "None",
		const std::string& holderName = "None",
		const std::string& school = "None",
		double balance = 0.0, 
		double overdraft = 0.0);
	explicit Binding_Card(const Json::Value& json);
	~Binding_Card() override;

	void query() override;
	void pay() override;
	void receiveMoney(const double money) override;

	/* Json */
	Json::Value toJson() override;
	std::shared_ptr<Card> toCard(const Json::Value& json) override;


	std::string getClassName() override;
};