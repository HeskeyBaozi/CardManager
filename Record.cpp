#include "Record.h"
using namespace std;

Record::Record()
	:__record()
{
}

void Record::push()
{
	int number;
	string name;
	double pricePerOne;
	string date;
	string place;
	cout << "请输入数量:" << endl;
	cin >> number;
	cout << "请输入名字:" << endl;
	cin >> name;
	cout << "请输入单价:" << endl;
	cin >> pricePerOne;
	cout << "请输入购买日期:" << endl;
	cin >> date;
	cout << "请输入地点:" << endl;
	cin >> place;
	__record.push_back(Item(number, name, 
		pricePerOne, date, place));

}

std::ostream& operator<<(std::ostream& out, const Record& record)
{
	for(auto& item : record.__record)
	{
		cout << item;
	}
	return out;
}
