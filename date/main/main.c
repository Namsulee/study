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
    
    Date date = {0,};
    
    CreateDate(&date);
    printf("Year[%d]\nMonth[%d]\nDay[%d]\nWeek[%d]\n", date.year, date.month, date.day, date.weekday);
    Date today = date.Today(&date);
    printf("Today : Year[%d]\nMonth[%d]\nDay[%d]\nWeek[%d]\n", today.year, today.month, today.day, today.weekday);
    Date tomorrow = date.Tomorrow(&date);
    printf("tomorrow : Year[%d]\nMonth[%d]\nDay[%d]\nWeek[%d]\n", tomorrow.year, tomorrow.month, tomorrow.day, tomorrow.weekday);
    Date yesterday = date.YesterDay(&date);
    printf("yesterday : Year[%d]\nMonth[%d]\nDay[%d]\nWeek[%d]\n", yesterday.year, yesterday.month, yesterday.day, yesterday.weekday);
    //Date prev = date.PrevDate(&date, &tomorrow);
    //Date next = date.NextDate(&date, &tomorrow);
    
    DestroyDate(&date);
    return 0;
}
