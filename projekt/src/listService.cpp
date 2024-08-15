#include "listService.h"
#include "deposit.h"
#include "transfer.h"
#include "payment.h"
#include "loan.h"
#include "closingAccount.h"
void ListService::add_service(Account account, int serviceTime, shared_ptr<Worker> worker)
{
	std::unique_ptr<Service> added_service = std::make_unique<Service>(account, serviceTime, worker);
	services.push_back(std::move(added_service));
}

void ListService::add_service_deposit(Account account, int serviceTime, shared_ptr<Worker> worker, int amountDeposit, int monthDuration, int interestRate)
{
	std::unique_ptr<Deposit> added_deposit = std::make_unique<Deposit>(account, serviceTime, worker, amountDeposit, monthDuration, interestRate);
	services.push_back(std::move(added_deposit));
}

void ListService::add_service_loan(Account account, int serviceTime, shared_ptr<Worker> worker, int amountLoan, int loanRate, int loanMonth)
{
	std::unique_ptr<Loan> added_loan = std::make_unique<Loan>(account, serviceTime, worker, amountLoan, loanRate, loanMonth);
	services.push_back(std::move(added_loan));
}

void ListService::add_service_payment(Account account, int serviceTime, shared_ptr<Worker> worker, int amountPayment)
{
	std::unique_ptr<Payment> added_payment = std::make_unique<Payment>(account, serviceTime, worker, amountPayment);
	services.push_back(std::move(added_payment));
}

void ListService::add_service_transfer(Account account, int serviceTime, shared_ptr<Worker> worker, int amountTransfer, Account account2)
{
	std::unique_ptr<Transfer> added_transfer = std::make_unique<Transfer>(account, serviceTime, worker, amountTransfer, account2);
	services.push_back(std::move(added_transfer));
}

void ListService::add_service_closingAccount(Account account, int serviceTime, shared_ptr<Worker> worker)
{
	std::unique_ptr<ClosingAccount> added_closingAccount = std::make_unique<ClosingAccount>(account, serviceTime, worker);
	services.push_back(std::move(added_closingAccount));
}

void ListService::print_list()
{
	for (auto& service_ptr : services)
	{
		service_ptr->print();
	}
}

int ListService::calculate_service_duration()
{
	int total_time = 0;
	for (const auto& service_ptr : services)
	{
		total_time += service_ptr->GetServiceTime();
	}
	return total_time;

	return 0;
}

const list<std::unique_ptr<Service>> &ListService::getServices() const {
    return services;
}
