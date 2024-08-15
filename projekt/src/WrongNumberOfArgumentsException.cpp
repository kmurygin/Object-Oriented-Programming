//
// Created by Kacper Murygin on 01/06/2022.
//

#include "WrongNumberOfArgumentsException.h"
WrongNumberOfArgumentsException::WrongNumberOfArgumentsException(int wrongNumberOfArguments):
        std::invalid_argument("Wrong number of arguments in input file: " + std::to_string(wrongNumberOfArguments)){}
