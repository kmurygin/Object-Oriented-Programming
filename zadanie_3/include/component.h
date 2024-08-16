//
// Created by Kacper Murygin on 06/04/2022.
//

#ifndef ZADANIE3_COMPONENT_H
#define ZADANIE3_COMPONENT_H
#include <string>

class Component{
private:
    std::string name;
    int percentage;
public:
    Component();
    Component(std::string Name, int Percentage);
    std::string getName() const;
    int getPercentage() const;

    void setName(std::string newName);
    void setPercentage(int newPercentage);

    bool operator>(Component secondArgument) const;
    bool operator<(const Component& secondArgument) const;

    bool operator==(const Component& second_argument) const;
    bool operator!=(const Component& second_argument) const;

    friend std::ostream& operator<<(std::ostream& os, const Component& component);
};

std::ostream& operator<<(std::ostream& os, const Component& component);

#endif //ZADANIE3_COMPONENT_H
