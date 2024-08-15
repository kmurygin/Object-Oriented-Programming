//
// Created by Kacper Murygin on 01/06/2022.
//

#include "NegativeTimeSimulationException.h"
NegativeTimeSimulationException::NegativeTimeSimulationException(int wrongNumber):
        std::invalid_argument("Time of the simulation cannot be negative: " + std::to_string(wrongNumber)){}