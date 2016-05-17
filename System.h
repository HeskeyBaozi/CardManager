#pragma once
#include "Binding_Card.h"
#include <memory>
#include <vector>
class CardSystem
{
public:
	static void displayWelcome();

	void pushCard();
	void pop();
private:
	std::vector<std::shared_ptr<Card> > __system;

};