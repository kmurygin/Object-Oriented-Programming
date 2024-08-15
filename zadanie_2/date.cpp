//
//  date.cpp
//  zadanie1
//
//  Created by Kacper Murygin on 08/03/2022.
//

#include <iostream>
#include "date.h"
using namespace std;

Date::Date(int d,Months m, int y) {
    if (checkDate(d, m, y)) {
        day = d;
        month = m;
        year = y;
    }
    else printWrongDate(d, m, y);
};

bool Date::checkIfLeap(int year) {
    return ( ((year % 4 == 0) & (year % 100 != 0)) || (year % 400 == 0));
}

bool Date::checkDate(int day, Months month, int year) {
    if(year < 1)
        return false;
    if(day < 1 || day > 31)
        return false;
    if(month < January || month > December)
        return false;
    if(month == February) {
        if (checkIfLeap(year)) {
            if (day > 29)
                return false;
        }
        else if (day > 28)
            return false;
    }
    if (month == April || month == June || month == September || month == November){
        if(day > 30)
            return false;
    }
    return true;
};

void Date::setDay(int newDay) {
    if (checkDate(newDay, month, year)) day = newDay;
    else printWrongDate(newDay, month, year);
}

void Date::setMonth(Months newMonth) {
    if (checkDate(day, newMonth, year)) month = newMonth;
    else printWrongDate(day, newMonth, year);
}

void Date::setYear(int newYear) {
    if (checkDate(day, month, newYear)) year =  newYear;
    else printWrongDate(day, month, newYear);
}

int Date::getDay() {
    return day;
}

Months Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

void Date::printDate() {
    cout << day << "." << month << "." << year << endl;
}

void Date::printWrongDate(int day, Months month, int year){
    cout << "Wrong date- " << day << "." << month << "." << year<< endl;
}