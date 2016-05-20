#pragma once
#include "Binding_Card.h"
#include <fstream>
#include <memory>
#include <string>
#include <map>

class SystemBase
{
public:
	SystemBase();
	virtual ~SystemBase();
	virtual void displayWelcome() = 0;
	virtual void displayFunction() = 0;
	void save();
	void load();

	Json::Value toJson();
	void pushJson(const Json::Value& json);

	static int getValidNumber(const int begin, const int end);	
protected:
	std::map<std::string, std::shared_ptr<Card> > __cardDictionary;
	
	
};