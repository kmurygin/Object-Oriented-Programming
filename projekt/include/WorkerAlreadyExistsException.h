//
// Created by Kacper Murygin on 13/05/2022.
//

#ifndef BANK_WORKERALREADYEXISTSEXCEPTION_H
#define BANK_WORKERALREADYEXISTSEXCEPTION_H
#include <stdexcept>
#include <string>
class WorkerAlreadyExistsException : public std::invalid_argument
{
public:
    WorkerAlreadyExistsException(int wrongID);
};
#endif //BANK_WORKERALREADYEXISTSEXCEPTION_H
