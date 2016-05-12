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
	out << "��" << item.__date << "��" << item.__place
		<< "������" << item.__pricePerOne*item.__number << "Ԫ" << endl;
	out << "����Ϊ" << item.__name << ", ����Ϊ" << item.__number 
		<< "(����Ϊ" << item.__pricePerOne << "Ԫ)" << endl;
	return out;
}
