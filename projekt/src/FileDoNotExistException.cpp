//
// Created by Kacper Murygin on 01/06/2022.
//

#include "FileDoNotExistException.h"
FileDoNotExistException::FileDoNotExistException(std::string fileName):
        std::invalid_argument("No such file: " + fileName){}