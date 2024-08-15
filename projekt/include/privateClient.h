//
// Created by Kacper Murygin on 13/05/2022.
//

#ifndef BANK_PRIVATECLIENT_H
#define BANK_PRIVATECLIENT_H
#include <vector>
#include <iostream>
#include "client.h"
#include "worker.h"
#include "allWorkers.h"
#include "allClients.h"
class PrivateClient : public Client{
protected:
public:
    PrivateClient(int Number, Account Account);
    shared_ptr<Worker> chooseWorker(AllWorkers workers);
    shared_ptr<Offer> chooseOffer(AllOffers offers);
};
#endif //BANK_PRIVATECLIENT_H
