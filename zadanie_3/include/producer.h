//
// Created by Kacper Murygin on 01/04/2022.
//

#ifndef ZADANIE3_PRODUCER_H
#define ZADANIE3_PRODUCER_H
#include <iostream>
#include <string>
using namespace std;

class Producer {
private:
    string name;
    string city;
    string postCode;
    string street;
    int number;
public:
    Producer();
    Producer(string Name, string City, string Street, string PostCode, int Number);
    string getName();
    string getCity();
    string getPostCode();
    string getStreet();
    int getNumber();
//    string getFullAddress();

    void setName(string newName);
    void setCity(string newCity);
    void setPostCode(string newPostCode);
    void setStreet(string newStreet);
    void setNumber(int newNumber);

    void setAddress(string newCity, string newPostCode, string newStreet, int newNumber);

    bool operator==(const Producer& second_argument) const;
    bool operator!=(const Producer& second_argument) const;

    friend std::ostream& operator<<(ostream& os, const Producer& producer);
};
ostream& operator<<(std::ostream& os, const Producer& producer);
#endif //ZADANIE3_PRODUCER_H
