#include "account.h"
#include "negative_account_balance.h"
#include <iostream>
Account::Account(int accountNumber, int accountBalance)
{
	_accountNumber = accountNumber;
	_accountBalance = accountBalance;
}

int Account::GetAccountNumber()
{
	return _accountNumber;
}

int Account::GetAccountBalance()
{
	return _accountBalance;
}

void Account::ChangeBalance(int amountToChange)
{
	if (GetAccountBalance() + amountToChange >= 0)
	{
		_accountBalance += amountToChange;
		//std::cout << _accountBalance;
	}
	else
	{
		throw NegativeAccountBalance(GetAccountBalance() + amountToChange);
	}
}

