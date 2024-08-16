//
// Created by Kacper Murygin on 13/04/2022.
//

#include "file.h"
#include <utility>

std::vector<Product> File::readFile() {
    std::ifstream file;
    file.open((std::string)filePath);
    std::vector<Product> Products;
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

File::File(const std::string& filePath) {
    if (checkIfExists(filePath)){
        this->filePath = filePath;
    }
}

bool File::checkIfExists(std::string filePath) {
    std::ifstream file;
    file.open((std::string)std::move(filePath));
    if(file) {
        file.close();
        return true;
    } else {
        std::cerr << "No such file in given path" << std::endl;
        file.close();
        return false;
    }
}

