#include "Campus_Card.h"
using namespace std;

Campus_Card::~Campus_Card()
{
	cout << this->getStudentID() << " ɾ����" << endl;
}

Campus_Card::Campus_Card(const std::string& cardID, const std::string& issueDate, const std::string& holderName, double balance, const std::string& studentID, const std::string& school)
	:Card(cardID, issueDate, holderName, balance)
{
	setStudentID(studentID);
	setSchool(school);
	cout << holderName << ' ' << studentID << " ��У԰��������" << endl;
}

void Campus_Card::pay()
{
	cout << "Call pay() from Campus" << endl;
}

void Campus_Card::query()
{
	cout << "Call query() from Campus" << endl;
}

inline std::string Campus_Card::getStudentID() const
{
	return __studentID;
}

inline std::string Campus_Card::getSchool() const
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
