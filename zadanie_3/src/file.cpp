//
// Created by Kacper Murygin on 13/04/2022.
//

#include "file.h"

vector<Product> File::readFile() {
    ifstream file;
    file.open("/Users/kacper/CLionProjects/zadanie3/"+(string)fileName);
    vector<Product> Products;
    if (file){
        Product temp;
        while (file >> temp) {
            Products.push_back(temp);
        }
    }
//    else{
//        cerr << "Error while opening the file";
//    }
    file.close();
    return Products;
}

File::File(string FileName) {
    if (checkIfExists(FileName)){
        fileName = FileName;
    }
}

bool File::checkIfExists(string FileName) {
    ifstream file;
    file.open("/Users/kacper/CLionProjects/zadanie3/"+(string)FileName);
    if(file) {
        file.close();
        return true;
    } else {
        file.close();
        return false;
    }
}

