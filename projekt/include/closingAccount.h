#pragma once
#include "service.h"
#include "account.h"

class ClosingAccount : public Service
{
public:
	ClosingAccount(Account& account, int serviceTime, shared_ptr<Worker> worker);
	void print();
    ostream &put(ostream &) override;
	void ProvideService() override;
};
