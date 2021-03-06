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
    ArrayList(int listSize);
    ArrayList(const ArrayList& source);
    ~ArrayList();
    int Store(int index, ArrayData *data);
    int Insert(int index, ArrayData *data);
    int AppendFromFront(ArrayData *data);
    int AppendFromRear(ArrayData *data);
    int Delete(int index);
    int DeleteFromFront(void);
    int DeleteFromRear(void);
    void Clear();
    int Modify(int index, ArrayData *data);
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
