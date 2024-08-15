//
// Created by Kacper Murygin on 01/06/2022.
//

#include "NegativeNumberOfWorkersException.h"

NegativeNumberOfWorkersException::NegativeNumberOfWorkersException(int wrongNumber):
        std::invalid_argument("Number of workers cannot be nagative: " + std::to_string(wrongNumber)){}