#include "deposit.h"
#include "account.h"
#include <iostream>

Deposit::Deposit(Account& account, int serviceTime, shared_ptr<Worker> worker, int amountDeposit, int monthDuration, int interestRate) :
Service(account, serviceTime, worker),
_amountDeposit(amountDeposit),
_monthDuration(monthDuration),
_interestRate(interestRate)
{}

int Deposit::GetAmountDeposit()
{
	return _amountDeposit;
}

int Deposit::CalculateInterest()
{
	int earnings=0;
	earnings = _amountDeposit * _interestRate / 100 * _monthDuration;
	return earnings;
}

void Deposit::print()
{
	//std::cout << "Account number: " << _account.GetAccountNumber() << " Service time: " << GetServiceTime() << " Emplopyee id:" << _worker->getId()
	//	<< " Deposit amount: " << GetAmountDeposit() << " Duration: " << _monthDuration << " Interest rate: " << _interestRate << std::endl;

    std::cout << "Client with accout nr: " << _account.GetAccountNumber() << "made deposit of: " <<  GetAmountDeposit() << ".Interest rate: "
    << _interestRate << "on duration of " << _monthDuration << " months" << "with help of employee: "
    << _worker->getId() << ". It took " << GetServiceTime() << " time" << std::endl;
}


void Deposit::ProvideService()
{
	_account.ChangeBalance(CalculateInterest());
}

int Deposit::getMonthDuration() {
    return _monthDuration;
}

int Deposit::getInterestRate() {
    return _interestRate;
}


ostream &Deposit::put(ostream &os) {
    os << "Client with accout nr: " << _account.GetAccountNumber() << "made deposit of: " << GetAmountDeposit() << ".Interest rate: "
       << _interestRate << "on duration of " << _monthDuration << " months" << "with help of employee: "
       << _worker->getId() << ". It took " << GetServiceTime() << " time" << std::endl;

    return os;
}