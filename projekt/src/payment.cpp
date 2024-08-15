#include "payment.h"
#include "account.h"
#include <iostream>

Payment::Payment(Account &account, int serviceTime, shared_ptr<Worker> worker, int amountPayment):
Service(account, serviceTime, worker),
_amountPayment(amountPayment)
{
}

int Payment::GetAmountPayment()
{
	return _amountPayment;
}

void Payment::print()
{
	//std::cout << "Client with account: " << _account.GetAccountNumber() << " Service time: " << GetServiceTime() << " Emplopyee id:" << _worker->getId() << " Payment was: " << _amountPayment << std::endl;
    std::cout << "Client with accout nr: " << _account.GetAccountNumber() << "did payment of: " <<  _amountPayment << "with help of employee: " << _worker->getId() << ". It took " << GetServiceTime() << " time" << std::endl;
}

void Payment::ProvideService()
{
	_account.ChangeBalance(_amountPayment);
}

ostream &Payment::put(ostream &os) {
    os << "Client with accout nr: " <<_account.GetAccountNumber() << "did payment of: " << _amountPayment << "with help of employee: " << _worker->getId() << ". It took " << GetServiceTime() << " time" << std::endl;
    return os;
}
