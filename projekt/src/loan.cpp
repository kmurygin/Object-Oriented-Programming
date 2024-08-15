#include "loan.h"
#include "account.h"
#include <iostream>

Loan::Loan(Account& account, int serviceTime, shared_ptr<Worker> worker, int amountLoan, int loanRate, int loanMonth):
	Service(account, serviceTime, worker),
	_amountLoan(amountLoan),
	_loanRate(loanRate),
	_loanMonth(loanMonth)
{}

int Loan::GetAmountLoan()
{
	return _amountLoan;
}

int Loan::CalculateWholeLoan()
{
	int costsOfTheloan = _amountLoan;
	costsOfTheloan = _amountLoan  + _amountLoan * ( _loanRate * _loanMonth) / 100;
	return costsOfTheloan;
}

int Loan::GetLoanMonth()
{
	return _loanMonth;
}

int Loan::GetLoanRate()
{
	return _loanRate;
}

void Loan::print()
{
	//std::cout << "Account number: " << _account.GetAccountNumber() << " Service time: " << GetServiceTime() << " Emplopyee id:" << _worker->getId()
	//	<< " Duration: " << _loanMonth << " Costs: " << CalculateWholeLoan() << std::endl;

    std::cout << "Client with accout nr: " << _account.GetAccountNumber() << "got loan of: " <<  _amountLoan<< ".Costs: "
              << CalculateWholeLoan() << "on duration of " << _loanMonth << " months" << "with help of employee: "
              << _worker->getId() << ". It took " << GetServiceTime() << " time" << std::endl;
}


void Loan::ProvideService()
{

}

ostream &Loan::put(ostream &os) {
    os << "Client with accout nr: " << _account.GetAccountNumber() << "got loan of: " <<  _amountLoan<< ".Costs: "
       << CalculateWholeLoan() << "on duration of " << _loanMonth << " months" << "with help of employee: "
       << _worker->getId() << ". It took " << GetServiceTime() << " time" << std::endl;

    return os;
}
