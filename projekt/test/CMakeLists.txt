cmake_minimum_required(VERSION 3.22)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test ../worker.cpp ../worker.h ../client.cpp
        ../client.h ../privateClient.cpp ../privateClient.h
        ../businessClient.cpp ../businessClient.h ../allClients.cpp
        ../allClients.h ../allOffers.cpp ../allOffers.h ../allWorkers.cpp
        ../allWorkers.h ../NoAvailableOfferException.cpp ../NoAvailableOfferException.h
        ../NoAvailableWorkerException.cpp ../NoAvailableWorkerException.h ../NoSuchClientInDatabaseException.cpp
        ../NoSuchClientInDatabaseException.h ../NoSuchOfferException.cpp ../NoSuchOfferException.h ../NoSuchWorkerException.cpp
        ../NoSuchWorkerException.h ../offer.cpp ../offer.h ../WorkerAlreadyExistsException.cpp ../WorkerAlreadyExistsException.h
        ../ClientInDatabaseException.cpp ../ClientInDatabaseException.h ../OfferAlreadyExistsException.cpp
        ../OfferAlreadyExistsException.h ../simulation.cpp ../simulation.h ../account.cpp ../account.h ../deposit.cpp ../deposit.h
        ../listService.cpp ../listService.h ../loan.cpp ../loan.h ../negative_account_balance.cpp ../negative_account_balance.h
        ../NegativeServiceTime.cpp ../NegativeServiceTime.h ../payment.cpp ../payment.h ../service.cpp ../service.h
        ../transfer.cpp ../transfer.h catch_config.cpp clients_tests.cpp catch.hh account_test.cpp
        ../randomClients.cpp ../randomClients.h ../randomWorkers.cpp ../randomWorkers.h ../file.cpp ../file.h ../closingAccount.cpp ../closingAccount.h
        ../machine.cpp ../machine.h ../randomData.cpp ../randomData.h ../counter.cpp ../counter.h simulation_test.cpp
        ../NegativeNumberOfClientsException.cpp ../NegativeNumberOfClientsException.h ../NegativeNumberOfWorkersException.cpp
        ../NegativeNumberOfWorkersException.h ../NegativeTimeSimulationException.cpp ../NegativeTimeSimulationException.h)

