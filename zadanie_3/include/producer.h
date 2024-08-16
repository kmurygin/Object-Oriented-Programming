//
// Created by Kacper Murygin on 01/04/2022.
//

#ifndef ZADANIE3_PRODUCER_H
#define ZADANIE3_PRODUCER_H
#include <iostream>
#include <string>

class Producer {
private:
    std::string name;
    std::string city;
    std::string postCode;
    std::string street;
    int number;
public:
    Producer();
    Producer(std::string Name, std::string City, std::string Street, std::string PostCode, int Number);
    std::string getName();
    std::string getCity();
    std::string getPostCode();
    std::string getStreet();
    int getNumber();
//    string getFullAddress();

    void setName(std::string newName);
    void setCity(std::string newCity);
    void setPostCode(std::string newPostCode);
    void setStreet(std::string newStreet);
    void setNumber(int newNumber);

    void setAddress(std::string newCity, std::string newPostCode, std::string newStreet, int newNumber);

    bool operator==(const Producer& second_argument) const;
    bool operator!=(const Producer& second_argument) const;

    friend std::ostream& operator<<(std::ostream& os, const Producer& producer);
};
std::ostream& operator<<(std::ostream& os, const Producer& producer);
#endif //ZADANIE3_PRODUCER_H
