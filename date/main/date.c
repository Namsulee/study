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
    time_t timer;
    struct tm *today;
    
    Date _today = {0,};
    Create(&_today);
    time(&timer);
    
    today = localtime(&timer);
    
    _today.year = today->tm_year + 1900;
    _today.day = today->tm_mday;
    _today.month = today->tm_mon + 1;
    _today.weekday = today->tm_wday;
    
    Destroy(&_today);
    return _today;
}

Date YesterDay(Date *this)
{
    struct tm time = {0,};
    Date _yesterday = {0,};
    
    Create(&_yesterday);
    time.tm_year = this->year - 1900;
    time.tm_mon = this->month - 1;
    time.tm_mday = this->day - 1;
    
    mktime(&time);
    
    _yesterday.year = time.tm_year + 1900;
    _yesterday.day = time.tm_mday;
    _yesterday.month = time.tm_mon + 1;
    _yesterday.weekday = time.tm_wday;
    
    Destroy(&_yesterday);
    return _yesterday;
}

Date Tomorrow(Date *this)
{
    struct tm time = {0,};
    Date _tomorrow = {0,};
    
    Create(&_tomorrow);
    time.tm_year = this->year - 1900;
    time.tm_mon = this->month - 1;
    time.tm_mday = this->day + 1;
    
    mktime(&time);
    
    _tomorrow.year = time.tm_year + 1900;
    _tomorrow.day = time.tm_mday;
    _tomorrow.month = time.tm_mon + 1;
    _tomorrow.weekday = time.tm_wday;
    
    Destroy(&_tomorrow);
    return _tomorrow;
}

Date PrevDate(Date *this, UShort day)
{
    struct tm time = {0,};
    Date _prevDate = {0,};
    
    Create(&_prevDate);
    time.tm_year = this->year - 1900;
    time.tm_mon = this->month - 1;
    time.tm_mday = this->day - day;
    
    mktime(&time);
    
    _prevDate.year = time.tm_year + 1900;
    _prevDate.day = time.tm_mday;
    _prevDate.month = time.tm_mon + 1;
    _prevDate.weekday = time.tm_wday;
    
    Destroy(&_prevDate);
    return _prevDate;
}

Date NextDate(Date *this, UShort day)
{
    struct tm time = {0,};
    Date _nextDate = {0,};
    
    Create(&_nextDate);
    time.tm_year = this->year - 1900;
    time.tm_mon = this->month - 1;
    time.tm_mday = this->day + day;
    
    mktime(&time);
    
    _nextDate.year = time.tm_year + 1900;
    _nextDate.day = time.tm_mday;
    _nextDate.month = time.tm_mon  + 1;
    _nextDate.weekday = time.tm_wday;
    
    Destroy(&_nextDate);
    return _nextDate;
}

boolean IsEqual(Date *this, Date *other)
{
    if (this->year == other->year && (this->month == other->month && this->day == other->day)) {
        return TRUE;
    }
    return FALSE;
}
boolean IsNotEqual(Date *this, Date *other)
{
    if (this->year != other->year || (this->month != other->month || this->day != other->day)) {
        return TRUE;
    }
    return FALSE;
}
boolean IsGreaterThan(Date *this, Date *other)
{
    if (this->year > other->year) {
        return TRUE;
    }
    
    if (this->month > other->month) {
        return TRUE;
    } else if (this->day > other->day) {
        return TRUE;
    }

    return FALSE;
}
boolean IsLesserThan(Date *this, Date *other)
{
    if (this->year < other->year) {
        return TRUE;
    }
    if (this->month < other->month) {
        return TRUE;
    } else if (this->day < other->day) {
        return TRUE;
    }
    
    return FALSE;
}

int GetYear(Date *this)
{
    return this->year;
}
int GetMonth(Date *this)
{
    return this->month;
}
int GetDay(Date *this)
{
    return this->day;
}
int GetWeekday(Date *this)
{
    return this->weekday;
}
void SetYear(Date *this, int year)
{
    this->year = year;
}
void SetMonth(Date *this , int month)
{
    this->month = month;
}
void SetDay(Date *this, int day)
{
    this->day = day;
}
void SetWeekday(Date *this, int weekday)
{
    this->weekday = weekday;
}
void Create(Date *this)
{
    this->year = 1900;
    this->month = 1;
    this->day = 1;
    this->weekday = 1;
    
    this->Today = Today;
    this->Tomorrow = Tomorrow;
    this->YesterDay = YesterDay;
    this->PrevDate = PrevDate;
    this->NextDate = NextDate;
    this->IsEqual = IsEqual;
    this->IsNotEqual = IsNotEqual;
    this->IsGreaterThan = IsGreaterThan;
    this->IsLesserThan = IsLesserThan;
    
    this->SetYear = SetYear;
    this->SetMonth = SetMonth;
    this->SetDay = SetDay;
    this->SetWeekday = SetWeekday;
    this->GetYear = GetYear;
    this->GetMonth = GetMonth;
    this->GetDay = GetDay;
    this->GetWeekday = GetWeekday;
}

void Destroy(Date *this)
{
    ;
}
