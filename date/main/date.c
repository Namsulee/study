//
//  date.c
//  date
//
//  Created by Namsu Lee on 2018. 1. 22..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//
#include <stdlib.h>
#include <time.h>
#include "date.h"

Date Today(Date *this)
{
    Date date = {0,};
    
    if (this != NULL) {
        date.year = this->year + 1900;
        date.day = this->day;
        date.month = this->month+1;
        date.weekday = this->weekday;
    }
    
    return date;
}

Date YesterDay(Date *this)
{
    Date date = {0,};
    
    if (this != NULL) {
        date.year = this->year + 1900;
        date.day = this->day-1;
        date.month = this->month+1;
        date.weekday = this->weekday;
    }
    
    return date;
}

Date Tomorrow(Date *this)
{
    Date date = {0,};
    
    if (this != NULL) {
        date.year = this->year + 1900;
        date.day = this->day+1;
        date.month = this->month+1;
        date.weekday = this->weekday;
    }
    
    return date;
}

Date PrevDate(Date *this, Date *other)
{
    Date date = {0,};
    
    if (this != NULL) {
        date.year = this->year + 1900;
        date.day = this->day+1;
        date.month = this->month+1;
        date.weekday = this->weekday;
    }
    return date;
}

Date NextDate(Date *this, Date *other)
{
    Date date = {0,};
    
    if (this != NULL) {
        date.year = this->year + 1900;
        date.day = this->day+1;
        date.month = this->month+1;
        date.weekday = this->weekday;
    }
    
    return date;
}

boolean isEqual(Date *this, Date * other)
{
    return FALSE;
}
boolean isNotEqual(Date *this, Date * other)
{
     return FALSE;
}
boolean isGreaterThan(Date *this, Date * other)
{
     return FALSE;
}
boolean isLesserThan(Date *this, Date * other)
{
     return FALSE;
}

int getYear(Date *this)
{
    return this->year;
}
int getMonth(Date *this)
{
    return this->month;
}
int getDay(Date *this)
{
    return this->day;
}
int getWeekday(Date *this)
{
    return this->weekday;
}
void setYear(Date *this, int year)
{
    this->year = year;
}
void setMonth(Date *this , int month)
{
    this->month = month;
}
void setDay(Date *this, int day)
{
    this->day = day;
}
void setWeekday(Date *this, int weekday)
{
    this->weekday = weekday;
}
void CreateDate(Date *this)
{
    struct tm *t = NULL;
    time_t timer;
    timer = time(NULL);
    t = localtime(&timer);
    
    this->year = t->tm_year;
    this->month = t->tm_mon;
    this->day = t->tm_mday;
    this->weekday = t->tm_wday;
    
    this->Today = Today;
    this->Tomorrow = Tomorrow;
    this->YesterDay = YesterDay;
    this->PrevDate = PrevDate;
    this->NextDate = NextDate;
    this->isEqual = isEqual;
    this->isNotEqual = isNotEqual;
    this->isGreaterThan = isGreaterThan;
    this->isLesserThan = isLesserThan;
    
    this->setYear = setYear;
    this->setMonth = setMonth;
    this->setDay = setDay;
    this->setWeekday = setWeekday;
    this->getYear = getYear;
    this->getMonth = getMonth;
    this->getDay = getDay;
    this->getWeekday = getWeekday;
}

void DestroyDate(Date *this)
{
    return;
}
