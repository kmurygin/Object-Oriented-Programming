//
// Created by Kacper Murygin on 13/05/2022.
//

#ifndef BANK_NOSUCHWORKEREXCEPTION_H
#define BANK_NOSUCHWORKEREXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;

class NoSuchWorkerException : public std::invalid_argument
{
public:
    NoSuchWorkerException(int wrongID);
};
#endif //BANK_NOSUCHWORKEREXCEPTION_H
