#include <iostream>
#include "System_User.h"
#include "System_Admin.h"
using namespace std;

void Print(Card& input)
{
	input.pay();
}
/*
int ParseJsonFromString()
{
const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";

Json::Reader reader;
Json::Value root;
if (reader.parse(str, root))  // reader��Json�ַ���������root��root������Json��������Ԫ��
{
std::string upload_id = root["uploadid"].asString();  // ���ʽڵ㣬upload_id = "UP000000"
int code = root["code"].asInt();    // ���ʽڵ㣬code = 100
}
return 0;
}*/

int main()
{
	string whoAmI;
	cout << "���������?" << endl;
	cin >> whoAmI;
	cin.ignore();
	cin.clear();
	if (whoAmI == "Admin")
	{
		AdminSystem sys;
		sys.pushCard();
		Json::StyledWriter writer;
		cout << writer.write(sys.toJson()) << endl;
	}
	if (whoAmI == "User")
	{
		UserSystem sys;
	}
	return 0;
}