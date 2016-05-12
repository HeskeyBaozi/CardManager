#pragma once
#include "Item.h"
#include <vector>
class Record
{
public:
	Record();
	friend std::ostream& operator<<(std::ostream& out, const Record& record);

	void push();
private:
	std::vector<Item> __record;
};