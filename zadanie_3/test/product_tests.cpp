//
// Created by Kacper Murygin on 05/04/2022.
//
#include <string>
#include "catch.hh"
#include "../inc/product.h"
#include "../inc/producer.h"
#include "../inc/date.h"
#include "../inc/component.h"
#include "../inc/file.h"
//Playlist(string Name, string Author, string DateCreated, string DateModified, vector<string> Songs, double TotalTime)
TEST_CASE("product simple tests", "[product]")
{
    int Volume = 10;
    int NumberLot = 202;
    string Name = "milk";
    Component sugar("sugar", 40);
    Component fat("fat", 20);
    vector<Component> Components = {sugar, fat};
    Product product_milk(Volume, NumberLot, Name, Components);
    product_milk.getProducer().setName("Mlekovita");
    product_milk.getProducer().setAddress("Warszawa", "02-497", "Błękitna", 23);

    SECTION("checkIfContain, getIndexOfComponent"){
        Component gluten("gluten", 30);
        Component lactose("lactose", 10);
        product_milk.addComponent(gluten);
        product_milk.addComponent(lactose);
        CHECK(product_milk.checkIfContains("fat") == 1);
        CHECK(product_milk.checkIfContains("gluten") == 1);
        CHECK(product_milk.checkIfContains("vitamin D") == 0);

        CHECK(product_milk.getIndexOfComponent("sugar") == 0);
        CHECK(product_milk.getIndexOfComponent("fat") == 1);
        CHECK(product_milk.getIndexOfComponent("gluten") == 2);
        CHECK(product_milk.getIndexOfComponent("lactose") == 3);

    }

    SECTION("Number of components and greater than a certain value"){
        Component gluten("gluten", 30);
        Component lactose("lactose", 10);
        product_milk.addComponent(gluten);
        product_milk.addComponent(lactose);

        CHECK(product_milk.numberOfComponents() == 4);
        CHECK(product_milk.numberOfComponentsGreater(20) == 2);
    }

    SECTION("Sorting components- percentage and name"){
        Component gluten("gluten", 30);
        Component lactose("lactose", 10);
        product_milk.addComponent(gluten);
        product_milk.addComponent(lactose);
        CHECK(product_milk.getIndexOfComponent("sugar") == 0);
        CHECK(product_milk.getIndexOfComponent("fat") == 1);
        CHECK(product_milk.getIndexOfComponent("gluten") == 2);
        CHECK(product_milk.getIndexOfComponent("lactose") == 3);

        product_milk.sortComponentsPercentage();
        CHECK(product_milk.getIndexOfComponent("sugar") == 3);
        CHECK(product_milk.getIndexOfComponent("gluten") == 2);
        CHECK(product_milk.getIndexOfComponent("fat") == 1);
        CHECK(product_milk.getIndexOfComponent("lactose") == 0);

        product_milk.sortComponentsName();
        CHECK(product_milk.getIndexOfComponent("fat") == 0);
        CHECK(product_milk.getIndexOfComponent("gluten") == 1);
        CHECK(product_milk.getIndexOfComponent("lactose") == 2);
        CHECK(product_milk.getIndexOfComponent("sugar") == 3);

    }

    SECTION("Modifying component"){
        Component oil("oil", 10);
        product_milk.modifyComponent(sugar, oil);

        CHECK(product_milk.getIndexOfComponent("oil") == 0);
        CHECK(product_milk.getIndexOfComponent("fat") == 1);
    }

    SECTION("Removing component"){
        product_milk.removeComponent("gluten");
        CHECK(product_milk.checkIfContains("gluten") == 0);
    }

    SECTION("Getting component by name"){
        Component sugar = product_milk.getComponent("sugar");
        CHECK(sugar.getName() == "sugar");
        CHECK(sugar.getPercentage() == 40);
    }

    SECTION("changing element values"){
        product_milk.setName("milk2");
        product_milk.setVolume(9);
        product_milk.setNumberLot(222);
        CHECK(product_milk.getName() == "milk2");
        CHECK(product_milk.getVolume() == 9);
        CHECK(product_milk.getNumberLot() == 222);
    }

    SECTION("added element to vector- components"){
        Component chocolate("chocolate", 40);
        Component vanilla("vanilla", 20);
        product_milk.addComponent(chocolate);
        product_milk.addComponent(vanilla);
        vector<Component> componentss = {sugar, fat, chocolate, vanilla};
//        CHECK(product_milk.getComponents() == componentss);
    }
    //product
    SECTION("removing element from vector- components"){
        product_milk.removeComponent("fat");
        vector<Component> componentss = {sugar};
        CHECK(product_milk.getComponents() == componentss);
    }

    SECTION("getting index of an component"){
        vector<Component> componentss = {sugar, fat};
        CHECK(product_milk.getComponents() == componentss);
        CHECK(product_milk.getIndexOfComponent("fat") == 1);
    }

    SECTION("checking if vector contains a certain component"){
        Component cheese("cheese", 40);
        CHECK(product_milk.checkIfContains("fat") == 1);
        CHECK(product_milk.checkIfContains("cheese") == 0);
    }

    SECTION("getting the number of components"){
        Component chocolate("chocolate", 40);
        Component vanilla("vanilla", 20);
        CHECK(product_milk.numberOfComponents() == 2);
        product_milk.addComponent(chocolate);
        product_milk.addComponent(vanilla);
        CHECK(product_milk.numberOfComponents() == 4);
    }

    SECTION("Operator <"){
        Product product1(10, NumberLot, Name, Components);
        Product product2(20, NumberLot, Name, Components);
        CHECK(product1 < product2);
    }

    SECTION("Operator >"){
        Product product1(40, NumberLot, Name, Components);
        Product product2(20, NumberLot, Name, Components);
        CHECK(product1 > product2);
    }

    SECTION("Operator ++"){
        Product product1(20, NumberLot, Name, Components);
        product1++;
        CHECK(product1.getVolume() == 21);
    }

    SECTION("Operator ++ prefix"){
        Product product1(20, NumberLot, Name, Components);
        ++product1;
        CHECK(product1.getVolume() == 21);
    }

    //Producer
    SECTION("Producer- created"){
        Producer producer1("Bakoma", "Warsaw", "Marszałkowska", "02-495", 23);
        Producer producer2("Bakoma", "Warsaw", "Marszałkowska", "02-495", 23);
        CHECK(producer1.getName() == "Bakoma");
        CHECK(producer1 == producer2);
    }

    SECTION("Producer- setAddress"){
        Producer producer1("Bakoma", "Warsaw", "Marszałkowska", "02-495", 23);
        Producer producer2("Bakoma", "Warsaw", "Marszałkowska", "02-495", 23);
        producer2.setAddress("Cracow", "Wawelska", "04-234", 33);
        CHECK(producer2.getName() == "Bakoma");
        CHECK(producer2.getCity() == "Cracow");
        CHECK(producer2.getPostCode() == "04-234");
        CHECK(producer2.getStreet() == "Wawelska");
        CHECK(producer2.getNumber() == 33);

        CHECK(producer1 != producer2);
    }

    //date
    SECTION("Date create"){
        Date date1(1,January,2022);
        Date date2(2,February,2022);
        Date date3(1, January, 2022);
        CHECK(date1 == date3);
    }

    //component
    SECTION("component- created"){
        Component component1("milk", 40);
        CHECK(component1.getName() == "milk");
        CHECK(component1.getPercentage() == 40);
    }

    SECTION("component- getters and setters"){
        Component component1("milk", 40);
        CHECK(component1.getName() == "milk");
        CHECK(component1.getPercentage() == 40);

        component1.setName("gluten");
        component1.setPercentage(70);
        CHECK(component1.getName() == "gluten");
        CHECK(component1.getPercentage() == 70);
    }

    SECTION("component < and >"){
        Component component1("milk", 40);
        Component component2("sugar", 70);
        Component component3("sugar", 70);
        CHECK(component2 > component1);
        CHECK(component1 < component2);
        CHECK(component1 != component2);
        CHECK(component2 == component3);
    }
}