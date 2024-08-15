//
// Created by Kacper Murygin on 25/05/2022.
//

#include "simulation.h"
#include <random>
#include <memory>
#include "machine.h"
#include "payment.h"
#include "randomData.h"
#include "closingAccount.h"
#include "loan.h"
#include "transfer.h"
#include "deposit.h"
#include <chrono>
enum BankService{
    CashDispense, //0
    CashDepositMachine, //1
    Counter, //2
    AccountHandling, //3
    Information //4
};

enum CounterOption{
    deposit, // lokata
    payment, // 
    transfer, // transfer
    loan
};

void Simulation::setTimeSimulation(int newTime) {
    timeSimulation = newTime;
}

void Simulation::setNumberOfWorkers(int newWorkers) {
    numberOfWorkers = newWorkers;
}

void Simulation::setNumberOfPrivateClients(int newClients) {
    number0fPrivateClients = newClients;
}

void Simulation::setNumberOfBusinessClients(int newClients) {
    numberOfBusinessClients = newClients;
}

int Simulation::getTimeSimulation() {
    return timeSimulation;
}

int Simulation::getNumberOfWorkers() {
    return numberOfWorkers;
}

int Simulation::getNumberOfPrivateClients() {
    return number0fPrivateClients;
}

int Simulation::getNumberOfBusinessClients() {
    return numberOfBusinessClients;
}

Simulation::Simulation(int TimeSimulation, int NumberOfWorkers, int Number0fPrivateClients, int NumberOfBusinessClients){
    if(TimeSimulation >= 0)
        this -> timeSimulation = TimeSimulation;
    else
        throw(NegativeTimeSimulationException(TimeSimulation));

    if (NumberOfWorkers >= 0)
        this->numberOfWorkers = NumberOfWorkers;
    else
        throw (NegativeNumberOfWorkersException(NumberOfWorkers));

    if(Number0fPrivateClients >= 0)
        this -> number0fPrivateClients = Number0fPrivateClients;
    else{
        throw (NegativeNumberOfClientsException(NumberOfBusinessClients));
    }

    if(NumberOfBusinessClients >= 0)
        this -> numberOfBusinessClients = NumberOfBusinessClients;
    else
        throw (NegativeNumberOfClientsException(NumberOfBusinessClients));

    this -> allWorkers = createRandomWorkers(numberOfWorkers);
    this -> allClients = createRandomClients(number0fPrivateClients, numberOfBusinessClients);
}

