#include "Card.h"
using namespace std;

Card::Card(const std::string& issueDate, const std::string& holderName, double balance)
	:_record(Json::arrayValue)
{
	setCardholderName(holderName);
	setIssueDate(issueDate);
	setBalance(balance);
	cout << "��ϲ��, ������ɹ�!" << endl;
	cout << "�ֿ���: " << getCardholderName() << " | ��������: " << getIssueDate() << endl;
}

Card::Card(const Json::Value& json)
{
	setIssueDate(json["issueDate"].asString());
	setCardholderName(json["holderName"].asString());
	setBalance(json["balance"].asDouble());
}

Card::~Card()
{
	cout << "ע���� " << getCardholderName() << " �Ŀ�"
		<< endl;
}

std::string Card::getIssueDate() const
{
	return __issueDate;
}

std::string Card::getCardholderName() const
{
	return __holderName;
}

double Card::getBalance() const
{
	return __balance;
}

void Card::setIssueDate(const std::string& issueDate)
{
	__issueDate = issueDate;
}

void Card::setCardholderName(const std::string& holderName)
{
	__holderName = holderName;
}

void Card::setBalance(double balance)
{
	__balance = balance;
}

string Card::getClassName()
{
	return "Card";
}

Item Card::createConsumeItem()
{
	Item temp;
	return temp;
}

Item::Item()
	: _when("None"), _where("None"),
	_what("None"), _howMany(0), _price(0)
{
	/* _when: ����ʱ�� */
	time_t temp = time(nullptr);
	_when = ctime(&temp);

	/* _where: ���ѵص� */
	cout << "���������ѵص�:" << endl;
	getline(cin, _where, '\n');

	/* _what: ������Ʒ���� */
	cout << "������������Ʒ����:" << endl;
	getline(cin, _what, '\n');

	/* _howMany: �������� */
	cout << "��������������:" << endl;
	cin >> _howMany;
	cin.ignore();
	cin.clear();

	/* _price: ���� */
	cout << "�����뵥��:" << endl;
	cin >> _price;
	cin.ignore();
	cin.clear();
}

Item::Item(const Json::Value& itemObj)
	:_when(itemObj["when"].asString()),
	_where(itemObj["where"].asString()),
	_what(itemObj["what"].asString()),
	_howMany(itemObj["howMany"].asInt()),
	_price(itemObj["price"].asDouble())
{
}

Json::Value Item::toJson() const
{
	Json::Value itemObj(Json::objectValue);
	itemObj["when"] = Json::Value(_when);
	itemObj["where"] = Json::Value(_where);
	itemObj["what"] = Json::Value(_what);
	itemObj["howMany"] = Json::Value(_howMany);
	itemObj["price"] = Json::Value(_price);
	return itemObj;
}

double Item::getHowMuch() const
{
	return _howMany*_price;
}
