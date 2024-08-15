//
//  main.cpp
//  zadanie1
//
//  Created by Kacper Murygin on 08/03/2022.
//

#include <iostream>
#include "date.h"
using namespace std;

int main() {
    Date date1(10,December,2020);
    cout << date1.getDay() << "." << date1.getMonth() << "." << date1.getYear() << endl;

    date1.setMonth(January);
    date1.printDate();

    Date date2(10, November, 2021);
    date2.printDate();
    
    Date date3(34, September , 2023); //wrong date

    Date date4(24, December, 2022);
    date4.printDate();

    date2.setDay(34); //wrong day
    date2.setYear(-223); //wrong year

    Date date5(28, February, 2022);
    date5.printDate();

    Date date6(29, February, 2022); //not a leap year
    Date date7(29, February, 2024); //a leap year

    date7.printDate();

    date7.setDay(-10);
    date7.setMonth(March);

    date7.printDate();

    Date date8(23,(Months)4,2022);
    date8.printDate();
    return 0;
}
