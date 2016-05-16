#include "Record.h"
using namespace std;

Record::Record()
	:__recordVector()
{
	cout << "Record 生成了" << endl;
}

Record::~Record()
{
	cout << "Record 消失了" << endl;
}

void Record::push(const Item& item)
{
	__recordVector.push_back(item);
}


std::ostream& operator<<(std::ostream& out, const Record& record)
{
	for(const auto& item : record.__recordVector)
	{
		cout << item;
	}
	return out;
}
