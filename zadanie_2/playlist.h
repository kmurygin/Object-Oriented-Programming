//
// Created by Kacper Murygin on 18/03/2022.
//
#include<string>
#include<vector>

using namespace std;

#ifndef PLAYLIST_H
#define PLAYLIST_H

//Lista ma nazwę, autora, datę utworzenia i modyfikacji, łączny czas trwania i składa się z piosenek.
//Na potrzeby tego zadania piosenki mogą być reprezentowane za pomocą tytułów.
class Playlist {
private:
    string name;
    string author;
    vector<string> songs;
    int totalTime;
    string dateCreated;
    string dateModified;
public:
    Playlist(string Name, string Author, string DateCreated, string DateModified, vector<string> Songs, int TotalTime);
    string getName();
    string getAuthor();
    int getTotalTime();
    string getDateCreated();
    string getDateModified();

    void setName(string newName);
    void setAuthor(string newAuthor);
    void setTotalTime(int newTime);
    void setDateCreated(string newDate);
    void setDateModified(string newDate);

    bool checkTime(int checkedTime);
    //vector songs- methods
    vector<string> getSongs();
    bool checkIfContains(string song);
    int getIndexOfSong(string Song);
    void addSong(string newSong);
    void modifySong(string oldSong, string newSong);
    void removeSong(string Song);
    int numberOfSongs();
    void printSongs();
};

#endif //PLAYLIST_H