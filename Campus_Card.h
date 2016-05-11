#pragma once
#include "Card.h"

class Campus_Card:virtual public Card
{
public:
	/* constructor & destructor */
	~Campus_Card() override;
	Campus_Card(const std::string& cardID, const std::string& issueDate, const std::string& holderName, double balance, const std::string& studentID, const std::string& school);

	/* pay & query */
	void query() override;
	void pay() override;
	
	/* Getter & Setter */
	std::string getStudentID() const;
	std::string getSchool() const;

	void setStudentID(const std::string& studentID);
	void setSchool(const std::string& school);
private:
	std::string __studentID;
	std::string __school;
};