int Simulation::start(string fileNameOutput) {
    try{
        File fileOutput(fileNameOutput);

    shared_ptr<Client> client;
    shared_ptr<Client> clientToTransfer;
    shared_ptr<Worker> worker;
    shared_ptr<Worker> AccountWorker;
    shared_ptr<Worker> InformationWorker;
    shared_ptr<Worker> CounterWorker;
    shared_ptr<Worker> machineWorker = make_shared<Worker>(1000, 0, false);

    list<shared_ptr<CounterClass>> allCounters;
    for (int i=0; i<3; i++){
        shared_ptr<CounterClass> counterToAdd = make_shared<CounterClass>(i);
        allCounters.push_back(counterToAdd);
    }


    Machine machine(1);
    Machine machine2(2);
    Machine machine3(3);
    Machine machine4(4);
    Machine machine5(5);

    this -> createQueues();

    std::cout << "<---------ROZPOCZYNANIE SYMULACJI--------->" << std::endl;
    printArguments();
    std::cout << endl;
    printQueues();

    for (int i = 0; i < timeSimulation; i++) {
        std::cout << endl;
        std::cout << i << " iteration" << endl;
        std::cout << endl;
        if(!cashDispenser.empty()){
            if (machine2.GetTimeToChangeClient() == i)
            {
                try {
                    client = cashDispenser.front();
                    cashDispenser.pop();
                    cout << "For client " << client->getNumber() << " was chosen machine " << endl;

                    // przygotuje dane do service i list service
                    Account acc = client->getAccount();
                    int amount = RandomValueToPayment(client->getAccount().GetAccountBalance());
                    int time = 1;

                    // updatuje kiedy odblokowywuje sie maszyna
                    machine2.ChangeTimeToChangeClient(i, time);

                    Payment pay(acc, time, machineWorker, amount);
                    listService.add_service_payment(acc, time, machineWorker, amount);
                    pay.ProvideService();
                    pay.print();
                    fileOutput.writeToFile(pay);
                    std::chrono::seconds dura(2);
                    std::this_thread::sleep_for(dura);
                }
                catch (NoAvailableWorkerException) {
                    cashDispenser.push(client);
                }

            }
        }
        if(!cashDepositMachine.empty()){
            if (machine.GetTimeToChangeClient() == i)
            {
                try {
                    // tutaj tworze sobie workera ktory tak naprawde jestsztuczny bo to maszyna a jest mi potrzebny do service

                    client = cashDepositMachine.front();
                    cashDepositMachine.pop();
                    cout << "For client " << client->getNumber() << " was chosen machine " << endl;

                    // przygotuje dane do service i list service
                    Account acc2 = client->getAccount();
                    int amount = RandomValueToPayment(client->getAccount().GetAccountBalance());
                    int time = 1;

                    // updatuje kiedy odblokowywuje sie maszyna
                    machine.ChangeTimeToChangeClient(i, time);


                    Payment pay(acc2, time, machineWorker, -amount);
                    listService.add_service_payment(acc2, time, machineWorker, -amount);
                    pay.ProvideService();
                    pay.print();
                    fileOutput.writeToFile(pay);
                    std::chrono::seconds dura(2);
                    std::this_thread::sleep_for(dura);
                }
                catch (NoAvailableWorkerException) {
                    cashDepositMachine.push(client);
                }

            }
        }
        if(!counter.empty()){
            for (const auto &chosenCounter: allCounters){
            if (chosenCounter -> GetTimeToChangeClient() == i) {
                if (chosenCounter -> getWorker()){
                    shared_ptr<Worker> workerToChange = chosenCounter -> getWorker();
                    workerToChange ->setAccessibility(true);
                }
                try {
                    client = counter.front();
                    counter.pop();
                    CounterWorker = client->chooseWorker(allWorkers);
                    chosenCounter -> setWorker(CounterWorker);
                    cout << "For client " << client->getNumber() << "was chosen worker " << CounterWorker->getId()
                         << endl;

                    Account acc2 = client->getAccount();
                    int rating = CounterWorker->getRating();
                    int time = RandomTimeToHandle(rating);
                    //musimy wylosowac co chcemy zrobic w kasie
                    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                    std::mt19937 generator(seed);
                    std::uniform_int_distribution<int> distribution(0, 3);
                    int counterOption = distribution(generator);
                    switch (counterOption) {
                        case deposit: {
                            int balance = acc2.GetAccountBalance();
                            int amount = RandomValueToPayment(balance);
                            int month = RandomDurationMonth();
                            int interestRate = RandomInterestRate();
                            Deposit dep(acc2, time, CounterWorker, amount, month, interestRate);
                            listService.add_service_deposit(acc2, time, CounterWorker, amount, month, interestRate);
                            dep.ProvideService();
                            dep.print();
                            fileOutput.writeToFile(dep);
                            break;
                        }
                        case payment: {
                            int balance = acc2.GetAccountBalance();
                            int amount = RandomValueToPayment(balance);
                            Payment pay(acc2, time, CounterWorker, amount);
                            listService.add_service_payment(acc2, time, CounterWorker, amount);
                            pay.ProvideService();
                            pay.print();
                            fileOutput.writeToFile(pay);
                            break;
                        }
                        case transfer: {
                            int balance = acc2.GetAccountBalance();
                            int amount = RandomValueToPayment(balance);
                            int amountOfClients = allClients.getNumberOfClients();
                            int randomClient = RandomClientId(amountOfClients);
                            clientToTransfer = allClients.getClientByNumber(randomClient);
                            Account accOther = clientToTransfer->getAccount();
                            Transfer trans(acc2, time, CounterWorker, amount, accOther);
                            listService.add_service_transfer(acc2, time, CounterWorker, amount, accOther);
                            trans.ProvideService();
                            trans.print();
                            fileOutput.writeToFile(trans);
                            break;
                        }
                        case loan: {

                            int month = RandomDurationMonth();
                            int interestRate = RandomInterestRate();
                            int balance = acc2.GetAccountBalance();
                            int amount = RandomValueToPayment(balance);
                            Loan loan = Loan(acc2, time, CounterWorker, amount, interestRate, month);
                            listService.add_service_loan(acc2, time, CounterWorker, amount, interestRate, month);
                            loan.ProvideService();
                            loan.print();
                            fileOutput.writeToFile(loan);
                            break;
                        }
                    }

                    // updatuje kiedy odblokowywuje sie maszyna
                    machine5.ChangeTimeToChangeClient(i, time);
                    std::chrono::seconds dura(2);
                    std::this_thread::sleep_for(dura);
                }
                catch (NoAvailableWorkerException) {
                    counter.push(client);
                }
            }
            }
        }
        if(!accountHandling.empty()){
            if (machine4.GetTimeToChangeClient() == i)
            {
                if(AccountWorker)
                    AccountWorker ->setAccessibility(true);
                try {
                    client = accountHandling.front();
                    accountHandling.pop();
                    AccountWorker = client->chooseWorker(allWorkers);
                    cout << "For client " << client->getNumber() << "was chosen worker " << AccountWorker->getId() << endl;
                    Account acc2 = client->getAccount();
                    int rating = AccountWorker->getRating();
                    int time = RandomTimeToHandle(rating);

                    // updatuje kiedy odblokowywuje sie maszyna
                    machine4.ChangeTimeToChangeClient(i, time);
                    ClosingAccount closingAccount= ClosingAccount(acc2, time, AccountWorker);
                    listService.add_service_closingAccount(acc2, 200, AccountWorker);
                    closingAccount.ProvideService();
                    closingAccount.print();
                    fileOutput.writeToFile(closingAccount);
                    std::chrono::seconds dura(2);
                    std::this_thread::sleep_for(dura);
                }
                catch (NoAvailableWorkerException) {
                    accountHandling.push(client);
                }
            }

        }
        if(!information.empty()){
             if (machine3.GetTimeToChangeClient() == i){
                 if(InformationWorker)
                     InformationWorker ->setAccessibility(true);
                try {
                    client = information.front();
                    information.pop();
                    InformationWorker = client->chooseWorker(allWorkers);
                    cout << "For client " << client->getNumber() << "was chosen worker " << InformationWorker->getId() << endl;

                    Account acc2 = client->getAccount();
                    int time = 1;

                    // updatuje kiedy odblokowywuje sie maszyna
                    machine3.ChangeTimeToChangeClient(i, time);
                    Service ser = Service(acc2, time, InformationWorker);
                    ser.ProvideService();
                    listService.add_service(acc2, 100, InformationWorker);
                    ser.print();
                    fileOutput.writeToFile(ser);
                    std::chrono::seconds dura(2);
                    std::this_thread::sleep_for(dura);

                }
                catch(NoAvailableWorkerException){
                    information.push(client);
                }

                 }
        }

    }
    std::cout << "<-----------KONCZENIE SYMULACJI----------->" << std::endl;
    listService.print_list();
    return 0;
    }
    catch(FileDoNotExistException){
        cerr << "File " << fileNameOutput << " does not exist" << endl;
        return 1;
    }
}

void Simulation::printArguments() {
    cout << "Time of simulation: " << timeSimulation << endl;
    cout << "Number of workers: " << numberOfWorkers << endl;
    cout << "Number of private clients: " << number0fPrivateClients << endl;
    cout << "Number of business clients: " << numberOfBusinessClients << endl;
}

void Simulation::printQueues() {
    cout << "Number of people in:" << endl;
    cout << "Cash dispenser: " << cashDispenser.size() << endl;
    cout << "Cash deposit machine: " << cashDepositMachine.size() << endl;
    cout << "Counter: " << counter.size() << endl;
    cout << "Account handling: " << accountHandling.size() << endl;
    cout << "Information: " << information.size() << endl;
}

void Simulation::createQueues() {

    for (const auto &client: allClients.getClients()) {
        std::random_device generator;
        std::uniform_int_distribution<int> distribution(0, 4);
        int serviceChosen = distribution(generator);

        switch (serviceChosen) {
            case CashDispense:
                cashDispenser.push(client);
                break;
            case CashDepositMachine:
                cashDepositMachine.push(client);
                break;
            case Counter:
                counter.push(client);
                break;
            case AccountHandling:
                accountHandling.push(client);
                break;
            case Information:
                information.push(client);
                break;
        }
    }
}

