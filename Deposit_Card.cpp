#include "Deposit_Card.h"
using namespace std;

Deposit_Card::~Deposit_Card()
{
}

void Deposit_Card::deposit(const double money)
{
	setBalance(getBalance() + money);
	cout << "成功充值" << money << "元, 现在有" << getBalance() << "元" << endl;
}



void Deposit_Card::transfer(Card& otherCard, const double money)
{
	if (getBalance() < 0)
	{
		cout << "卡处于透支状态, 不能转出, 请充值" << endl;
		return;
	}
	if(getBalance()<money)
	{
		cout << "卡里只有" << getBalance() << "元, 不足" << money << "元, 无法转账" << endl;
		return;
	}
	setBalance(getBalance() - money);
	otherCard.receiveMoney(money);
	cout << "成功转给" << otherCard.getCardholderName() << " " << money << "元" << endl;
}

Deposit_Card::Deposit_Card(
	const std::string& issueDate, 
	const std::string& holderName, 
	double balance, 
	double overdraft)
	:Card(issueDate, holderName)
{
	setOverdraft(overdraft);
	setBalance(balance);
}

Deposit_Card::Deposit_Card(const Json::Value& json)
	:Card(json)
{
	setOverdraft(json["overdraft"].asDouble());
	if (json["balance"].isArray())
	{
		setBalance(json["balance"][1].asDouble());
	}
	else setBalance(json["balance"].asDouble());
}

void Deposit_Card::pay()
{
	cout << "你好, " << getCardholderName() << ", 欢迎使用储蓄卡部分支付" << endl;
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
		else cout << "成功取消" << endl;
	}
	else if (temp.getHowMuch() <= this->getBalance() + this->getOverdraft())
	{
		cout << "请确认你的消费信息:" << endl;
		cout << temp.toJson().toStyledString() << "一共消费 " << temp.getHowMuch() << " 元" << endl;
		cout << "您的卡可以透支支付, 请问是否透支支付?" << endl;
		if (confirm())
		{
			this->setBalance(getBalance() - temp.getHowMuch());
			this->_record.append(temp.toJson());
			cout << "成功支付, 余额为负代表透支状态" << endl;
		}
		else cout << "成功取消透支支付" << endl;
	}
	else
	{
		cout << "对不起, 钱不够, 再看:)" << endl;
	}
	/* fixme */
	cout << _record.toStyledString() << endl;
}

void Deposit_Card::query()
{
	cout << "Call query() from Deposit" << endl;
}

void Deposit_Card::receiveMoney(const double money)
{
		setBalance(getBalance() + money);
}

Json::Value Deposit_Card::toJson()
{
	Json::Value object;
	object["issueDate"] = Json::Value(getIssueDate());
	object["holderName"] = Json::Value(getCardholderName());

	object["balance"] = Json::Value(getBalance());
	object["overdraft"] = Json::Value(getOverdraft());

	object["record"] = _record;
	return object;
}

shared_ptr<Card> Deposit_Card::toCard(const Json::Value& json)
{
	/* 基类卡信息 */
	string issueDate = "None";
	string holderName = "None";
	double balance = 0.0;

	/* 储蓄卡信息 */
	double overdraft = 0.0;

	/* json读入信息 */
	issueDate = json["issueDate"].asString();
	holderName = json["holderName"].asString();
	balance = json["balance"].asDouble();
	overdraft = json["overdraft"].asDouble();

	/* 创建卡片对象智能指针 */
	shared_ptr<Card> smart_ptr
		(new Deposit_Card(issueDate, holderName, balance, overdraft));
	return smart_ptr;
}

double Deposit_Card::getOverdraft() const
{
	return __overdraft;
}

double Deposit_Card::getBalance() const
{
	return __balance;
}

void Deposit_Card::setOverdraft(double overdraft)
{
	__overdraft = overdraft;
}

void Deposit_Card::setBalance(double balance)
{
	__balance = balance;
}

std::string Deposit_Card::getClassName()
{
	return "Deposit_Card";
}
