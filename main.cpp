#include <iostream>
#include "Binding_Card.h"
#include "Record.h"
using namespace std;

void Print(Card& input)
{
	input.pay();
}

int main()
{
	
	Campus_Card myCampusCard("1001", "20160511", "小明", 0.0, "15331097", "软件学院");
	Binding_Card myBindCard("10000", "20160511", "15331097", "何志宇", "软件学院", 88.8, 10.0);
	Print(myBindCard);
	Print(myCampusCard);
	return 0;
}