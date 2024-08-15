#pragma once
#include <list>
#include <memory>
#include "service.h"

class ListService
{
private:
	std::list<std::unique_ptr<Service>> services;
public:
	void add_service(Account account, int serviceTime, shared_ptr<Worker> worker);
	void add_service_deposit(Account account, int serviceTime, shared_ptr<Worker> worker, int amountDeposit, int monthDuration, int interestRate);
	void add_service_loan(Account account, int serviceTime, shared_ptr<Worker> worker, int amountLoan, int loanRate, int loanMonth);
	void add_service_payment(Account account, int serviceTime, shared_ptr<Worker> worker, int amountPayment);
	void add_service_transfer(Account account, int serviceTime, shared_ptr<Worker> worker, int amountTransfer, Account account2);
	void add_service_closingAccount(Account account, int serviceTime, shared_ptr<Worker> worker);
	void print_list();
	int calculate_service_duration();

    const list<std::unique_ptr<Service>> &getServices() const;

};
