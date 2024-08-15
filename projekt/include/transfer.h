#pragma once
#include "service.h"
#include "account.h"

class Transfer : public Service
{
private:
	int _amountTransfer;
	Account _account2;
public:
	Transfer(Account & account, int serviceTime, shared_ptr<Worker>, int amountTransfer, Account & account2);
	int GetAmountTransfer();
	void print();
	void ProvideService() override;
	Account GetAccount2();
    ostream &put(ostream &) override;
};
