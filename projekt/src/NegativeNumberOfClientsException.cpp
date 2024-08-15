//
// Created by Kacper Murygin on 01/06/2022.
//

#include "NegativeNumberOfClientsException.h"

NegativeNumberOfClientsException::NegativeNumberOfClientsException(int wrongNumber):
        std::invalid_argument("Number of clients cannot be nagative: " + std::to_string(wrongNumber)){}