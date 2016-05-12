#pragma once
#include "Campus_Card.h"
#include "Deposit_Card.h"
class Binding_Card
	:public Campus_Card, public Deposit_Card
{
public:
	/* constructor & destructor */
	Binding_Card(const std::string& cardID,
		const std::string& issueDate, 
		const std::string& studentID, 
		const std::string& holderName, 
		const std::string& school,
		double balance, 
		double overdraft);
	~Binding_Card() override;

	void query() override;
	void pay() override;
};