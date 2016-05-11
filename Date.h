#pragma once
#include <string>
class Date
{
public:
	explicit Date(std::string dateString);
private:
	int __year;
	int __month;
	int __day;
};

inline Date::Date(std::string dateString)
	: __year(0), __month(0), __day(0)
{
}
