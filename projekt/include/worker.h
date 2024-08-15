//
// Created by Kacper Murygin on 13/05/2022.
//

#ifndef BANK_WORKER_H
#define BANK_WORKER_H
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

class Worker{
private:
    int id;
    double rating;
    bool ifAccessible;
public:
    Worker(int Id, double Rating, bool IfAccessible=true);
    int getId();
    double getRating();
    bool getAccessible();

    void setID(int newID);
    void setRating(double newRating);
    void setAccessibility(bool newAccessibility);

    bool operator>(const Worker& secondWorker) const;
    bool operator<(const Worker& secondWorker) const;

    friend ostream& operator<<(ostream& os, const Worker& worker);
};
ostream& operator<<(ostream& os, const Worker& worker);
#endif //BANK_WORKER_H
