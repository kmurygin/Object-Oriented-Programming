//
// Created by Kacper Murygin on 13/05/2022.
//

#include "allWorkers.h"
#include <algorithm>
#include <iterator>
using namespace std;

bool AllWorkers::checkWorkerNumber(int Id) {
    for (const auto &workerPtr: workers) {
        if (workerPtr->getId() == Id)
            return true;
    }
    return false;
}

void AllWorkers::addWorker(int Id, double Rating, bool IfAccessible) {
    if(!checkWorkerNumber(Id)){
        unique_ptr<Worker> addedWorker = make_unique<Worker>(Id, Rating, IfAccessible=true);
        workers.push_back(move(addedWorker));
    }
    else
        throw WorkerAlreadyExistsException(Id);
}

int AllWorkers::getNumberOfWorkers() {
    return workers.size();
}

void AllWorkers::removeWorker(int Id) {
    if (checkWorkerNumber(Id)){
        auto it = find_if(workers.begin(), workers.end(), [&Id](shared_ptr<Worker> obj) {return obj -> getId() == Id;});
        auto index = distance(workers.begin(), it);
        workers.erase(remove(workers.begin(), workers.end(), workers[index]), workers.end());
    }
    else
        throw NoSuchWorkerException(Id);
}

vector<shared_ptr<Worker>> AllWorkers::getWorkers() {
    return workers;
}
