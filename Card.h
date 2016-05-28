#pragma once
#include <iostream>
#include "json/json.h"
#include <ctime>
#include <memory>
#include <string>
class Item;

class Card
{
public:
	/* constructor & destructor */
	explicit Card(const std::string& issueDate,
		const std::string& holderName = "None");
	explicit Card(const Json::Value& json);
	virtual ~Card();
	
	/* query & pay */
	virtual void query() = 0;
	virtual void pay() = 0;

	/* Balance */
	virtual double getBalance() const = 0;
	virtual void setBalance(double balance) = 0;

	/* receive Money */
	virtual void receiveMoney(const double money) = 0;

	/* Json */
	virtual Json::Value toJson() = 0;
	virtual std::shared_ptr<Card> toCardSmartPtr(const Json::Value& json) = 0;

	/* Getter & Setter */
	std::string getIssueDate() const;
	std::string getCardholderName() const;
	

	void setIssueDate(const std::string& issueDate);
	void setCardholderName(const std::string& holderName);


	virtual std::string getClassName();

protected:
	Json::Value _record;
	static Item createConsumeItem();
	static bool confirm();

private:
	/*
	*  __issueDate: 发卡日期
	* __holderName: 持卡人姓名
	*    __balance: 余额
	*/
	std::string __issueDate;
	std::string __holderName;

};

class Item
{
public:
	Item();
	explicit Item(const Json::Value& itemObj);

	Json::Value toJson() const;
	double getHowMuch() const;
private:
	std::string _when;
	std::string _where;
	std::string _what;
	int _howMany;
	double _price;
};

int getValidNumber(const int begin, const int end);
