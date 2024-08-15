//
// Created by Kacper Murygin on 13/05/2022.
//

#ifndef BANK_NOSUCHCLIENTINDATABASEEXCEPTION_H
#define BANK_NOSUCHCLIENTINDATABASEEXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;
class NoSuchClientInDatabaseException : public std::invalid_argument
{
public:
    NoSuchClientInDatabaseException(int wrongNumber);

};
#endif //BANK_NOSUCHCLIENTINDATABASEEXCEPTION_H
