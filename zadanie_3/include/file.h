//
// Created by Kacper Murygin on 13/04/2022.
//

#ifndef ZADANIE3_FILE_H
#define ZADANIE3_FILE_H

#include <string>
#include <fstream>
#include "product.h"

class File {
private:
    std::string filePath;
public:
    File(const std::string& filePath);
    std::vector<Product> readFile();
    static bool checkIfExists(std::string filePath);
};


#endif //ZADANIE3_FILE_H
