//
// Created by Kacper Murygin on 13/05/2022.
//

#ifndef ZADANIE4_CLIENT_H
#define ZADANIE4_CLIENT_H
#include <string>
#include <ostream>
#include <iostream>
#include "NoAvailableWorkerException.h"
#include "NoAvailableOfferException.h"
#include "worker.h"
#include "offer.h"
#include "allOffers.h"
#include "allWorkers.h"
#include "account.h"
using namespace std;

class Client {
protected:
    int number;
    Account account;
    //numer konta, balans konta, czy ma kredyt/lokate- na ile
public:
    Client(int Number, Account Account);
    int getNumber();
    Account getAccount();
    virtual ~Client();

    void setNumber(int newNumber);
    void setAccount(Account newAccount);

    bool compareNumber(int Number);
    virtual shared_ptr<Worker> chooseWorker(AllWorkers workers) = 0;
    virtual shared_ptr<Offer> chooseOffer(AllOffers workers) = 0;

    friend ostream& operator<<(ostream& os, const Client& client);
};
ostream& operator<<(ostream& os, const Client& client);
#endif //ZADANIE4_CLIENT_H
