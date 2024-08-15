//
// Created by Kacper Murygin on 18/03/2022.
//
#include <iostream>
#include "playlist.h"
using namespace std;

Playlist::Playlist(string Name, string Author, string DateCreated, string DateModified, vector<string> Songs, int TotalTime)
{
    name = Name;
    author = Author;
    dateCreated = DateCreated;
    dateModified = DateModified;
    if (checkTime(TotalTime))
        totalTime = TotalTime;
    else totalTime = 0;
    songs = Songs;
}

string Playlist::getAuthor() {
    return author;
}

string Playlist::getName() {
    return name;
}

int Playlist::getTotalTime() {
    return totalTime;
}

void Playlist::setName(string newName) {
    name = newName;
}

void Playlist::setAuthor(string newAuthor) {
    author = newAuthor;
}

bool Playlist::checkIfContains(string keySong) {
    if (find(songs.begin(), songs.end(), keySong) != songs.end()) {
        return true;
    }
    else
        return false;
}

void Playlist::addSong(string newSong) {
    if (not checkIfContains(newSong)) {
        songs.push_back(newSong);
    }
}

int Playlist::getIndexOfSong(string Song){
    for (int i = 0; i < songs.size(); i++)
    {
        if (songs[i] == Song)
            return i;
    }
}

void Playlist::modifySong(string oldSong, string newSong) {
    if (checkIfContains(oldSong)){
        int index = getIndexOfSong(oldSong);
        songs.at(index) = newSong;
    }
}

void Playlist::removeSong(string song) {
    if (checkIfContains(song)){
        songs.erase(std::remove(songs.begin(), songs.end(), song), songs.end());
    }
}

int Playlist::numberOfSongs() {
    return songs.size();
}

string Playlist::getDateCreated() {
    return dateCreated;
}

string Playlist::getDateModified() {
    return dateModified;
}

void Playlist::setTotalTime(int newTime) {
    if (checkTime(newTime))
        totalTime = newTime;
}

void Playlist::setDateCreated(string newDate) {
    dateCreated = newDate;
}

void Playlist::setDateModified(string newDate) {
    dateModified = newDate;
}

bool Playlist::checkTime(int checkedTime) {
    if (checkedTime > 0)
        return true;
    else
        return false;
}

vector<string> Playlist::getSongs() {
    return songs;
}

void Playlist::printSongs() {
    for (int i=0; i< songs.size(); i++){
        cout << songs[i] << " ";
    }
    cout << endl;
}
