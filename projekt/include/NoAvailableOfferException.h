//
// Created by Kacper Murygin on 13/05/2022.
//

#ifndef BANK_NOAVAILABLEOFFEREXCEPTION_H
#define BANK_NOAVAILABLEOFFEREXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;
class NoAvailableOfferException : public std::invalid_argument
{
public:
    NoAvailableOfferException(int number);

};
#endif //BANK_NOAVAILABLEOFFEREXCEPTION_H
