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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string str;
    
    // creation
    Date _date1("20180201");
    cout << static_cast<char *>(_date1) << endl;
    
    Date _date2(2018, 2, 2);
    cout << static_cast<char *>(_date2) << endl;
    
    // today
    Date today;
    today = Date::Today();
    cout << "today is " << today.GetYear();
    cout.width(2);
    cout << setfill('0') << today.GetMonth();
    cout.width(2);
    cout << setfill('0') << today.GetDay() << endl;
    cout << "today is " << static_cast<char *>(today) << endl;
    
    // yesterday
    Date yesterday = today.YesterDay();
    cout << "yesterday is " << yesterday.GetYear();
    cout.width(2);
    cout << setfill('0') << yesterday.GetMonth();
    cout.width(2);
    cout << setfill('0') << yesterday.GetDay() << endl;
    cout << "yesterday is " << static_cast<char *>(yesterday) << endl;
    
    // yesterday's yesterday
    Date date = --yesterday;
    cout << static_cast<char *>(date) << endl;
    
    
    return 0;
}
