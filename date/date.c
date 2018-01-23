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


Date getToday(TDate_Handle * this)
{
    struct tm *t;
    time_t timer;
    Date date = {0,};
    
    if (this != NULL) {
        timer = time(NULL);
        t = localtime(&timer);
        date.year = t->tm_year + 1900;
        date.day = t->tm_mday;
        date.month = t->tm_mon+1;
    }
    
    return date;
}

Date getYesterDay(TDate_Handle * this)
{
    struct tm *t;
    time_t timer;
    Date date = {0,};
    
    if (this != NULL) {
        timer = time(NULL);
        t = localtime(&timer);
        date.year = t->tm_year + 1900;
        date.day = t->tm_mday-1;
        date.month = t->tm_mon+1;
    }
    
    return date;
}

Date getTomorrow(TDate_Handle * this)
{
    struct tm *t;
    time_t timer;
    Date date = {0,};
    
    if (this != NULL) {
        timer = time(NULL);
        t = localtime(&timer);
        date.year = t->tm_year + 1900;
        date.day = t->tm_mday+1;
        date.month = t->tm_mon+1;
    }
    
    return date;
}

Date getPrevDate(TDate_Handle * this, Date * date)
{
    struct tm *t;
    time_t timer;
    Date retDate = {0,};
    
    if (this != NULL) {
        timer = time(NULL);
        t = localtime(&timer);
        t->tm_year = date->year - 1900;
        t->tm_mon = date->month;
        t->tm_mday = date->day - 1;
        mktime(t);
        
        retDate.year = t->tm_year;
        retDate.month = t->tm_mon;
        retDate.day = t->tm_mday;
    }
    
    return retDate;
}

Date getNextDate(TDate_Handle * this, Date * date)
{
    struct tm *t;
    time_t timer;
    Date retDate = {0,};
    
    if (this != NULL) {
        timer = time(NULL);
        t = localtime(&timer);
        t->tm_year = date->year - 1900;
        t->tm_mon = date->month;
        t->tm_mday = date->day - 1;
        mktime(t);
        
        retDate.year = t->tm_year;
        retDate.month = t->tm_mon;
        retDate.day = t->tm_mday;
    }
    
    return retDate;
}

boolean isEqual(TDate_Handle * this, Date * srcDate, Date * dstDate)
{
    return TRUE;
}
boolean isNotEqual(TDate_Handle * this, Date * srcDate, Date * dstDate)
{
    return TRUE;
}
boolean isGreaterThan(TDate_Handle * this, Date * srcDate, Date * dstDate)
{
    return TRUE;
}

boolean isLesserThan(TDate_Handle * this, Date * srcDate, Date * dstDate)
{
    return TRUE;
}

void CreateDate(TDate_Handle * this)
{
    if (this == NULL) {
        this = (TDate_Handle *) malloc(sizeof(TDate_Handle));
        if (this != NULL) {
            this->getToday = getToday;
            this->getTomorrow = getTomorrow;
            this->getYesterDay = getYesterDay;
            this->getPrevDate = getPrevDate;
            this->getNextDate = getNextDate;
            this->isEqual = isEqual;
            this->isNotEqual = isNotEqual;
            this->isGreaterThan = isGreaterThan;
            this->isLesserThan = isLesserThan;
        }
    } else {
        printf("error to crate Handle\n");
    }
}

void DestroyDate(TDate_Handle * this)
{
    if (this != NULL) {
        free(this);
    }
}
