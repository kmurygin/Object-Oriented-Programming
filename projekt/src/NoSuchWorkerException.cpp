//
// Created by Kacper Murygin on 13/05/2022.
//

#include "NoSuchWorkerException.h"
NoSuchWorkerException::NoSuchWorkerException(int wrongID):
        std::invalid_argument("No such worker in database, number: " + std::to_string(wrongID)){}