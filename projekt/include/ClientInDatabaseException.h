//
// Created by Kacper Murygin on 13/05/20222.
//

#ifndef ZADANIE4_CLIENTINDATABASEEXCEPTION_H
#define ZADANIE4_CLIENTINDATABASEEXCEPTION_H
#include <stdexcept>
#include <string>
class ClientInDatabaseException : public std::invalid_argument
{
public:
    ClientInDatabaseException(int wrongNumber);

};

#endif //ZADANIE4_CLIENTINDATABASEEXCEPTION_H
