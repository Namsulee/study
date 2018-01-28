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
    
    Destroy(&date);
    Destroy(&today);
    Destroy(&yesterDay);
    Destroy(&tomorrow);
    Destroy(&prevDate);
    Destroy(&nextDate);
    
    return 0;
}
