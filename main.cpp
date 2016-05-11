#include <iostream>
#include "Binding_Card.h"
using namespace std;

int main()
{
	Campus_Card myCampusCard("1001", "20160511", "小明", 0.0, "15331097", "软件学院");
	cout << "sizeof(card) = " << sizeof(Card) << endl;
	cout << "sizeof(capums) = " << sizeof(Campus_Card) << endl;
	cout << "sizeof(deposit) = " << sizeof(Deposit_Card) << endl;
	cout << "sizeof(Binding) = " << sizeof(Binding_Card) << endl;
	cout << sizeof(double) << endl;
	Binding_Card myBindCard("10000", "20160511", "15331097", "何志宇", "软件学院", 88.8, 10.0);
	myBindCard.pay();
	myCampusCard.pay();
	return 0;
}