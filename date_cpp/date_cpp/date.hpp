//
//  date.hpp
//  date_cpp
//
//  Created by Namsu Lee on 2018. 1. 28..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#ifndef date_hpp
#define date_hpp

typedef unsigned int UShort;

typedef enum {
    FALSE = 0,
    TRUE = 1
} boolean;


class Date
{
public:
    int year, month, day, week;
    
    Date();
    ~Date();
    Date Today();
    Date YesterDay();
    Date Tomorrow();
    Date PrevDate(UShort day);
    Date NextDate(UShort day);
    
    boolean IsEqual(Date *date, Date *other);
    
};


#endif /* date_hpp */
