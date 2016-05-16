#include "Item.h"
using namespace std;

Item::Item(const int number,
	const std::string& name,
	const double pricePerOne,
	const std::string& date,
	const std::string& place)
	: __number(number),
	__name(name), 
	__pricePerOne(pricePerOne),
	__date(date),
	__place(place)
{
}

Item::Item()
{
	cout << "构造一个项目中:" << endl;
	int number;
	string name;
	double pricePerOne;
	string date;
	string place;
	cout << "请输入数量:" << endl;
	cin >> number;
	cout << "请输入物品名:" << endl;
	cin >> name;
	cout << "请输入单价:" << endl;
	cin >> pricePerOne;
	cout << "请输入购买日期:" << endl;
	cin >> date;
	cout << "请输入地点:" << endl;
	cin >> place;
	__number = number;
	__name = name;
	__pricePerOne = pricePerOne;
	__date = date;
	__place = place;
}

double Item::getTotal() const
{
	return __number*__pricePerOne;
}

ostream& operator<<(ostream& out, const Item& item)
{
	out << "【日期】: " << item.__date << ", 【地点】: " << item.__place
		<< ", 【消费金额】: " << item.__pricePerOne*item.__number << "元" << endl;
	out << "【购买物品】: " << item.__name << ", 【数量】:" << item.__number 
		<< ", 【单价】: " << item.__pricePerOne << "元" << endl;
	return out;
}
