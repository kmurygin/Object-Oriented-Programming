//
// Created by Kacper Murygin on 29/05/2022.
//

#include <iostream>
#include "file.h"

vector<int> File::readFile() {
    ifstream file;
    file.open(fileName);
    vector<int> arguments;
    int temp;
    while (file >> temp) {
        arguments.push_back(temp);
    }

    file.close();

    if (arguments.size() != 4){
        throw(WrongNumberOfArgumentsException(arguments.size()));
    }
    return arguments;
    }


File::File(string FileName) {
    ifstream fileHandle;
    fileHandle.open(FileName);
    if (fileHandle){
        fileName = FileName;
    }
    else
        throw(FileDoNotExistException(fileName));
}

void File::writeToFile(Service& service) {
    ofstream fileHandle;
    fileHandle.open(fileName, std::ios_base::app);
    fileHandle << service << endl;
    fileHandle.close();
}
