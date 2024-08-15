#pragma once
#include "service.h"
#include "account.h"

class Deposit : public Service
{
private:
	int _amountDeposit;
	int _monthDuration;
	int _interestRate;
public:

    int getInterestRate();

    Deposit(Account& account, int serviceTime,  shared_ptr<Worker> worker, int amountDeposit, int monthDuration, int interestRate);

    int getMonthDuration();

    int GetAmountDeposit();
	int CalculateInterest();
	void print();
	void ProvideService() override;
    ostream &put(ostream &) override;
};