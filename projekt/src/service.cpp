#include "service.h"
#include "account.h"
#include <iostream>
#include "NegativeServiceTime.h"
#include "worker.h"

Service::Service(Account &account, int serviceTime, shared_ptr<Worker> worker):
_account(account), _worker(worker), _serviceTime(serviceTime)
{
	if (serviceTime < 0)
	{
		throw NegativeServiceTime(serviceTime);
	}
}

void Service::ProvideService()
{

}

void Service::print()
{
	std::cout << "Account number: " << _account.GetAccountNumber() << " Service time: " << GetServiceTime() << " Emplopyee id:" << _worker->getId() << std::endl;
}

Account Service::GetAccount()
{

	return _account;
}

int Service::GetServiceTime()
{

	return _serviceTime;
}

shared_ptr<Worker> Service::GetWorker()
{
	return _worker;
}

ostream &operator<<(ostream &os, Service &service) {
    return service.put(os);
}

ostream &Service::put(ostream &os) {
    os << "Account number: " << _account.GetAccountNumber() << " Service time: " << GetServiceTime() << " Emplopyee id:" << _worker->getId() << std::endl;
    return os;
}

void Service::setServiceTime(int newServiceTime) {
    if (newServiceTime < 0)
        throw NegativeServiceTime(newServiceTime);
    else
        _serviceTime = newServiceTime;
}
