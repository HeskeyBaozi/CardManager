#include "Deposit_Card.h"
using namespace std;

Deposit_Card::~Deposit_Card()
{
}

void Deposit_Card::deposit(const double money)
{
	setBalance(getBalance() + money);
	cout << "�ɹ���ֵ" << money << "Ԫ, ������" << getBalance() << "Ԫ" << endl;
}



void Deposit_Card::transfer(Card& otherCard, const double money)
{
	if (getBalance() < 0)
	{
		cout << "������͸֧״̬, ����ת��, ���ֵ" << endl;
		return;
	}
	if(getBalance()<money)
	{
		cout << "����ֻ��" << getBalance() << "Ԫ, ����" << money << "Ԫ, �޷�ת��" << endl;
		return;
	}
	setBalance(getBalance() - money);
	otherCard.receiveMoney(money);
	cout << "�ɹ�ת��" << otherCard.getCardholderName() << " " << money << "Ԫ" << endl;
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
	cout << "���, " << getCardholderName() << ", ��ӭʹ�ô������֧��" << endl;
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
		else cout << "�ɹ�ȡ��" << endl;
	}
	else if (temp.getHowMuch() <= this->getBalance() + this->getOverdraft())
	{
		cout << "��ȷ�����������Ϣ:" << endl;
		cout << temp.toJson().toStyledString() << "һ������ " << temp.getHowMuch() << " Ԫ" << endl;
		cout << "���Ŀ�����͸֧֧��, �����Ƿ�͸֧֧��?" << endl;
		if (confirm())
		{
			this->setBalance(getBalance() - temp.getHowMuch());
			this->_record.append(temp.toJson());
			cout << "�ɹ�֧��, ���Ϊ������͸֧״̬" << endl;
		}
		else cout << "�ɹ�ȡ��͸֧֧��" << endl;
	}
	else
	{
		cout << "�Բ���, Ǯ����, �ٿ�:)" << endl;
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
	/* ���࿨��Ϣ */
	string issueDate = "None";
	string holderName = "None";
	double balance = 0.0;

	/* �����Ϣ */
	double overdraft = 0.0;

	/* json������Ϣ */
	issueDate = json["issueDate"].asString();
	holderName = json["holderName"].asString();
	balance = json["balance"].asDouble();
	overdraft = json["overdraft"].asDouble();

	/* ������Ƭ��������ָ�� */
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
