#pragma once
#include "Binding_Card.h"
#include <memory>
#include <string>
#include <map>
class SystemBase
{
public:
	virtual ~SystemBase();
	virtual void displayWelcome() = 0;
	virtual void displayFunction() = 0;

	void pushCard();
	void pop();
private:
	std::map<std::string, std::shared_ptr<Card> > __cardDictionary;
	static int getValidNumber(const int begin, const int end);
};