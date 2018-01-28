//
//  date.cpp
//  date_cpp
//
//  Created by Namsu Lee on 2018. 1. 28..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#include "date.hpp"

Date::Date()
{
    year = 1900;
    month = 1;
    day = 1;
    week = 1;
}

Date::~Date()
{
    
}

Date::Today()
{
    date = new Date();
    
    date.year = 1900;
    date.month = 1;
    date.day = 1;
    date.week = 1;
    
    return date;
}


