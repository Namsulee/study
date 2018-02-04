//
//  main.cpp
//  date_cpp
//
//  Created by Namsu Lee on 2018. 1. 28..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "date.hpp"
using namespace std;

char *covertWeekDay(WeekDay day)
{
    char *buffer;
    switch(day) {
    case MON:
        buffer = "Monday";
    break;
    case TUE:
        buffer = "Tuesday";
    break;
    case WED:
        buffer = "Wednesday";
    break;
    case THU:
        buffer = "Thursday";
    break;
    case FRI:
        buffer = "Friday";
    break;
    case SAT:
        buffer = "Saturday";
    break;
    case SUN:
        buffer = "Sunday";
    break;
    default:
        buffer = "Monday";
    break;
    }
    
    return buffer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string str;
    
    // creation 1
    Date *date = new Date();
    if (date != NULL)
        delete date;
    
    // creation 2
    Date date1("20180201");
    cout << static_cast<char *>(date1) << endl;
    // creation 3
    Date date2(2018, 2, 2);
    cout << static_cast<char *>(date2) << endl;
    
    // today
    Date today;
    today = Date::Today();
    cout << "today is " << today.GetYear();
    cout.width(2);
    cout << setfill('0') << today.GetMonth();
    cout.width(2);
    cout << setfill('0') << today.GetDay() << endl;
    cout << "today is " << static_cast<char *>(today);
    cout << " " << covertWeekDay(today.GetWeekDay()) << endl;
    
    Date yesterday = today.YesterDay();
    
    // yesterday
    cout << "yesterday is " << static_cast<char *>(yesterday);
    cout << " " << covertWeekDay(yesterday.GetWeekDay()) << endl;
    Date _date1 = today;
    cout << "yesterday is " << static_cast<char *>(_date1--) << endl;
    Date _date2 = today;
    cout << "yesterday is " << static_cast<char *>(_date2-(1)) << endl;
    
    // tomorrow
    Date tomorrow = today.Tomorrow();
    cout << "tomorrow is " << static_cast<char *>(tomorrow);
    cout << " " << covertWeekDay(tomorrow.GetWeekDay()) << endl;
    Date _date3 = today;
    cout << "tomorrow is " << static_cast<char *>(_date3++) << endl;
    Date _date4 = today;
    cout << "tomorrow is " << static_cast<char *>(_date4+(1)) << endl;
    
    // previous date
    Date prevDate = tomorrow.PreviousDate(2);
    cout << "tomorrow's 2 previous date is " << static_cast<char *>(prevDate) << endl;
    Date _prevDate = tomorrow;
    cout << "tomorrow's 2 previous date is " << static_cast<char *>(_prevDate-(2)) << endl;
    
    // next date
    Date nextDate = tomorrow.NextDate(3);
    cout << "tomorrow's 3 next date is " << static_cast<char *>(nextDate) << endl;
    Date _nextDate = tomorrow;
    cout << "tomorrow's 3 next date is " << static_cast<char *>(_nextDate+(3)) << endl;
    
    // check equal
    cout << static_cast<char *>(today) << " is equal to" << static_cast<char *>(yesterday) << " ? ";
    if (today.IsEquals(yesterday))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
        
    // check not equal
    cout << static_cast<char *>(today) << " is not equal to " << static_cast<char *>(yesterday) << " ? ";
    if (today.IsNotEquals(yesterday))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
    // check greater
    cout << static_cast<char *>(tomorrow) << " is geater than " << static_cast<char *>(yesterday) << " ? ";
    if (tomorrow.IsGreaterThan(yesterday))
        cout << " yes" << endl;
    else
        cout << " no" << endl;
    
    // check lesser
    cout << static_cast<char *>(tomorrow) << " is lesser than " << static_cast<char *>(yesterday) << " ?";
    if (tomorrow.IsLesserThan(yesterday))
        cout << " yes" << endl;
    else
        cout << " no" << endl;
    
    return 0;
}
