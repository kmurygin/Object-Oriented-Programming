//
// Created by Kacper Murygin on 31/05/2022.
//

#ifndef BANK_COUNTER_H
#define BANK_COUNTER_H
#include "machine.h"
#include "worker.h"
class CounterClass : public Machine{
private:
    shared_ptr<Worker> worker;
public:
    CounterClass(int id);

    void setWorker(shared_ptr<Worker> newWorker);
    shared_ptr<Worker> getWorker();
};
#endif //BANK_COUNTER_H
