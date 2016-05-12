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

ostream& operator<<(ostream& out, const Item& item)
{
	out << "于" << item.__date << "在" << item.__place
		<< "消费了" << item.__pricePerOne*item.__number << "元" << endl;
	out << "内容为" << item.__name << ", 数量为" << item.__number 
		<< "(单价为" << item.__pricePerOne << "元)" << endl;
	return out;
}
