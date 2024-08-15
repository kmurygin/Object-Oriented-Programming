//
// Created by Kacper Murygin on 18/03/2022.
//

#include <iostream>
#include <vector>
#include "playlist.h"
#include <sstream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 7) {
        cerr << "Incorrect number of command line arguments- expected 7, got" << argc << endl;
        return 1;
    }
    string Name;
    string Author;
    int TotalTime;
    string DateCreated;
    string DateModified;

    stringstream stream;

    stream << argv[1];
    stream >> Name;
    stream.clear();

    stream << argv[2];
    stream >> Author;
    stream.clear();

    stream << argv[3];
    stream >> DateCreated;
    stream.clear();

    stream << argv[4];
    stream >> DateModified;
    stream.clear();

    stream << argv[5];
    stream >> TotalTime;
    stream.clear();

    vector<string> Songs;
    for(int i=6; i<argc; i++){
        Songs.push_back((string)argv[i]);
    }
    Playlist playlist1(Name, Author, DateCreated, DateModified, Songs, TotalTime);
    cout << playlist1.getName()<< endl;
    cout << playlist1.getAuthor()<< endl;
    cout << playlist1.getDateCreated()<< endl;
    cout << playlist1.getDateModified()<< endl;
    cout << playlist1.getTotalTime()<< endl;
    cout << "The playlist consists of " << argc - 6 << " songs:" << endl;
    playlist1.printSongs();
    playlist1.addSong("Innuendo");
    playlist1.printSongs();
}