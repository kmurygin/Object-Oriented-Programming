//
// Created by Kacper Murygin on 13/05/2022.
//

#include "client.h"

int Client::getNumber() {
    return number;
}

Account Client::getAccount()
{
    return account;
}

void Client::setNumber(int newNumber) {
    number = newNumber;
}

void Client::setAccount(Account newAccount)
{
    account = newAccount;
}


Client::Client(int Number, Account Account):
account(Account) {
    number = Number;
}

Client::~Client() {}

bool Client::compareNumber(int Number) {
    return number == Number;
}

ostream& operator<<(ostream& os, const Client& client)
{
    os <<client.number;
    return os;
}