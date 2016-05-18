#pragma once
#include "Card.h"

class Campus_Card:virtual public Card
{
public:
	/* constructor & destructor */
	Campus_Card(
		const std::string& issueDate = "None",
		const std::string& holderName = "None",
		double balance = 0.0,
		const std::string& studentID = "None",
		const std::string& school = "None");
	~Campus_Card() override;

	/* pay & query */
	void query() override;
	void pay() override;

	/* to Json */
	//virtual Json::Value toJson();
	
	/* Getter & Setter */
	std::string getStudentID() const;
	std::string getSchool() const;

	void setStudentID(const std::string& studentID);
	void setSchool(const std::string& school);

	std::string getClassName() override;

private:
	/*
	* __studentID: Ñ§ºÅ
	*    __school: Ñ§Ôº
	*/
	std::string __studentID;
	std::string __school;
};


