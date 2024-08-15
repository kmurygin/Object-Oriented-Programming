//
// Created by Kacper Murygin on 01/04/2022.
//
#include <iostream>
#include "product.h"
#include "date.h"
#include "producer.h"
#include "component.h"
#include "file.h"
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Incorrect number of command line arguments"<<endl;
    }
    string fileName;
    stringstream stream;

    stream << argv[1];
    stream >> fileName;
    stream.clear();

    //Product(int Volume, int NumberLot, string Name, vector<Component> Components, Date ExpirationDate, Producer Producer);
    //Product(int Volume, int NumberLot, string Name, vector<Component> Components);
    File File1(fileName);
    vector <Product> products = File1.readFile();
    for (int i=0; i<products.size(); i++){
        cout << products.at(i);
        cout << "\n";
    }
//    Date date1(1,January,2022);
//    Producer producer1("Bakoma", "Warszawa", "Marszałkowska", "02-342", 12);
//    Component component1("milk", 30);
//    Component component2("sugar", 40);
//    Component component3("lactose", 50);
//    Component component4("gluten", 20);
//    vector<Component> components;
//    Product product1(20, 333, "Milk",components, date1, producer1);
//    product1.addComponent(component1);
//    product1.addComponent(component2);
//    product1.addComponent(component3);
//    product1.addComponent(component4);
//    cout << product1;
//    product1++;
//    product1.removeComponent("milk");
//    cout << product1;
//    product1--;
//    cout << product1;
    return 0;
}
