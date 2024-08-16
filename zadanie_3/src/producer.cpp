//
// Created by Kacper Murygin on 01/04/2022.
//

#include "producer.h"

std::string Producer::getName() {
    return name;
}

std::string Producer::getCity() {
    return city;
}

std::string Producer::getPostCode() {
    return postCode;
}

std::string Producer::getStreet() {
    return street;
}

int Producer::getNumber() {
    return number;
}

void Producer::setName(std::string newName) {
    name = newName;
}

void Producer::setCity(std::string newCity) {
    city = newCity;
}

void Producer::setPostCode(std::string newPostCode) {
    postCode = newPostCode;
}

void Producer::setStreet(std::string newStreet) {
    street = newStreet;
}

void Producer::setNumber(int newNumber) {
    number = newNumber;
}

Producer::Producer(std::string name, std::string city, std::string street, std::string postCode, int number) {
    this->name = name;
    this->city = city;
    this->street = street;
    this->postCode = postCode;
    this->number = number;
}

Producer::Producer() {
    name = "";
    city = "";
    street = "";
    postCode = "";
    number = 0;
}

void Producer::setAddress(std::string newCity, std::string newStreet, std::string newPostCode, int newNumber) {
    city = newCity;
    street = newStreet;
    postCode = newPostCode;
    number = newNumber;
}

bool Producer::operator==(const Producer& second_argument) const
{
    return city == second_argument.city && postCode == second_argument.postCode
    && street == second_argument.street && number == second_argument.number;
}

bool Producer::operator!=(const Producer& second_argument) const
{
    return !(*this == second_argument);
}

std::ostream& operator<<(std::ostream& os, const Producer& producer) {
    os <<"name: "<<producer.name <<" city:"<<producer.city<<" postcode:"<<producer.postCode<<" street:"<<producer.street
    <<" number:"<<producer.number;
    return os;
}