//
//  date.h
//  date
//
//  Created by Namsu Lee on 2018. 1. 22..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#ifndef date_h
#define date_h

typedef unsigned int UShort;

typedef enum {
    FALSE = 0,
    TRUE = 1
} boolean;

typedef struct _date Date;

typedef struct _date {
    int year;
    int month;
    int day;
    int weekday;
    
    int (*GetYear)(Date*);
    int (*GetMonth)(Date*);
    int (*GetDay)(Date*);
    int (*GetWeekday)(Date*);
    
    void (*SetYear)(Date*, int year);
    void (*SetMonth)(Date*, int month);
    void (*SetDay)(Date*, int day);
    void (*SetWeekday)(Date*, int weekday);
    
    Date (*Today)(Date*);
    Date (*YesterDay)(Date*);
    Date (*Tomorrow)(Date*);
    Date (*PrevDate)(Date*, UShort);
    Date (*NextDate)(Date*, UShort);
    boolean (*IsEqual)(Date*, Date*);
    boolean (*IsNotEqual)(Date*, Date*);
    boolean (*IsGreaterThan)(Date*, Date*);
    boolean (*IsLesserThan)(Date*, Date*);
} Date;

void Create(Date *this);
void Destroy(Date *this);
int GetYear(Date *this);
int GetMonth(Date *this);
int GetDay(Date *this);
int GetWeekday(Date *this);

void SetYear(Date *this, int year);
void SetMonth(Date *this , int month);
void SetDay(Date *this, int day);
void SetWeekday(Date *this, int weekday);

Date Today(Date *this);
Date YesterDay(Date *this);
Date Tomorrow(Date *this);
Date PrevDate(Date *this, UShort day);
Date NextDate(Date *this, UShort day);
boolean IsEqual(Date *this, Date *other);
boolean IsNotEqual(Date *this, Date *other);
boolean IsGreaterThan(Date *this, Date *other);
boolean IsLesserThan(Date *this, Date *other);

#endif /* date_h */
