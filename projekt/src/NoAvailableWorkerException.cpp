//
// Created by Kacper Murygin on 13/05/2022.
//

#include "NoAvailableWorkerException.h"

NoAvailableWorkerException::NoAvailableWorkerException(int number):
        std::invalid_argument("Client already exists in database, number: "){}
