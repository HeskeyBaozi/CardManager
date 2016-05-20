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
	explicit Card(const std::string& issueDate = "",
		const std::string& holderName = "",
		double balance = 0.0);
	explicit Card(const Json::Value& json);
	virtual ~Card();
	
	/* query & pay */
	virtual void query() = 0;
	virtual void pay() = 0;

	/* Json */
	virtual Json::Value toJson() = 0;
	virtual std::shared_ptr<Card> toCard(const Json::Value& json) = 0;

	/* Getter & Setter */
	std::string getIssueDate() const;
	std::string getCardholderName() const;
	double getBalance() const;

	void setIssueDate(const std::string& issueDate);
	void setCardholderName(const std::string& holderName);
	void setBalance(double balance);

	virtual std::string getClassName();

protected:
	Json::Value _record;
	static Item createConsumeItem();

private:
	/*
	*  __issueDate: 发卡日期
	* __holderName: 持卡人姓名
	*    __balance: 余额
	*/
	std::string __issueDate;
	std::string __holderName;
	double __balance;


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
