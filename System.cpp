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
	fout.close();
	fout_r.open("./file/Styled-CardInfo.json", ios::out);
	if(fout_r)
	{
		Json::StyledWriter writer;
		fout_r << writer.write(toJson());
	}
	fout_r.close();
}

void SystemBase::load()
{
	ifstream fin;
	fin.open("./file/Fast-CardInfo.json", ios::in);
	if(fin)
	{
		string line;
		Json::Value dictObj;
		getline(fin, line, '\n');
		Json::Reader reader;
		reader.parse(line, dictObj);
		if (dictObj.isObject())
		{
			pushJson(dictObj);
		}
	}
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
	const auto members = json.getMemberNames();
	for(const auto& cardIDString :members)
	{
		Json::Value cardObj = json[cardIDString];
		if (cardObj.isObject())
		{
			string cardID = cardIDString;

			bool isCampus = !cardObj["studentID"].isNull() && !cardObj["school"].isNull();
			bool isDeposit = !cardObj["overdraft"].isNull();
			bool isBinding = isCampus&&isDeposit;

			if (isBinding)
			{
				shared_ptr<Card> smart_ptr(new Binding_Card(cardObj));
				__cardDictionary.emplace(cardID, smart_ptr);
			}
			else if (isCampus)
			{
				shared_ptr<Card> smart_ptr(new Campus_Card(cardObj));
				__cardDictionary.emplace(cardID, smart_ptr);
			}
			else if (isDeposit)
			{
				shared_ptr<Card> smart_ptr(new Deposit_Card(cardObj));
				__cardDictionary.emplace(cardID, smart_ptr);
			}

		}
	}
}
