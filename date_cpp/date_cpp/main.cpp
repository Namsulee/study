//
//  main.cpp
//  date_cpp
//
//  Created by Namsu Lee on 2018. 1. 28..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#include <iostream>
#include "date.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string str;
    
    Date today;
    today = Date::Today();
    cout << "date is " << static_cast<char *>(today) << endl;
    return 0;
}
