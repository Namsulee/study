//
//  main.c
//  date
//
//  Created by Namsu Lee on 2018. 1. 22..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "date.h"
#define COMPARE(a, b) (a > b ? a : b)

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Date console!\n");
    
    Date date;
    Date today;
    Date yesterDay;
    Date tomorrow;
    Date prevDate;
    Date nextDate;
    
    Create(&date);
    Create(&today);
    Create(&yesterDay);
    Create(&tomorrow);
    Create(&prevDate);
    Create(&nextDate);
    
    // Today
    today = date.Today(&date);
    printf("%4d-%02d-%02d\n", today.year, today.month, today.day);
    
    // YesterDay
    yesterDay = today.YesterDay(&today);
    printf("%4d-%02d-%02d\n", yesterDay.year, yesterDay.month, yesterDay.day);
    
    // Tomorrow
    tomorrow = today.Tomorrow(&today);
    printf("%4d-%02d-%02d\n", tomorrow.year, tomorrow.month, tomorrow.day);
    
    // PrevDate
    prevDate = today.PrevDate(&today, 15);
    printf("%4d-%02d-%02d\n", prevDate.year, prevDate.month, prevDate.day);
    
    // NextDate
    nextDate = today.NextDate(&today, 4);
    printf("%4d-%02d-%02d\n", nextDate.year, nextDate.month, nextDate.day);
    
    // Compare - equal
    printf("Does it equal?(Today, Tommorrow)? ");
    if (today.IsEqual(&today, &tomorrow)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    // Compare - geater
    printf("which day is greater Today or Tommorrow? ");
    if (today.IsGreaterThan(&today, &tomorrow)) {
        printf("Today\n");
    } else {
        printf("Tomorrow\n");
    }
    // Compare - Lessor
    printf("which day is lesser Today or Tommorrow? ");
    if (today.IsLesserThan(&today, &tomorrow)) {
        printf("Today\n");
    } else {
        printf("Tomorrow\n");
    }
    Destroy(&date);
    Destroy(&today);
    Destroy(&yesterDay);
    Destroy(&tomorrow);
    Destroy(&prevDate);
    Destroy(&nextDate);
    
    return 0;
}
