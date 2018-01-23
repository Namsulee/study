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

typedef struct Date {
    int year;
    int month;
    int day;
    int weekday;
} Date;

typedef struct TDate_Handle {
    unsigned int ulSecureToken;
    Date (*getToday)(struct TDate_Handle * this);
    Date (*getYesterDay)(struct TDate_Handle * this);
    Date (*getTomorrow)(struct TDate_Handle * this);
    Date (*getPrevDate)(struct TDate_Handle * this, Date * date);
    Date (*getNextDate)(struct TDate_Handle * this, Date * date);
    boolean (*isEqual)(struct TDate_Handle * this, Date * srcDate, Date * dstDate);
    boolean (*isNotEqual)(struct TDate_Handle * this, Date * srcDate, Date * dstDate);
    boolean (*isGreaterThan)(struct TDate_Handle * this, Date * srcDate, Date * dstDate);
    boolean (*isLesserThan)(struct TDate_Handle * this, Date * srcDate, Date * dstDate);
} TDate_Handle;

void CreateDate(TDate_Handle * this);
void DestroyDate(TDate_Handle * this);
Date getToday(TDate_Handle * this);
Date getYesterDay(TDate_Handle * this);
Date getTomorrow(TDate_Handle * this);
Date getPrevDate(TDate_Handle * this, Date * date);
Date getNextDate(TDate_Handle * this, Date * date);
boolean isEqual(TDate_Handle * this, Date * srcDate, Date * dstDate);
boolean isNotEqual(TDate_Handle * this, Date * srcDate, Date * dstDate);
boolean isGreaterThan(TDate_Handle * this, Date * srcDate, Date * dstDate);
boolean isLesserThan(TDate_Handle * this, Date * srcDate, Date * dstDate);

#endif /* date_h */
