//
// Created by Kacper Murygin on 13/05/2022.
//
#ifndef ZADANIE4_ALLCLIENTS_H
#define ZADANIE4_ALLCLIENTS_H
#include <iostream>
#include <vector>
#include "client.h"
#include <string>
#include <memory>
#include <list>
#include "privateClient.h"
#include "businessClient.h"
#include "ClientInDatabaseException.h"
#include "NoSuchClientInDatabaseException.h"
#include "allWorkers.h"
#include "allOffers.h"
using namespace std;

class AllClients {
private:
public:
    list<shared_ptr<Client>> allClients;
    int getNumberOfClients();

    shared_ptr<Client> getClientByNumber(int Number);

    bool checkClientNumber(int Number);
    void addPrivateClient(int Number, Account Account);
    void addBusinessClient(int Number, Account Account);
    void removeClient(int Number);

    void chooseWorkers(AllWorkers Workers);
    void chooseOffers(AllOffers Offers);

    list<shared_ptr<Client>> getClients();
};
#endif //ZADANIE4_ALLCLIENTS_H
