//
//  ArrayList.c
//  ArrayList_C
//
//  Created by Namsu Lee on 2018. 2. 19..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#include "ArrayList.h"
#include <stdlib.h>
#include <memory.h>

void Create(int capacity, size_t size, ArrayList *this)
{
    this->capacity = capacity;
    this->length = 0;
    this->front = calloc(capacity, size);
    
    this->GetCapacity = GetCapacity;
    this->GetLength = GetLength;
    this->Store = Store;
    this->Insert = Insert;
    this->AppendFromFront = AppendFromFront;
    this->AppendFromRear = AppendFromRear;
    this->Delete = Delete;
    this->DeleteFromFront = DeleteFromFront;
    this->DeleteFromRear = DeleteFromRear;
}

void Destroy(ArrayList *this)
{
    ;
}
int GetCapacity(ArrayList *this)
{
    return this->capacity;
}
int GetLength(ArrayList *this)
{
    return this->length;
}
int Store(ArrayList *this, int index, void *object, size_t size)
{
    memcpy(this->front + (index*size), object, size);
    this->length++;
    
    return index;
}
int Insert(ArrayList *this, int index, void *object, size_t size)
{
    void *temp = NULL;
    int i = 0;
    int j = 0;
    
    if (this->capacity > 1) {
        temp = calloc(this->capacity+1, size);
    }
    
    while (i < index) {
        memcpy(temp + (j*size), this->front + (i * size), size);
        j++;
        i++;
    }
    
    i = index + 1;
    while (i < this->length) {
        memcpy(temp + (j*size), this->front + (i * size), size);
    }
    
    if (this->front != NULL)
        free(this->front);
    
    if (this->capacity > 1)
        this->front = temp;
    
    this->capacity++;
    
    memcpy((char*)this->front + (index*size), object, size);
    this->length++;
    
    
    return index;
}
int AppendFromFront(ArrayList *this, void *object, size_t size)
{
    void *temp = NULL;
    int i = 0;
    int index = 0;
    
    if (this->capacity > 1) {
        temp = calloc(this->capacity+1, size);
    }
    
    while (i < this->length) {
        memcpy(temp + (i*size)+1, this->front + (i * size), size);
        i++;
    }
   
    if (this->front != NULL)
        free(this->front);
    
    if (this->capacity > 1)
        this->front = temp;
    
    this->capacity++;
    
    memcpy((char*)this->front, object, size);
    this->length++;
    index = 0;
    
    return index;
}
int AppendFromRear(ArrayList *this, void *object, size_t size)
{
    void *temp = NULL;
    int i = 0;
    int index = 0;
    
    if (this->capacity > 1) {
        temp = calloc(this->capacity+1, size);
    }
    
    while (i < this->length) {
        memcpy(temp + (i*size), this->front + (i * size), size);
        i++;
    }
    
    if (this->front != NULL)
    free(this->front);
    
    if (this->capacity > 1)
        this->front = temp;
    
    this->capacity++;
    
    memcpy((char*)this->front + (this->length * size), object, size);
    this->length++;

    index = this->length;
    
    return index;
}

