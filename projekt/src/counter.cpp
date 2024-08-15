//
// Created by Kacper Murygin on 31/05/2022.
//

#include "counter.h"
CounterClass::CounterClass(int id) : Machine(id) {}

void CounterClass::setWorker(shared_ptr<Worker> newWorker) {
    this -> worker = newWorker;
}

shared_ptr<Worker> CounterClass::getWorker() {
    return worker;
}
