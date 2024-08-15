#pragma once
#include <string>
#include "account.h"
#include "worker.h"

class Service
{
protected:
	Account _account;
	int _serviceTime;
	shared_ptr<Worker> _worker;
public:
	Service(Account &account, int serviceTime, shared_ptr<Worker> worker);

	// metoda wirtualna
	virtual void ProvideService();

    void setServiceTime(int newServiceTime);
    void print();
	Account GetAccount();
	int GetServiceTime();
	shared_ptr<Worker> GetWorker();
    virtual ostream &put(ostream &);

    friend ostream& operator<<(ostream& os, Service& service);
};

ostream& operator<<(ostream& os, Service& service);