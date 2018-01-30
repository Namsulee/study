//
//  date.hpp
//  date_cpp
//
//  Created by Namsu Lee on 2018. 1. 28..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#ifndef date_hpp
#define date_hpp

typedef unsigned int UShort;

class Date
{
public:
    Date();
    ~Date();
    Date(int year, int month, int day);
    Date(char(*date));
    Date(const Date& source);
    static Date Today();
    operator char*();
    
    Date YesterDay();
    Date& operator--();
    Date operator--(int);
    /*
    Date Tomorrow();
    Date& operator++();
    Date operator++(int);
    
    Date PreviousDate(UShort day);
    Date operator-(UShort day);
    
    Date NextDate(UShort day);
    Date operator+(UShort day);
    
    bool IsEquals(const Date& other);
    bool operator==(const Date& other);
    
    bool IsNotEquals(const Date& other);
    bool operator!=(const Date& other);
    
    bool IsGreaterThan(const Date& other);
    bool operator>(const Date& other);
    bool operator>=(const Date& other);
    
    bool IsLesserThan(const Date& other);
    bool operator<(const Date& other);
    bool operator<=(const Date& other);
    
    Date& operator=(const Date& source);
    */
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    int GetWeekDay() const;

private:
    int year;
    int month;
    int day;
    int weekday;
};

// attribute들에 대해서 inline함수들로 구현한다.
inline int Date::GetYear() const {
    return this->year;
}

inline int Date::GetMonth() const {
    return this->month;
}

inline int Date::GetDay() const {
    return this->day;
}

inline int Date::GetWeekDay() const {
    return this->weekday;
}

#endif /* date_hpp */
