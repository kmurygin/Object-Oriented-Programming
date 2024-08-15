//
// Created by Kacper Murygin on 13/05/2022.
//

#ifndef BANK_NOSUCHOFFEREXCEPTION_H
#define BANK_NOSUCHOFFEREXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;

class NoSuchOfferException : public std::invalid_argument
{
public:
    NoSuchOfferException(int wrongNumber);
};
#endif //BANK_NOSUCHOFFEREXCEPTION_H
