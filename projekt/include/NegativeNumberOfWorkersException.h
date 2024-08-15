//
// Created by Kacper Murygin on 01/06/2022.
//

#ifndef BANK_NEGATIVENUMBEROFWORKERSEXCEPTION_H
#define BANK_NEGATIVENUMBEROFWORKERSEXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;

class NegativeNumberOfWorkersException: public std::invalid_argument{
public:
    NegativeNumberOfWorkersException(int wrongNumber);
};

#endif //BANK_NEGATIVENUMBEROFWORKERSEXCEPTION_H
