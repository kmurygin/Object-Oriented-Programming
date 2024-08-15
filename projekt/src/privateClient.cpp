//
// Created by Kacper Murygin on 13/05/2022.
//

#include "privateClient.h"
using namespace std;

shared_ptr<Worker> PrivateClient::chooseWorker(AllWorkers Workers) {
    vector<shared_ptr<Worker>> workers = Workers.getWorkers();
    for(int i=0; i< Workers.getNumberOfWorkers(); i++) {
        if(workers[i] -> getAccessible()) {
            workers[i]->setAccessibility(false);
            return workers[i];
        }
    }
    throw NoAvailableWorkerException(number);
}

PrivateClient::PrivateClient(int Number, Account Account) :
        Client(Number, Account) {}

shared_ptr<Offer> PrivateClient::chooseOffer(AllOffers Offers) {
    vector<shared_ptr<Offer>> offers = Offers.getOffers();
    for(int i=0; i< Offers.getNumberOfOffers(); i++) {
        if(offers[i] -> getAvailableClients() > 0) {
            offers[i]->decreaseAvailableClients();
            return offers[i];
        }
    }
    throw NoAvailableOfferException(number);
}