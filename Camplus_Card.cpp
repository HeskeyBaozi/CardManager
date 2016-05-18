#include "Campus_Card.h"
using namespace std;

Campus_Card::~Campus_Card()
{
	cout << this->getStudentID() << " 删除了" << endl;
}

Campus_Card::Campus_Card(const std::string& issueDate,
	const std::string& holderName, 
	double balance, 
	const std::string& studentID, 
	const std::string& school)
	:Card(issueDate, holderName, balance)
{
	setStudentID(studentID);
	setSchool(school);
	cout << holderName << ' ' << studentID << " 的校园卡创建了" << endl;
}

void Campus_Card::pay()
{
	cout << "Call pay() from Campus" << endl;
}

void Campus_Card::query()
{
	cout << "Call query() from Campus" << endl;
}

std::string Campus_Card::getStudentID() const
{
	return __studentID;
}

std::string Campus_Card::getSchool() const
{
	return __school;
}

inline void Campus_Card::setStudentID(const std::string& studentID)
{
	__studentID = studentID;
}

inline void Campus_Card::setSchool(const std::string& school)
{
	__school = school;
}

std::string Campus_Card::getClassName()
{
	return "Campus_Card";
}
