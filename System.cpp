#include "System.h"
using namespace std;
typedef Json::Value var;

SystemBase::SystemBase()
{
	load();
}

SystemBase::~SystemBase()
{
	save();
}

void SystemBase::save()
{
	ofstream fout, fout_r;
	fout.open("./file/Fast-CardInfo.json", ios::out);
	if (fout)
	{
		Json::FastWriter writer;
		fout << writer.write(toJson());
	}
	fout_r.open("./file/Styled-CardInfo.json", ios::out);
	if(fout_r)
	{
		Json::StyledWriter writer;
		fout_r << writer.write(toJson());
	}
}

void SystemBase::load()
{
}

Json::Value SystemBase::toJson()
{
	/* 整个卡字典 */
	var dict;
	for(const auto& pair :__cardDictionary)
	{
		/* 将卡片对象添加到卡字典 
		*
		*   key: cardID
		* value: 该卡片的json对象
		*/
		var value(pair.second->toJson());
		dict[pair.first] = value;
	}
	return dict;
}

void SystemBase::pushJson(const Json::Value& json)
{
	for (const auto& cardObj : json)
	{
		if (!cardObj["cardID"].isNull())
		{
			string cardID = cardObj["cardID"].asString();
			bool isCampus = !cardObj["studentID"].isNull() && !cardObj["school"].isNull();
			bool isDeposit = !cardObj["overdraft"].isNull();
			bool isBinding = isCampus&&isDeposit;
			shared_ptr<Card> smart_ptr;
			if(isBinding)
			{
				smart_ptr = dynamic_pointer_cast<Card>(make_shared<Binding_Card>(new Binding_Card(cardObj)));
			}else if(isCampus)
			{
				smart_ptr = dynamic_pointer_cast<Card>(make_shared<Campus_Card>(new Campus_Card(cardObj)));
			}else if(isDeposit)
			{
				smart_ptr = dynamic_pointer_cast<Card>(make_shared<Deposit_Card>(new Deposit_Card(cardObj)));
			}
			__cardDictionary.emplace(cardID, smart_ptr);
		}		
	}
}

int SystemBase::getValidNumber(const int begin, const int end)
{
	cout << "请输入选择的数字:" << endl;
	cout << ">>> ";
	int myNumber = -1;
	cin >> myNumber;
	cin.ignore();
	cin.clear();
	while (!(myNumber >= begin&&myNumber < end))
	{
		cout << "输入无效, 请重新输入数字: " << endl;
		cout << ">>> ";
		cin >> myNumber;
		cin.ignore();
		cin.clear();
	}
	return myNumber;
}
