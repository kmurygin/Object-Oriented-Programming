//
// Created by Kacper Murygin on 25/05/2022.
//

#ifndef BANK_SIMULATION_H
#define BANK_SIMULATION_H
#include <chrono>
#include <thread>
#include <iostream>
#include "allWorkers.h"
#include "allClients.h"
#include "randomClients.h"
#include "randomWorkers.h"
#include "counter.h"
#include <queue>
#include <memory>
#include "listService.h"
#include "file.h"
#include "NegativeNumberOfClientsException.h"
#include "NegativeNumberOfWorkersException.h"
#include "NegativeTimeSimulationException.h"
class Simulation {
private:
    int timeSimulation;
    int numberOfWorkers;
    int number0fPrivateClients;
    int numberOfBusinessClients;

    queue<shared_ptr<Client>> cashDispenser; //0
    queue<shared_ptr<Client>> cashDepositMachine; //1
    queue<shared_ptr<Client>> counter; //2
    queue<shared_ptr<Client>> accountHandling; //3
    queue<shared_ptr<Client>> information; //4

    AllWorkers allWorkers;
    AllClients allClients;
public:
    ListService listService;
    Simulation(int timeSimulation, int numberOfWorkers, int number0fPrivateClients, int numberOfBusinessClients);

    void setTimeSimulation(int newTime);
    void setNumberOfWorkers(int newWorkers);
    void setNumberOfPrivateClients(int newClients);
    void setNumberOfBusinessClients(int newClients);

    int getTimeSimulation();
    int getNumberOfWorkers();
    int getNumberOfPrivateClients();
    int getNumberOfBusinessClients();

    int start(string fileNameOutput);
    void printArguments();
    void printQueues();
    void addWorkers();
    void createQueues();

};


#endif //BANK_SIMULATION_H
