#include "Card.h"
using namespace std;

Card::Card(const std::string& issueDate, const std::string& holderName, double balance)
	:_record(Json::arrayValue)
{
	setCardholderName(holderName);
	setIssueDate(issueDate);
	setBalance(balance);
	cout << "恭喜您, 卡办理成功!" << endl;
	cout << "持卡人: " << getCardholderName() << " | 发卡日期: " << getIssueDate() << endl;
}

Card::Card(const Json::Value& json)
{
	setIssueDate(json["issueDate"].asString());
	setCardholderName(json["holderName"].asString());
	setBalance(json["balance"].asDouble());
}

Card::~Card()
{
	cout << "注销了 " << getCardholderName() << " 的卡"
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
	/* _when: 日历时间 */
	time_t temp = time(nullptr);
	_when = ctime(&temp);

	/* _where: 消费地点 */
	cout << "请输入消费地点:" << endl;
	getline(cin, _where, '\n');

	/* _what: 消费物品名字 */
	cout << "请输入消费物品名字:" << endl;
	getline(cin, _what, '\n');

	/* _howMany: 消费数量 */
	cout << "请输入消费数量:" << endl;
	cin >> _howMany;
	cin.ignore();
	cin.clear();

	/* _price: 单价 */
	cout << "请输入单价:" << endl;
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
