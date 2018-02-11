//
//  ArrayList.cpp
//  ArrayList
//
//  Created by Namsu Lee on 2018. 2. 11..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#include "ArrayList.h"
#include <stdlib.h>
#include <string.h>

ArrayList::ArrayList(int listSize, int size)
{
    front = (ArrayData *) calloc(listSize, size);
    capacity = listSize;
    current = 0;
}

ArrayList::ArrayList(const ArrayList& source)
{
    int i = 0;
    this->capacity = source.capacity;
    this->current = source.current;
    
    this->front = (ArrayData *) calloc(source.capacity, sizeof(ArrayData));
    
    while(i < source.current) {
        memcpy(((ArrayData*)this->front) + (i*sizeof(ArrayData)), ((ArrayData*)(source.front)) + (i*sizeof(ArrayData)), sizeof(ArrayData));
        i++;
    }
}

int ArrayList::Store(ArrayData *data, int index, int size)
{
    memcpy(((ArrayData*)(this->front)) + (index * size), data, size);
    return index;
}

int ArrayList::Insert(ArrayData *data, int index, int size)
{
    ArrayData *_data;
    int i = 0;
    
    // alloc memory the capacity + 1
    _data = (ArrayData *) calloc(this->capacity + 1, sizeof(ArrayData));
    
    // Coping the data before index
    while (i < index) {
        memcpy(((ArrayData*)_data) + (i * size), ((ArrayData*)(this->front)) + (i * size), size);
        i++;
    }
    
    // Copying the data after index
    while (i < this->current) {
        memcpy(((ArrayData*)_data) + ((i+1) * size), ((ArrayData*)(this->front)) + (i * size), size);
        i++;
    }
    
    if (this->front != NULL) {
        free(this->front);
    }
    this->front = _data;
    this->capacity++;;
    memcpy(((ArrayData*)(this->front)) + (index * size), data, size);
    this->current++;
    
    return index;
}

int ArrayList::AppendFromFront(ArrayData *data, int size)
{
    int index = 0;
    int i = 0;
    ArrayData *_data;
    
    // alloc memory the capacity + 1
    _data = (ArrayData *) calloc(this->capacity + 1, sizeof(ArrayData));
    
    // Copying the data after index
    while (i < this->current) {
        memcpy(((ArrayData*)_data) + ((i+1) * size), ((ArrayData*)(this->front)) + (i * size), size);
        i++;
    }
    
    if (this->front != NULL) {
        free(this->front);
    }
    
    this->front = _data;
    this->capacity++;;
    memcpy(((ArrayData*)(this->front)) + (index * size), data, size);
    this->current++;
    
    return index;
}

int ArrayList::AppendFromRear(ArrayData *data, int size)
{
    int index = 0;
    int i = 0;
    ArrayData *_data;
    
    // alloc memory the capacity + 1
    _data = (ArrayData *) calloc(this->capacity + 1, sizeof(ArrayData));
    
    // Copying the data after index
    while (i < this->current) {
        memcpy(((ArrayData*)_data) + (i * size), ((ArrayData*)(this->front)) + (i * size), size);
        i++;
    }
    
    if (this->front != NULL) {
        free(this->front);
    }
    
    this->front = _data;
    this->capacity++;;
    memcpy(((ArrayData*)(this->front)) + (index * size), data, size);
    this->current++;
    index = this->capacity-1; // point out last index in the array
    
    return index;
}

int ArrayList::Delete(int index, int size)
{
    ArrayData *_data = NULL;
    int i = 0;
    int j = 0;
    
    if (this->capacity > 1) {
        _data = (ArrayData*) calloc(this->capacity-1, size);
    }
    
    while (i < index) {
        memcpy(((ArrayData*)_data) + (j*size), ((ArrayData*)(this->front)) + (i*size), size);
        j++;
        i++;
    }
    
    i = index + 1;
    while (i < this->current) {
        memcpy(((ArrayData*)_data) + (j*size), ((ArrayData*)(this->front)) + (i*size), size);
        j++;
        i++;
    }
    
    if (this->front != NULL) {
        free(this->front);
    }
    
    if (this->capacity > 1) {
        this->front = _data;
    }
    
    this->current--;
    this->capacity--;
    index = this->current;
    
    return index;
}

int ArrayList::DeleteFromFront(int size)
{
    ArrayData *_data = NULL;
    int i = 0;
    int index = 0;
    
    if (this->capacity > 1) {
        _data = (ArrayData*) calloc(this->capacity-1, size);
    }
   
    while (i < this->current) {
        memcpy(((ArrayData*)_data) + ((i-1)*size), ((ArrayData*)(this->front)) + (i*size), size);
        i++;
    }
    
    if (this->front != NULL) {
        free(this->front);
    }
    
    if (this->capacity > 1) {
        this->front = _data;
    }
    
    this->current--;
    this->capacity--;
    
    return index;
}

int ArrayList::DeleteFromRear(int size)
{
    ArrayData *_data = NULL;
    int i = 0;
    int index = 0;
    
    if (this->capacity > 1) {
        _data = (ArrayData*) calloc(this->capacity-1, size);
    }
    
    while (i < this->current-1) {
        memcpy(((ArrayData*)_data) + (i*size), ((ArrayData*)(this->front)) + (i*size), size);
        i++;
    }
    
    if (this->front != NULL) {
        free(this->front);
    }
    
    if (this->capacity > 1) {
        this->front = _data;
    }
    
    this->current--;
    this->capacity--;
    index = this->capacity - 1;
    return index;
}

void ArrayList::Clear(void)
{
    if (this->front != NULL) {
        free(this->front);
    }
    this->capacity = 0;
    this->current = 0;
}

int ArrayList::Modify(int index, ArrayData *data, int size)
{
    memcpy(((ArrayData*)(this->front)) + (index*size), (ArrayData*)data, size);
    return index;
}
