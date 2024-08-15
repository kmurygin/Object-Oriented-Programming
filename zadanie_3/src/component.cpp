//
// Created by Kacper Murygin on 06/04/2022.
//

#include "component.h"
#include <iostream>
string Component::getName() const{
    return name;
}

int Component::getPercentage() const{
    return percentage;
}

void Component::setName(string newName) {
    name = newName;
}

void Component::setPercentage(int newPercentage) {
    percentage = newPercentage;
}

Component::Component(string Name, int Percentage) {
    name = Name;
    percentage = Percentage;
}

Component::Component() {
    name = "";
    percentage = 0;
}

bool Component::operator>(Component secondArgument) const
{
    return percentage > secondArgument.getPercentage();
}

bool Component::operator<(const Component& secondArgument) const
{
    return !(*this > secondArgument);
}

ostream& operator<<(ostream& os, Component const & component) {
    os<<component.getName() << "," << component.getPercentage();
    return os;
}

bool Component::operator==(const Component& second_argument) const
{
    return name == second_argument.getName() && percentage == second_argument.getPercentage();
}

bool Component::operator!=(const Component& second_argument) const
{
    return !(*this == second_argument);
}
