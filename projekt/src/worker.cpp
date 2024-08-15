//
// Created by Kacper Murygin on 13/05/2022.
//

#include "worker.h"

double Worker::getRating() {
    return rating;
}

bool Worker::getAccessible() {
    return ifAccessible;
}

int Worker::getId() {
    return id;
}

void Worker::setID(int newID) {
    id = newID;
}
void Worker::setRating(double newRating) {
    rating = newRating;
}

void Worker::setAccessibility(bool newAccessibility) {
    ifAccessible = newAccessibility;
}

Worker::Worker(int Id, double Rating, bool IfAccessible) {
    id = Id;
    rating = Rating;
    ifAccessible = IfAccessible;
}

bool Worker::operator>(const Worker& secondWorker) const
{
    return rating > secondWorker.rating;
}

bool Worker::operator<(const Worker& secondWorker) const
{
    return !(*this > secondWorker);
}

ostream& operator<<(ostream& os, const Worker& worker)
{
    os << worker.id << "," << worker.rating << "," << worker.ifAccessible;
    return os;
}