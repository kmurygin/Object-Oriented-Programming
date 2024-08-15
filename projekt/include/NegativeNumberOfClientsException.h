//
// Created by Kacper Murygin on 01/06/2022.
//

#ifndef BANK_NEGATIVENUMBEROFCLIENTSEXCEPTION_H
#define BANK_NEGATIVENUMBEROFCLIENTSEXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;

class NegativeNumberOfClientsException: public std::invalid_argument{
public:
    NegativeNumberOfClientsException(int wrongNumber);
};

#endif //BANK_NEGATIVENUMBEROFCLIENTSEXCEPTION_H
