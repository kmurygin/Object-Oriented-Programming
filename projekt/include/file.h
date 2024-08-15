//
// Created by Kacper Murygin on 29/05/2022.
//

#ifndef ZADANIE3_FILE_H
#define ZADANIE3_FILE_H

#include <string>
#include <fstream>
#include <vector>
#include "payment.h"
#include "WrongNumberOfArgumentsException.h"
#include "FileDoNotExistException.h"
using namespace std;
class File {
private:
    string fileName;
public:
    File(string FileName);
    vector<int> readFile();
    void writeToFile(Service& service);
};


#endif //ZADANIE3_FILE_H
