#pragma once
#include "Campus_Card.h"
#include "Deposit_Card.h"
class Binding_Card
	:public Campus_Card, public Deposit_Card
{
public:
	/* constructor & destructor */
	explicit Binding_Card(
		const std::string& issueDate = "None",
		const std::string& studentID = "None",
		const std::string& holderName = "None",
		const std::string& school = "None",
		double balance = 0.0, 
		double overdraft = 0.0);
	~Binding_Card() override;

	void query() override;
	void pay() override;

	/* to Json */
	/* Json ½á¹¹:
	*  string issueDate
	*  
	*
	*
	*
	*
	*
	*
	*/
	Json::Value toJson() override;


	std::string getClassName() override;
};