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
	cout << "����������:" << endl;
	cin >> number;
	cout << "����������:" << endl;
	cin >> name;
	cout << "�����뵥��:" << endl;
	cin >> pricePerOne;
	cout << "�����빺������:" << endl;
	cin >> date;
	cout << "������ص�:" << endl;
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
