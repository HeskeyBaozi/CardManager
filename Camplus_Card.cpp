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
	cout << holderName << ' ' << studentID << " 的校园卡创建了" << endl;
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
	cout << "你好, " << getCardholderName() << ", 欢迎使用校园卡部分支付" << endl;
	Item temp = createConsumeItem();
	if (temp.getHowMuch() <= this->getBalance())
	{
		cout << "请确认你的消费信息:" << endl;
		cout << temp.toJson().toStyledString() << "一共消费 " << temp.getHowMuch() << " 元" << endl;
		if (confirm())
		{
			this->setBalance(getBalance() - temp.getHowMuch());
			this->_record.append(temp.toJson());
			cout << "成功支付" << endl;
		}
		cout << "成功取消" << endl;
	}
	else
	{
		cout << "对不起, 钱不够, 再看:)" << endl;
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
	/* 基类卡信息 */
	string issueDate = "None";
	string holderName = "None";
	double balance = 0.0;

	/* 校园卡信息 */
	string studentID = "None";
	string school = "None";

	/* json读入信息 */
	issueDate = json["issueDate"].asString();
	holderName = json["holderName"].asString();
	balance = json["balance"].asDouble();
	studentID = json["studentID"].asString();
	school = json["school"].asString();

	/* 创建卡片对象智能指针 */
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
