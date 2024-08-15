#include "closingAccount.h"

ClosingAccount::ClosingAccount(Account& account, int serviceTime, shared_ptr<Worker> worker):
Service(account, serviceTime, worker)
{}

void ClosingAccount::print()
{
	//std::cout << "Account number: " << _account.GetAccountNumber() << " Service time: " << GetServiceTime() << " Emplopyee id:" << _worker->getId() << " is closed" << endl;
    std::cout << "Client with account nr: " << _account.GetAccountNumber() << "has closed their account with the help of employee: " <<
    _worker ->getId() <<". It took: " << GetServiceTime() << std::endl;
}
void ClosingAccount::ProvideService()
{
	// account.Close();
}

ostream &ClosingAccount::put(ostream &os) {
    os << "Client with account nr: " << _account.GetAccountNumber() << "has closed their account with the help of employee: " <<
              _worker ->getId() <<". It took: " << GetServiceTime() << std::endl;

    return os;
}