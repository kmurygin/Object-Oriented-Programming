//
// Created by Kacper Murygin on 01/04/2022.
//

#include "producer.h"
using namespace std;

string Producer::getName() {
    return name;
}

string Producer::getCity() {
    return city;
}

string Producer::getPostCode() {
    return postCode;
}

string Producer::getStreet() {
    return street;
}

int Producer::getNumber() {
    return number;
}

void Producer::setName(string newName) {
    name = newName;
}

void Producer::setCity(string newCity) {
    city = newCity;
}

void Producer::setPostCode(string newPostCode) {
    postCode = newPostCode;
}

void Producer::setStreet(string newStreet) {
    street = newStreet;
}

void Producer::setNumber(int newNumber) {
    number = newNumber;
}

Producer::Producer(string Name, string City, string Street, string PostCode, int Number) {
    name = Name;
    city = City;
    street = Street;
    postCode = PostCode;
    number = Number;
}

Producer::Producer() {
    name = "";
    city = "";
    street = "";
    postCode = "";
    number = 0;
}

void Producer::setAddress(string newCity, string newStreet, string newPostCode, int newNumber) {
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

ostream& operator<<(ostream& os, const Producer& producer) {
    os <<"name: "<<producer.name <<" city:"<<producer.city<<" postcode:"<<producer.postCode<<" street:"<<producer.street
    <<" number:"<<producer.number;
    return os;
}