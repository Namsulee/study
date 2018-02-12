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

ArrayList::ArrayList(int listSize)
{
    front = (ArrayData *) calloc(listSize, sizeof(ArrayData));
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

int ArrayList::Store(int index, ArrayData *data)
{
    memcpy(((ArrayData*)(this->front)) + (index * sizeof(ArrayData)), data, sizeof(ArrayData));
    return index;
}

int ArrayList::Insert(int index, ArrayData *data)
{
    ArrayData *_data;
    int i = 0;
    
    // alloc memory the capacity + 1
    _data = (ArrayData *) calloc(this->capacity + 1, sizeof(ArrayData));
    
    // Coping the data before index
    while (i < index) {
        memcpy(((ArrayData*)_data) + (i * sizeof(ArrayData)), ((ArrayData*)(this->front)) + (i * sizeof(ArrayData)), sizeof(ArrayData));
        i++;
    }
    
    // Copying the data after index
    while (i < this->current) {
        memcpy(((ArrayData*)_data) + ((i+1) * sizeof(ArrayData)), ((ArrayData*)(this->front)) + (i * sizeof(ArrayData)), sizeof(ArrayData));
        i++;
    }
    
    if (this->front != NULL) {
        free(this->front);
    }
    this->front = _data;
    this->capacity++;;
    memcpy(((ArrayData*)(this->front)) + (index * sizeof(ArrayData)), data, sizeof(ArrayData));
    this->current++;
    
    return index;
}

int ArrayList::AppendFromFront(ArrayData *data)
{
    int index = 0;
    int i = 0;
    ArrayData *_data;
    
    // alloc memory the capacity + 1
    _data = (ArrayData *) calloc(this->capacity + 1, sizeof(ArrayData));
    
    // Copying the data after index
    while (i < this->current) {
        memcpy(((ArrayData*)_data) + ((i+1) * sizeof(ArrayData)), ((ArrayData*)(this->front)) + (i * sizeof(ArrayData)), sizeof(ArrayData));
        i++;
    }
    
    if (this->front != NULL) {
        free(this->front);
    }
    
    this->front = _data;
    this->capacity++;;
    memcpy(((ArrayData*)(this->front)) + (index * sizeof(ArrayData)), data, sizeof(ArrayData));
    this->current++;
    
    return index;
}

int ArrayList::AppendFromRear(ArrayData *data)
{
    int index = 0;
    int i = 0;
    ArrayData *_data;
    
    // alloc memory the capacity + 1
    _data = (ArrayData *) calloc(this->capacity + 1, sizeof(ArrayData));
    
    // Copying the data after index
    while (i < this->current) {
        memcpy(((ArrayData*)_data) + (i * sizeof(ArrayData)), ((ArrayData*)(this->front)) + (i * sizeof(ArrayData)), sizeof(ArrayData));
        i++;
    }
    
    if (this->front != NULL) {
        free(this->front);
    }
    
    this->front = _data;
    this->capacity++;;
    memcpy(((ArrayData*)(this->front)) + (index * sizeof(ArrayData)), data, sizeof(ArrayData));
    this->current++;
    index = this->capacity-1; // point out last index in the array
    
    return index;
}

int ArrayList::Delete(int index)
{
    ArrayData *_data = NULL;
    int i = 0;
    int j = 0;
    
    if (this->capacity > 1) {
        _data = (ArrayData*) calloc(this->capacity-1, sizeof(ArrayData));
    }
    
    while (i < index) {
        memcpy(((ArrayData*)_data) + (j*sizeof(ArrayData)), ((ArrayData*)(this->front)) + (i*sizeof(ArrayData)), sizeof(ArrayData));
        j++;
        i++;
    }
    
    i = index + 1;
    while (i < this->current) {
        memcpy(((ArrayData*)_data) + (j*sizeof(ArrayData)), ((ArrayData*)(this->front)) + (i*sizeof(ArrayData)), sizeof(ArrayData));
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
    index = -1;
    
    return index;
}

int ArrayList::DeleteFromFront(void)
{
    ArrayData *_data = NULL;
    int i = 0;
    int index = 0;
    int size = sizeof(ArrayData);
    
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
    index = -1;
    
    return index;
}

int ArrayList::DeleteFromRear(void)
{
    ArrayData *_data = NULL;
    int i = 0;
    int index = 0;
    int size = sizeof(ArrayData);
    
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
    index = -1;
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

int ArrayList::Modify(int index, ArrayData *data)
{
    int size = sizeof(ArrayData);
    memcpy(((ArrayData*)(this->front)) + (index*size), (ArrayData*)data, size);
    return index;
}
