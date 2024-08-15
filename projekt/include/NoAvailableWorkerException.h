//
// Created by Kacper Murygin on 13/05/2022.
//

#ifndef BANK_NOAVAILABLEWORKEREXCEPTION_H
#define BANK_NOAVAILABLEWORKEREXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;
class NoAvailableWorkerException : public std::invalid_argument
{
public:
    NoAvailableWorkerException(int number);

};
#endif //BANK_NOAVAILABLEWORKEREXCEPTION_H
