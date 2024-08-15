#include <iostream>
#include <vector>
#include "client.h"
#include "businessClient.h"
#include "privateClient.h"
#include "allClients.h"
#include "allOffers.h"
#include "offer.h"
#include "worker.h"
#include "account.h"
#include "deposit.h"
#include "listService.h"
#include "loan.h"
#include "negative_account_balance.h"
#include "NegativeServiceTime.h"
#include "payment.h"
#include "service.h"
#include "simulation.h"
#include "randomWorkers.h"
#include "randomClients.h"
#include "file.h"
#include <sstream>
#include <cstring>
#include "WrongNumberOfArgumentsException.h"
#include "FileDoNotExistException.h"
using namespace std;

enum Choices{
    file = 1, commandLine = 2
};

int main(int argc, char* argv[]) {
    /*uzytkownik moze podac parametry wywolania programu poprzez linie wywolania lub plik
    argumenty:
    1) nazwa pliku
    2) decyzja- plik 1 lub linia 2
     Jezeli plik:
    3) sciezka do pliku/nazwa - argumenty
    4) sciezka do pliku/nazwa - plik z wynikami
     Jezeli linia:
    3) sciezka do pliku/nazwa - plik z wynikami
    4) czas symulacji
    5) liczba pracownikow
    6) liczba prywatnych klientow
    7) liczba biznesowych klientow
    */
    stringstream stream;
    int numberOfWorkers, numberOfPrivateClients, numberOfBusinessClients;
    int choice, timeOfSimulation;
    std::string fileNameInput;
    std::string fileNameOutput;

    if (argc < 3){
        cerr << "Incorrect number of command line arguments- expected minimum 3 (name of file + your choice + output file), got " << argc << endl;
        return 1;
    }

    stream << argv[1];
    stream >> choice;
    stream.clear();

    switch(choice){
        case file: {
            vector<int> arguments;
            if (argc != 4) {
                cerr << "Incorrect number of command line arguments- expected 4, got" << argc << endl;
                return 1;
            }
            stream << argv[2];
            stream >> fileNameInput;
            stream.clear();

            stream << argv[3];
            stream >> fileNameOutput;
            stream.clear();

            try{
                File sourceFile(fileNameInput);
                arguments = sourceFile.readFile();
            }
            catch(FileDoNotExistException){
                cerr << "File " << fileNameInput << " does not exist" << endl;
                return 1;
            }
            catch(WrongNumberOfArgumentsException){
                cerr << "Wrong number of arguments in input file" << endl;
                return 1;
            }


            timeOfSimulation = arguments[0];
            numberOfWorkers = arguments[1];
            numberOfPrivateClients = arguments[2];
            numberOfBusinessClients = arguments[3];
            break;
        }
        case commandLine:
            //obsluga linii polecen
            if (argc != 7){
                cerr << "Incorrect number of command line arguments- expected 7, got" << argc << endl;
                return 1;
            }
            stream << argv[2];
            stream >> fileNameOutput;
            stream.clear();

            stream << argv[3];
            stream >> timeOfSimulation;
            stream.clear();

            stream << argv[4];
            stream >> numberOfWorkers;
            stream.clear();

            stream << argv[5];
            stream >> numberOfPrivateClients;
            stream.clear();

            stream << argv[6];
            stream >> numberOfBusinessClients;
            stream.clear();

            break;
        default:
            cerr << "Inncorect choice" << endl;
            return 1;
    }

//	//the simulation will start here
//	AllWorkers workers = createRandomWorkers(numberOfWorkers);
//	for (const auto& workerPtr: workers.getWorkers())
//	{
//		std::cout << workerPtr->getId() << " " << workerPtr->getRating() << std::endl;
//	}
//
//	AllClients allClients = createRandomClients(numberOfPrivateClients, numberOfBusinessClients);
//	for (const auto& clientPtr : allClients.getClients())
//	{
//		std::cout << clientPtr->getNumber() << " " << clientPtr->getAccount().GetAccountBalance() << "  " << clientPtr->getAccount().GetAccountNumber() << std::endl;
//	}
    try{
        Simulation simulation1(timeOfSimulation, numberOfWorkers, numberOfPrivateClients, numberOfBusinessClients);
        simulation1.start(fileNameOutput);
    }
	catch(NegativeTimeSimulationException){
        cerr << "Time of the simulation cannot be negative." << endl;
    }
    catch(NegativeNumberOfWorkersException){
        cerr << "Number of workers cannot be negative." << endl;
    }
    catch(NegativeNumberOfClientsException){
        cerr << "Number of clients cannot be negative." << endl;
    }

	return 0;
}
