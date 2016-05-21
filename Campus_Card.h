#pragma once
#include "Card.h"

class Campus_Card:virtual public Card
{
public:
	/* constructor & destructor */
	explicit Campus_Card(
		const std::string& issueDate = "None",
		const std::string& holderName = "None",
		double balance = 0.0,
		const std::string& studentID = "None",
		const std::string& school = "None");
	explicit Campus_Card(const Json::Value& json);
	~Campus_Card() override;

	/* pay & query */
	void query() override;
	void pay() override;

	/* receive Money */
	void receiveMoney(const double money) override;

	/* Json */
	Json::Value toJson() override;
	std::shared_ptr<Card> toCard(const Json::Value& json) override;
	
	/* Getter & Setter */
	std::string getStudentID() const;
	std::string getSchool() const;
	double getBalance() const;

	void setStudentID(const std::string& studentID);
	void setSchool(const std::string& school);
	void setBalance(double balance);

	std::string getClassName() override;

private:
	/*
	* __studentID: Ñ§ºÅ
	*    __school: Ñ§Ôº
	*/
	std::string __studentID;
	std::string __school;
	double __balance;
};


