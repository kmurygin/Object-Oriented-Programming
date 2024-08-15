#pragma once
#include "service.h"
#include "account.h"

class Loan : public Service
{
private:
	int _amountLoan;
	int _loanRate;
	int _loanMonth;
public:
	Loan(Account& account, int serviceTime, shared_ptr<Worker> worker, int amountLoan, int loanRate, int loanMonth);
	int GetAmountLoan();
	int GetLoanMonth();
	int GetLoanRate();
	void print();
	int CalculateWholeLoan();
	void ProvideService() override;
    ostream &put(ostream &) override;
};
