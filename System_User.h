#pragma once
#include "System.h"

class UserSystem:virtual public SystemBase
{
public:
	UserSystem();
	explicit UserSystem(std::string cardID);
	void displayWelcome() override;
	void displayFunction() override;
	void moneyDeal();
	std::shared_ptr<Card> User_ptr;
};