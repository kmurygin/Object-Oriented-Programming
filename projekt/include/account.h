#pragma once

class Account
{
public:
	Account(int accountNumber, int accountBalance);
	int GetAccountNumber();
	int GetAccountBalance();
	void ChangeBalance(int amountToChange);

private:
	int _accountNumber;
	int _accountBalance;
};
