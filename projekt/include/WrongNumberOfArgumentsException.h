//
// Created by Kacper Murygin on 01/06/2022.
//

#ifndef BANK_WRONGNUMBEROFARGUMENTSEXCEPTION_H
#define BANK_WRONGNUMBEROFARGUMENTSEXCEPTION_H
#include <stdexcept>
#include <string>
class WrongNumberOfArgumentsException : public std::invalid_argument
{
public:
    WrongNumberOfArgumentsException(int wrongNumberOfArguments);
};
#endif //BANK_WRONGNUMBEROFARGUMENTSEXCEPTION_H
