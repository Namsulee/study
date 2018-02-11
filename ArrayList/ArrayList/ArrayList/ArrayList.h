//
//  ArrayList.h
//  ArrayList
//
//  Created by Namsu Lee on 2018. 2. 11..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#ifndef ArrayList_h
#define ArrayList_h

typedef struct _ArrayData {
    int data;
} ArrayData;

class ArrayList
{
public:
    ArrayList(int listSize, int size);
    ArrayList(const ArrayList& source);
    ~ArrayList();
    int Store(ArrayData *data, int index, int size);
    int Insert(ArrayData *data, int index, int size);
    int AppendFromFront(ArrayData *data, int size);
    int AppendFromRear(ArrayData *data, int size);
    int Delete(int index, int size);
    int DeleteFromFront(int size);
    int DeleteFromRear(int size);
    void Clear();
    int Modify(int index, ArrayData *data, int size);
    int LinearSearchUniqueArray(ArrayData *data);
    int LinearSearchDuplicateArray(ArrayData *data, int *count);
    
    int GetCapacity() const;
    int GetCurrent() const;
    
private:
    int capacity;
    int current;
    ArrayData *front;
};

inline int ArrayList::GetCapacity() const {
    return this->capacity;
}

inline int ArrayList::GetCurrent() const {
    return this->current;
}
#endif /* ArrayList_h */
