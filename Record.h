#pragma once
#include "Item.h"
#include <vector>
class Record
{
public:
	Record();
	~Record();
	friend std::ostream& operator<<(std::ostream& out, const Record& record);

	void push(const Item& item = Item());
private:
	std::vector<Item> __recordVector;
};