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
if (reader.parse(str, root))  // reader将Json字符串解析到root，root将包含Json里所有子元素
{
std::string upload_id = root["uploadid"].asString();  // 访问节点，upload_id = "UP000000"
int code = root["code"].asInt();    // 访问节点，code = 100
}
return 0;
}*/

int main()
{
	UserSystem sys;
	sys.displayFunction();
	int myChoose = sys.getValidNumber(0, 3);
	while(myChoose != 0)
	{
		switch(myChoose)
		{
		case 1:
			cout << sys.User_ptr->toJson().toStyledString() << endl;;
			break;
		}
		myChoose = sys.getValidNumber(0, 3);
	}
	return 0;
}