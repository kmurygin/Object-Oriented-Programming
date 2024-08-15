//
// Created by Kacper Murygin on 01/06/2022.
//

#ifndef BANK_FILEDONOTEXISTEXCEPTION_H
#define BANK_FILEDONOTEXISTEXCEPTION_H
#include <stdexcept>
#include <string>
class FileDoNotExistException : public std::invalid_argument
{
public:
    FileDoNotExistException(std::string fileName);
};
#endif //BANK_FILEDONOTEXISTEXCEPTION_H