int Delete(ArrayList *this, int index, size_t size)
{
    void *temp = NULL;
    int i = 0;
    int j = 0;
    
    if (this->capacity > 1) {
        temp = calloc(this->capacity-1, size);
    }
    
    while (i < index) {
        memcpy(temp + (j*size), this->front + (i * size), size);
        j++;
        i++;
    }
    
    i = index + 1;
    while (i < this->length) {
        memcpy(temp + (j*size), this->front + (i * size), size);
        j++;
        i++;
    }
    
    if (this->front != NULL)
        free(this->front);
        
    if (this->capacity > 1)
        this->front = temp;
    
    this->capacity--;
    this->length--;
    index = -1;
    
    return index;
}
int DeleteFromFront(ArrayList *this, size_t size)
{
    void *temp = NULL;
    int i = 1;
    int j = 0;
    
    if (this->capacity > 1) {
        temp = calloc(this->capacity-1, size);
    }
    
    while (i < this->length) {
        memcpy(temp + (j*size), this->front + (i * size), size);
        j++;
        i++;
    }
    
    if (this->front != NULL)
        free(this->front);
    
    if (this->capacity > 1)
        this->front = temp;
    
    this->capacity--;
    this->length--;
    
    return -1;
}
int DeleteFromRear(ArrayList *this, size_t size)
{
    void *temp = NULL;
    int i = 0;
    
    if (this->capacity > 1) {
        temp = calloc(this->capacity-1, size);
    }
    
    while (i < this->length-1) {
        memcpy(temp + (i*size), this->front + (i * size), size);
        i++;
    }
    
    if (this->front != NULL)
        free(this->front);
    
    if (this->capacity > 1)
        this->front = temp;
    
    this->capacity--;
    this->length--;
    
    return -1;
}
void Clear(ArrayList *this)
{
    if (this->front != NULL) {
        free(this->front);
        this->front = NULL;
    }
    this->capacity = 0;
    this->length = 0;
}
int Modify(ArrayList *this, int index, void *object, size_t size)
{
    memcpy(((char*)(this->front)) + (index * size), object, size);
    return index;
}
int LinearSearchUnique(ArrayList *this, void *key, size_t size)
{
    int i = 1;
    int index = 0;
    Data *data;
    
    while (i < this->length) {
        data = this->front + (i * size);
        if (data->value == ((Data*)key)->value) {
            index = i;
            break;
        }
        i++;
    }
    
    return index;
}

void LinearSearchDuplicate(ArrayList *this, void *key, int *count, int *(*indexes), size_t size)
{
    int i = 1;
    int k = 0;
    Data *data;
    
    
    while (i <= this->length) {
        data = this->front + (i * size);
        if (data->value >= ((Data*)key)->value) {
            *count = *count + 1;
        }
        i++;
    }
    
    if (*count > 0) {
       indexes = calloc(*count, sizeof(int));
    }
    
    i = 0;
    while (i < *count) {
        data = this->front + (i * size);
        if (data->value >= ((Data*)key)->value) {
            *indexes[k++] = i;
        }
        i++;
    }
}

int BinarySearchUnique(ArrayList *this, void *key, size_t size)
{
    int index = 0;
    int high;
    int low = 1;
    int mid;
    Data *org;
    
    high = this->capacity;
    mid = (high + low) / 2;
    org = (Data*)this->front;
    while (low <= high && (org + (mid*size))->value == ((Data*)key)->value) {
        if ((org + (mid*size))->value < ((Data*)key)->value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    if (low <= high) {
        index = mid;
    }
    
    return index;
}
void BinarySearchDuplicate(ArrayList *this, void *key, int *count, int *(*indexes), size_t size)
{
    int high;
    int low = 1;
    int mid;
    int keyStart;
    int keyEnd;
    int index = 0;
    int i = 1;
    int j = 0;
    Data *org;
    
    high = this->length;
    mid = (high + low) / 2;
    org = (Data*)this->front;
    while (low < high && (org + (mid*size))->value != ((Data*)key)->value) {
        if ((org + (mid*size))->value < ((Data*)key)->value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        index = mid;
        i = index - 1;
    }
    
    while (i >= low && (org + (i*size))->value == ((Data*)key)->value) {
        i--;
    }
    keyStart = i + 1;
    i = keyStart;
    
    while (keyStart <= high && (org + (i*size))->value == ((Data*)key)->value) {
        *count = *count + 1;
        i++;
    }
    keyEnd = i - 1;
    
    if (*count > 0) {
        indexes = calloc(*count, sizeof(int));
    }
    
    i = keyStart;
    
    while (i <= keyEnd && (org + (i*size))->value == ((Data*)key)->value) {
        *indexes[j++] = i;
    }
}
void SelectSort(ArrayList *this);
{
    
}
void BubbleSort(ArrayList *this)
{
    
}
void InsertionSort(ArrayList *this)
{
    
}
void MergeSort(ArrayList *one, ArrayList *other)
{
    
}
void GetAt(ArrayList *this, int index, void *object, size_t size)
{
    object = calloc(1, size);
    memcpy(object, this->front + (index * size), size);
}
