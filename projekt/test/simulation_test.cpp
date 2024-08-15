//
// Created by Kacper Murygin on 01/06/2022.
//
#include <iostream>
#include <vector>
#include "catch.hh"
#include "../client.h"
#include "../businessClient.h"
#include "../privateClient.h"
#include "../allClients.h"
#include "../allOffers.h"
#include "../offer.h"
#include "../worker.h"
#include "../account.h"
#include "../simulation.h"
using namespace std;

TEST_CASE("simulation- tests"){
    SECTION("constructor and getters"){
        Simulation simulation(12, 4, 2, 5);
        CHECK(simulation.getTimeSimulation() == 12);
        CHECK(simulation.getNumberOfWorkers() == 4);
        CHECK(simulation.getNumberOfPrivateClients() == 2);
        CHECK(simulation.getNumberOfBusinessClients() == 5);
    }

    SECTION("setters"){
        Simulation simulation(12, 4, 2, 5);
        simulation.setTimeSimulation(2);
        CHECK(simulation.getTimeSimulation() == 2);

        simulation.setNumberOfWorkers(25);
        CHECK(simulation.getNumberOfWorkers() == 25);

        simulation.setNumberOfPrivateClients(20);
        CHECK(simulation.getNumberOfPrivateClients() == 20);

        simulation.setNumberOfBusinessClients(28);
        CHECK(simulation.getNumberOfBusinessClients() == 28);

    }
}