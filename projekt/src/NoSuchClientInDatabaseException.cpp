//
// Created by Kacper Murygin on 13/05/2022.
//

#include "NoSuchClientInDatabaseException.h"

NoSuchClientInDatabaseException::NoSuchClientInDatabaseException(int wrongNumber):
        std::invalid_argument("No such client in database, number: " + std::to_string(wrongNumber)){}