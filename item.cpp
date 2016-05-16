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
	cout << "����һ����Ŀ��:" << endl;
	int number;
	string name;
	double pricePerOne;
	string date;
	string place;
	cout << "����������:" << endl;
	cin >> number;
	cout << "��������Ʒ��:" << endl;
	cin >> name;
	cout << "�����뵥��:" << endl;
	cin >> pricePerOne;
	cout << "�����빺������:" << endl;
	cin >> date;
	cout << "������ص�:" << endl;
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
	out << "�����ڡ�: " << item.__date << ", ���ص㡿: " << item.__place
		<< ", �����ѽ�: " << item.__pricePerOne*item.__number << "Ԫ" << endl;
	out << "��������Ʒ��: " << item.__name << ", ��������:" << item.__number 
		<< ", �����ۡ�: " << item.__pricePerOne << "Ԫ" << endl;
	return out;
}
