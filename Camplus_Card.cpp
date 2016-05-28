#include "Campus_Card.h"
using namespace std;
typedef Json::Value var;

Campus_Card::~Campus_Card()
{
}

Campus_Card::Campus_Card(const std::string& issueDate,
	const std::string& holderName,
	double balance,
	const std::string& studentID,
	const std::string& school)
	:Card(issueDate, holderName)
{
	setStudentID(studentID);
	setSchool(school);
	Campus_Card::setBalance(balance);
	cout << holderName << ' ' << studentID << " ��У԰��������" << endl;
}

Campus_Card::Campus_Card(const Json::Value& json)
	:Card(json)
{
	setStudentID(json["studentID"].asString());
	setSchool(json["school"].asString());
	if (json["balance"].isArray())
	{
		Campus_Card::setBalance(json["balance"][0].asDouble());
	}
	else Campus_Card::setBalance(json["balance"].asDouble());
}

void Campus_Card::pay()
{
	cout << "���, " << getCardholderName() << ", ��ӭʹ��У԰������֧��" << endl;
	Item temp = createConsumeItem();
	if (temp.getHowMuch() <= this->getBalance())
	{
		cout << "��ȷ�����������Ϣ:" << endl;
		cout << temp.toJson().toStyledString() << "һ������ " << temp.getHowMuch() << " Ԫ" << endl;
		if (confirm())
		{
			this->setBalance(getBalance() - temp.getHowMuch());
			this->_record.append(temp.toJson());
			cout << "�ɹ�֧��" << endl;
		}
		cout << "�ɹ�ȡ��" << endl;
	}
	else
	{
		cout << "�Բ���, Ǯ����, �ٿ�:)" << endl;
	}
	/* fixme */
	cout << _record.toStyledString() << endl;
}

void Campus_Card::receiveMoney(const double money)
{
	setBalance(getBalance() + money);
}

Json::Value Campus_Card::toJson()
{
	Json::Value object;
	object["issueDate"] = Json::Value(getIssueDate());
	object["holderName"] = Json::Value(getCardholderName());
	object["balance"] = Json::Value(getBalance());
	object["studentID"] = Json::Value(getStudentID());
	object["school"] = Json::Value(getSchool());
	object["record"] = _record;
	return object;
}

shared_ptr<Card> Campus_Card::toCard(const Json::Value& json)
{
	/* ���࿨��Ϣ */
	string issueDate = "None";
	string holderName = "None";
	double balance = 0.0;

	/* У԰����Ϣ */
	string studentID = "None";
	string school = "None";

	/* json������Ϣ */
	issueDate = json["issueDate"].asString();
	holderName = json["holderName"].asString();
	balance = json["balance"].asDouble();
	studentID = json["studentID"].asString();
	school = json["school"].asString();

	/* ������Ƭ��������ָ�� */
	shared_ptr<Card> smart_ptr
		(new Campus_Card(issueDate, holderName, balance, studentID, school));
	return smart_ptr;
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

double Campus_Card::getBalance() const
{
	return __balance;
}

inline void Campus_Card::setStudentID(const std::string& studentID)
{
	__studentID = studentID;
}

inline void Campus_Card::setSchool(const std::string& school)
{
	__school = school;
}

void Campus_Card::setBalance(double balance)
{
	__balance = balance;
}

std::string Campus_Card::getClassName()
{
	return "Campus_Card";
}
