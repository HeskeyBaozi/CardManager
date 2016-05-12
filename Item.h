#pragma once
#include <iostream>
#include <string>

class Item
{
public:
	Item(const int number,
		const std::string& name,
		const double pricePerOne,
		const std::string& date,
		const std::string& place);
	friend std::ostream& operator<<(std::ostream& out, const Item& item);
private:
	int __number;
	std::string __name;
	double __pricePerOne;
	std::string __date;
	std::string __place;
};