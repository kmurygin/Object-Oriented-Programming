//
// Created by Kacper Murygin on 13/04/2022.
//

#ifndef ZADANIE3_FILE_H
#define ZADANIE3_FILE_H

#include <string>
#include <fstream>
#include "product.h"
using namespace std;
class File {
private:
    string fileName;
public:
    File(string FileName);
    vector<Product> readFile();
    bool checkIfExists(string FileName);
};


#endif //ZADANIE3_FILE_H
