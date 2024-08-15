//
// Created by Kacper Murygin on 24/03/2022.
//
#include <string>
#include "catch.hh"
#include "../playlist.h"
//Playlist(string Name, string Author, string DateCreated, string DateModified, vector<string> Songs, double TotalTime)
TEST_CASE("playlist simple tests", "[playlist]")
{
    Playlist playlist1("playlista1", "Kacper Murygin", "10.02.2020", "20.02.2021", {"Innuendo", "Born this way"}, 14);
    CHECK(playlist1.getAuthor() == "Kacper Murygin");
    CHECK(playlist1.getName() == "playlista1");
    CHECK(playlist1.getDateCreated() == "10.02.2020");
    CHECK(playlist1.getDateModified() == "20.02.2021");
    vector<string> songss = {"Innuendo", "Born this way"};
    CHECK(playlist1.getSongs() == songss);
    CHECK(playlist1.getTotalTime() == 14);

    SECTION("checking if time is greater than 0"){
        CHECK(playlist1.checkTime(-14) == 0);
        CHECK(playlist1.checkTime(45) == 1);
    }

    SECTION("Constructor with negative time") {
        Playlist playlist2("playlista1", "Kacper Murygin", "10.02.2020", "20.02.2021", {"Innuendo", "Born this way"}, -17);
        CHECK(playlist2.getTotalTime() == 0);
    }

    SECTION("modification of name") {
        playlist1.setName("playlista super");
        CHECK(playlist1.getName() == "playlista super");
    }

    SECTION("modification of author") {
        playlist1.setAuthor("Freddie Mercury");
        CHECK(playlist1.getAuthor() == "Freddie Mercury");
    }

    SECTION("modification of dateCreated") {
        playlist1.setDateCreated("02.03.2022");
        CHECK(playlist1.getDateCreated() == "02.03.2022");
    }

    SECTION("modification of dateModified") {
        playlist1.setDateModified("20.04.2022");
        CHECK(playlist1.getDateModified() == "20.04.2022");
    }

    SECTION("modification of totalTime") {
        playlist1.setTotalTime(15);
        CHECK(playlist1.getTotalTime() == 15);
    }

    SECTION("modification of totalTime- negative time") {
        playlist1.setTotalTime(-14);
        CHECK(playlist1.getTotalTime() == 14);
    }

    SECTION("modification of every element but songs") {
        playlist1.setName("playlista the best");
        playlist1.setAuthor("Lady Gaga");
        playlist1.setTotalTime(200);
        playlist1.setDateCreated("31.03.2022");
        playlist1.setDateModified("01.04.2022");

        CHECK(playlist1.getName() == "playlista the best");
        CHECK(playlist1.getAuthor() == "Lady Gaga");
        CHECK(playlist1.getTotalTime() == 200);
        CHECK(playlist1.getDateCreated() == "31.03.2022");
        CHECK(playlist1.getDateModified() == "01.04.2022");
    }

    SECTION("adding new song to playlist- song does NOT exist") {
        playlist1.addSong("Diamonds");
        vector<string> songss = {"Innuendo", "Born this way", "Diamonds"};
        CHECK(playlist1.getSongs() == songss);
    }

    SECTION("adding new song to playlist- song exists") {
        playlist1.addSong("Innuendo");
        vector<string> songss = {"Innuendo", "Born this way"};
        CHECK(playlist1.getSongs() == songss);
    }

    SECTION("adding songs in playlist- more at once") {
        playlist1.addSong("Diamonds");
        playlist1.addSong("I'm still standing");
        playlist1.addSong("Vogue");

        vector<string> songss = {"Innuendo", "Born this way", "Diamonds", "I'm still standing", "Vogue"};
        CHECK(playlist1.getSongs() == songss);
    }

    SECTION("removing song from playlist- song exists") {
        playlist1.removeSong("Born this way");
        vector<string> songss = {"Innuendo"};
        CHECK(playlist1.getSongs() == songss);
    }

    SECTION("removing song from playlist- song does NOT exist") {
        playlist1.removeSong("Vogue");
        vector<string> songss = {"Innuendo", "Born this way"};
        CHECK(playlist1.getSongs() == songss);
    }

    SECTION("modifying playlist- song exists"){
        playlist1.modifySong("Born this way", "Radio Gaga");
        vector<string> songs1 = {"Innuendo", "Radio Gaga"};
        CHECK(playlist1.getSongs() == songs1);
    }

    SECTION("modifying playlist- song does NOT exist"){
        playlist1.modifySong("Vogue", "Radio Gaga");
        vector<string> songs1 = {"Innuendo", "Born this way"};
        CHECK(playlist1.getSongs() == songs1);
    }

    SECTION("getting number of songs in a playlist"){
        playlist1.addSong("Diamonds");
        playlist1.addSong("I'm still standing");
        playlist1.addSong("Vogue");

        CHECK(playlist1.numberOfSongs() == 5);
    }
}