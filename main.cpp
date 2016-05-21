#include <iostream>
#include "System_User.h"
#include "System_Admin.h"
using namespace std;

void Print(Card& input)
{
	input.pay();
}

int main()
{
	string cardID;
	cout << "��������Ŀ���, �װ����û�(����quit�˳�):" << endl;
	cout << "����admin�������Աģʽ!" << endl;
	cout << ">>> ";
	getline(cin, cardID, '\n');
	while(cardID != "quit")
	{
		if (cardID != "admin")
		{
			UserSystem sys(cardID);
			sys.displayFunction();
			int myChoose = getValidNumber(0, 4);
			while (myChoose != 0)
			{
				switch (myChoose)
				{
				case 1:
					cout << sys.User_ptr->toJson().toStyledString() << endl;;
					break;
				case 2:
					sys.User_ptr->pay();
					break;
				case 3:
					sys.moneyDeal();
					break;
				}
				sys.displayFunction();
				myChoose = getValidNumber(0, 4);
			}
		}else
		{
			AdminSystem sys;
			sys.displayFunction();
			int myChoose = getValidNumber(0, 4);
			while (myChoose != 0)
			{
				switch (myChoose)
				{
				case 1:
					cout << sys.toJson().toStyledString() << endl;
					break;
				case 2:
					sys.pushCard();
					break;
				case 3:
					sys.pop();
					break;
				}
				sys.displayFunction();
				myChoose = getValidNumber(0, 4);
			}

		}
		cout << "��������Ŀ���, �װ����û�(����quit�˳�):" << endl;
		cout << ">>> ";
		getline(cin, cardID, '\n');
	}	
	return 0;
}