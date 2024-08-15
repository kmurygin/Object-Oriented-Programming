#pragma once
#include "service.h"
#include "account.h"

class Payment : public Service
{
private:
	int _amountPayment;
public:
	Payment(Account &account, int serviceTime, shared_ptr<Worker> worker, int amountPayment);
	int GetAmountPayment();
	void print();
	void ProvideService() override;
    ostream &put(ostream &) override;
};