//
//  main.c
//  ArrayList_C
//
//  Created by Namsu Lee on 2018. 2. 19..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//
#include "ArrayList.h"
#include <stdio.h>

int CompareInteger(void *one, void* other)
{
    int ret;

    if (((Data*)one)->value > ((Data*)(other))->value) {
        ret = 1;
    } else if (((Data*)one)->value == ((Data*)(other))->value) {
        ret = 0;
    } else {
        ret = -1;
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
