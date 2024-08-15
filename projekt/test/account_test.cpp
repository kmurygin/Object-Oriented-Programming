//
// Created by Kacper Murygin on 29/05/2022.
//
#include <iostream>
#include <vector>
#include "catch.hh"
#include "../client.h"
#include "../businessClient.h"
#include "../privateClient.h"
#include "../allClients.h"
#include "../allOffers.h"
#include "../offer.h"
#include "../worker.h"
#include "../account.h"
#include "../deposit.h"
#include "../loan.h"
#include "../payment.h"
#include "../transfer.h"
#include "../listService.h"
#include "../negative_account_balance.h"
#include "../NegativeServiceTime.h"
using namespace std;
TEST_CASE("simple tests- account", "[account]"){
    SECTION("Account- constructor"){
        Account account1(1, 100);
        CHECK(account1.GetAccountNumber() == 1);
        CHECK(account1.GetAccountBalance() == 100);
    }
    SECTION("Account- ChangeBalance() method"){
        Account account1(1, 100);
        CHECK(account1.GetAccountNumber() == 1);
        CHECK(account1.GetAccountBalance() == 100);

        account1.ChangeBalance(10);
        CHECK(account1.GetAccountBalance() == 110);
    }
}

TEST_CASE("simple tests- services", "[deposit, loan]"){
    Account account1(1, 100);
    Account account2(2, 200);
    shared_ptr<Worker> worker1 = make_shared<Worker>(1, 100);
    SECTION("deposit- constructor"){
        Deposit deposit1(account1, 10, worker1, 100, 2, 4);
        CHECK(deposit1.GetAmountDeposit() == 100);
        CHECK(deposit1.getInterestRate() == 4);
        CHECK(deposit1.getMonthDuration() == 2);
        CHECK(deposit1.GetServiceTime() == 10);
        CHECK(deposit1.GetWorker() -> getId() == 1);
        CHECK(deposit1.GetWorker() -> getRating() == 100);
        CHECK(deposit1.GetAccount().GetAccountNumber() == 1);
        CHECK(deposit1.GetAccount().GetAccountBalance() == 100);
    }
    SECTION("loan- constructor"){
        Loan loan1(account1, 100, worker1, 270, 50, 24);
        CHECK(loan1.GetAmountLoan() == 270);
        CHECK(loan1.GetLoanMonth() == 24);
        CHECK(loan1.GetLoanRate() == 50);
        CHECK(loan1.GetServiceTime() == 100);
        CHECK(loan1.GetWorker() -> getId() == 1);
        CHECK(loan1.GetWorker() -> getRating() == 100);
        CHECK(loan1.GetAccount().GetAccountNumber() == 1);
        CHECK(loan1.GetAccount().GetAccountBalance() == 100);
    }
    SECTION("payment- constructor"){
        Payment payment1(account1, 27, worker1, 100);
        CHECK(payment1.GetAmountPayment() == 100);
        CHECK(payment1.GetServiceTime() == 27);
        CHECK(payment1.GetWorker() -> getId() == 1);
        CHECK(payment1.GetWorker() -> getRating() == 100);
        CHECK(payment1.GetAccount().GetAccountNumber() == 1);
        CHECK(payment1.GetAccount().GetAccountBalance() == 100);
    }
    SECTION("transfer- constructor"){
        Transfer transfer1(account1, 100, worker1, 10, account2);
        CHECK(transfer1.GetWorker() -> getId() == 1);
        CHECK(transfer1.GetWorker() -> getRating() == 100);
        CHECK(transfer1.GetServiceTime() == 100);
        CHECK(transfer1.GetAmountTransfer() == 10);
        CHECK(transfer1.GetAccount().GetAccountNumber() == 1);
        CHECK(transfer1.GetAccount().GetAccountBalance() == 100);
        CHECK(transfer1.GetAccount2().GetAccountNumber() == 2);
        CHECK(transfer1.GetAccount2().GetAccountBalance() == 200);
    }
    SECTION("list of services"){
        ListService listService1;

        listService1.add_service_deposit(account1, 10, worker1, 100, 2, 4);
        listService1.add_service_loan(account1, 100, worker1, 270, 50, 24);
        listService1.add_service_payment(account1, 27, worker1, 100);
        listService1.add_service_transfer(account1, 100, worker1, 10, account2);

        CHECK(listService1.getServices().size() == 4);
    }

    SECTION("negative service time"){
        Account account2(1000, 200);
        shared_ptr<Worker> worker2 = make_shared<Worker>(1, 100);
        Service service2(account2, 10, worker2);

        CHECK_THROWS_AS(service2.setServiceTime(-2), NegativeServiceTime);
    }

    SECTION("negative account balance"){
        Account account1(1000, 200);
        CHECK(account1.GetAccountNumber() == 1000);
        CHECK(account1.GetAccountBalance() == 200);

        account1.ChangeBalance(100);
        CHECK(account1.GetAccountBalance() == 300);

        account1.ChangeBalance(-100);
        CHECK(account1.GetAccountBalance() == 200);

        CHECK_THROWS_AS(account1.ChangeBalance(-400), NegativeAccountBalance);
    }
}