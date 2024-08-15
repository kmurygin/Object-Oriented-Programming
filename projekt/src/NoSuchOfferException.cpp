//
// Created by Kacper Murygin on 13/05/2022.
//

#include "NoSuchOfferException.h"

NoSuchOfferException::NoSuchOfferException(int wrongNumber):
        std::invalid_argument("No such offer in database, number: " + std::to_string(wrongNumber)){}