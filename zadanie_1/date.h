//
//  date.h
//  zadanie1
//
//  Created by Kacper Murygin on 08/03/2022.
//

#ifndef DATE.H
#define DATE.H

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
    Date(int day, Months month, int year);

    void setDay(int newDay);

    void setMonth(Months newMonth);

    void setYear(int newYear);

    int getDay();

    Months getMonth();

    int getYear();

    void printDate();

    void printWrongDate(int day, Months month, int year);
};


#endif //DATE_H