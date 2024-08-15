#pragma once
#include <stdexcept>

class NegativeAccountBalance : public std::invalid_argument
{
public:
	NegativeAccountBalance(int wrong_account_balance);
};