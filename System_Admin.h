#pragma once
#include "System.h"
class AdminSystem:virtual public SystemBase
{
public:
	void displayWelcome() override;
	void displayFunction() override;
	void pushCard();
	void pop();
};