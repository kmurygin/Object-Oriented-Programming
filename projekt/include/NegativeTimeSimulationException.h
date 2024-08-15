//
// Created by Kacper Murygin on 01/06/2022.
//

#ifndef BANK_NEGATIVETIMESIMULATIONEXCEPTION_H
#define BANK_NEGATIVETIMESIMULATIONEXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;

class NegativeTimeSimulationException: public std::invalid_argument{
public:
    NegativeTimeSimulationException(int wrongNumber);
};

#endif //BANK_NEGATIVETIMESIMULATIONEXCEPTION_H
