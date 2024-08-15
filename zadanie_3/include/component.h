//
// Created by Kacper Murygin on 06/04/2022.
//

#ifndef ZADANIE3_COMPONENT_H
#define ZADANIE3_COMPONENT_H
#include <string>
using namespace std;
class Component{
private:
    string name;
    int percentage;
public:
    Component();
    Component(string Name, int Percentage);
    string getName() const;
    int getPercentage() const;

    void setName(string newName);
    void setPercentage(int newPercentage);

    bool operator>(Component secondArgument) const;
    bool operator<(const Component& secondArgument) const;

    bool operator==(const Component& second_argument) const;
    bool operator!=(const Component& second_argument) const;

    friend ostream& operator<<(ostream& os, const Component& component);
};

ostream& operator<<(ostream& os, const Component& component);

#endif //ZADANIE3_COMPONENT_H
