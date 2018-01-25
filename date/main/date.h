//
//  date.h
//  date
//
//  Created by Namsu Lee on 2018. 1. 22..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#ifndef date_h
#define date_h

#include <stdio.h>

typedef enum boolean {
    FALSE = 0,
    TRUE = 1
} boolean;

typedef struct _date Date;

typedef struct _date {
    int year;
    int month;
    int day;
    int weekday;
    
    int (*getYear)(Date*);
    int (*getMonth)(Date*);
    int (*getDay)(Date*);
    int (*getWeekday)(Date*);
    
    void (*setYear)(Date*, int year);
    void (*setMonth)(Date*, int month);
    void (*setDay)(Date*, int day);
    void (*setWeekday)(Date*, int weekday);
    
    Date (*Today)(Date*);
    Date (*YesterDay)(Date*);
    Date (*Tomorrow)(Date*);
    Date (*PrevDate)(Date*, Date*);
    Date (*NextDate)(Date*, Date*);
    boolean (*isEqual)(Date*, Date*);
    boolean (*isNotEqual)(Date*, Date*);
    boolean (*isGreaterThan)(Date*, Date*);
    boolean (*isLesserThan)(Date*, Date*);
} Date;

void CreateDate(Date *this);
void DestroyDate(Date *this);
int getYear(Date *this);
int getMonth(Date *this);
int getDay(Date *this);
int getWeekday(Date *this);

void setYear(Date *this, int year);
void setMonth(Date *this , int month);
void setDay(Date *this, int day);
void setWeekday(Date *this, int weekday);

Date Today(Date *this);
Date YesterDay(Date *this);
Date Tomorrow(Date *this);
Date PrevDate(Date *this, Date * date);
Date NextDate(Date *this, Date * date);
boolean isEqual(Date *this, Date * other);
boolean isNotEqual(Date *this, Date * other);
boolean isGreaterThan(Date *this, Date * other);
boolean isLesserThan(Date *this, Date * other);

#endif /* date_h */
