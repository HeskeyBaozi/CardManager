#include <iostream>
#include "System.h"
using namespace std;

void Print(Card& input)
{
	input.pay();
}

int main()
{
	CardSystem sys;
	sys.displayWelcome();
	sys.pushCard();
	cout << "ok" << endl;
	sys.pop();
	return 0;
}