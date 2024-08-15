#include "transfer.h"
#include "account.h"
#include <iostream>

Transfer::Transfer(Account & account, int serviceTime, shared_ptr<Worker> worker, int amountTransfer, Account & account2) :
Service(account, serviceTime, worker),
_amountTransfer(amountTransfer),
_account2(account2)
{}

int Transfer::GetAmountTransfer()
{
	return _amountTransfer;
}

void Transfer::print()
{
	//std::cout << "Account number: " << _account.GetAccountNumber() << " Service time: " << GetServiceTime() << " Emplopyee id:" << _worker->getId()
	//	<< " Amount to transfer: " << GetAmountTransfer() << " Account to transfer: " << _account2.GetAccountNumber()<<std::endl;

    std::cout << "Client with accout nr: " << _account.GetAccountNumber() << "made transfer to account nr: " <<  _account2.GetAccountNumber()
    << ".Amount to transfer: "<< GetAmountTransfer() << "with help of employee: " << _worker->getId()
    << ". It took " << GetServiceTime() << " time" << std::endl;
}

void Transfer::ProvideService()
{

	_account.ChangeBalance(-_amountTransfer);
	_account2.ChangeBalance(_amountTransfer);
}

Account Transfer::GetAccount2()
{
	return _account2;
}

ostream &Transfer::put(ostream &os) {
    os << "Client with accout nr: " << _account.GetAccountNumber() << "made transfer to account nr: " << _account2.GetAccountNumber()
       << ".Amount to transfer: "<< GetAmountTransfer() << "with help of employee: " << _worker->getId()
       << ". It took " << GetServiceTime() << " time" << std::endl;
    return os;
}