#pragma once
#include "System.h"

class UserSystem:virtual public SystemBase
{
public:
	UserSystem();
	void displayWelcome() override;
	void displayFunction() override;

	/* ���� */
	std::shared_ptr<Card> User_ptr;
};