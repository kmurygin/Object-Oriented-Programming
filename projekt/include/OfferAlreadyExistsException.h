//
// Created by Kacper Murygin on 24/04/2022.
//

#ifndef BANK_OFFERALREADYEXISTSEXCEPTION_H
#define BANK_OFFERALREADYEXISTSEXCEPTION_H
#include <stdexcept>
#include <string>
class OfferAlreadyExistsException : public std::invalid_argument
{
public:
    OfferAlreadyExistsException(int wrongNumber);
};
#endif //BANK_OFFERALREADYEXISTSEXCEPTION_H
