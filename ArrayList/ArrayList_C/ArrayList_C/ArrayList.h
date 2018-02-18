//
//  ArrayList.h
//  ArrayList_C
//
//  Created by Namsu Lee on 2018. 2. 19..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#ifndef ArrayList_h
#define ArrayList_h

#include <stdio.h>

typedef struct _arrayList ArrayList;

typedef struct {
    int value;
} Data;

typedef struct _arrayList {
    int capacity;
    int length;
    void (*front);
    
    int (*GetCapacity)(ArrayList*);
    int (*GetLength)(ArrayList*);
    
    int (*Store)(ArrayList *this, int index, void *object, size_t size);
    int (*Insert)(ArrayList *this, int index, void *object, size_t size);
    int (*AppendFromFront)(ArrayList *this, void *object, size_t size);
    int (*AppendFromRear)(ArrayList *this, void *object, size_t size);
    int (*Delete)(ArrayList *this, int index, size_t size);
    int (*DeleteFromFront)(ArrayList *this, size_t size);
    int (*DeleteFromRear)(ArrayList *this, size_t size);
    void (*Clear)(ArrayList *this);
    int (*Modify)(ArrayList *this, int index, void *object, size_t size);
    int (*LinearSearchUnique)(ArrayList *this, void *key, size_t size);
    void (*LinearSearchDuplicate)(ArrayList *this, void *key, int *count, int *(*indexes), size_t size);
    
} ArrayList;

void Create(int capacity, size_t size, ArrayList *this);
void Destroy(ArrayList *this);
int GetCapacity(ArrayList*);
int GetLength(ArrayList*);
int Store(ArrayList *this, int index, void *object, size_t size);
int Insert(ArrayList *this, int index, void *object, size_t size);
int AppendFromFront(ArrayList *this, void *object, size_t size);
int AppendFromRear(ArrayList *this, void *object, size_t size);
int Delete(ArrayList *this, int index, size_t size);
int DeleteFromFront(ArrayList *this, size_t size);
int DeleteFromRear(ArrayList *this, size_t size);
void Clear(ArrayList *this);
int Modify(ArrayList *this, int index, void *object, size_t size);
int LinearSearchUnique(ArrayList *this, void *key, size_t size);
void LinearSearchDuplicate(ArrayList * this, void *key, int *count, int *(*indexes), size_t size);

#endif /* ArrayList_h */
