//
// Created by Kacper Murygin on 01/04/2022.
//
#include <iostream>
#ifndef DATE_H
#define DATE_H
using namespace std;
enum Months {
    January=1, February, March, April, May, June,
    July, August, September, October, November, December
};

class Date {
private:
    int day;
    Months month;
    int year;
    bool checkIfLeap(int year);
    bool checkDate(int day, Months month, int year);

public:
    Date();
    Date(int day, Months month, int year);

    void setDay(int newDay);
    void setMonth(Months newMonth);
    void setYear(int newYear);

    void setDate(int newDay, Months newMonth, int newYear);

    int getDay();
    Months getMonth();
    int getYear();

    void printDate();
    void printWrongDate(int day, Months month, int year);

    bool operator==(const Date& second_argument) const;
    bool operator!=(const Date& second_argument) const;

    friend ostream& operator<<(ostream& os, const Date& component);
};
ostream& operator<<(ostream& os, const Date& component);
#endif //DATE_H