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
    
    TDate_Handle *handle = NULL;
    Date date = {0,};
    
    CreateDate(handle);
    
    if (handle != NULL) {
        date = handle->getToday(handle);
        printf("Year[%d]\n", date.year);
        printf("Month[%d]\n", date.month);
        printf("Day[%d]\n", date.day);
    } else {
        printf("handle is null\n");
    }
    
    DestroyDate(handle);
    return 0;
}
