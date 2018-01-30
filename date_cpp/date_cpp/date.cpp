//
//  date.cpp
//  date_cpp
//
//  Created by Namsu Lee on 2018. 1. 28..
//  Copyright © 2018년 Namsu Lee. All rights reserved.
//

#include "date.hpp"
#include <ctime>
#include <iostream>
using namespace std;

Date::Date()
{
    this->year = 1900;
    this->month = 1;
    this->day = 1;
    this->weekday = 1;
}

Date::~Date()
{
    
}

Date::Date(int year, int month, int day) {
    struct tm date = {0,};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    mktime(&date);
    this->year = date.tm_year + 1900;
    this->month = date.tm_mon + 1;
    this->day = date.tm_mday;
    this->weekday = date.tm_wday;
}

Date::Date(char(*date)) {
    struct tm temp = {0,};
    sscanf(date, "%4d%02d%02d", &temp.tm_year, &temp.tm_mon, &temp.tm_mday);
    temp.tm_year -= 1900;
    temp.tm_mon -= 1;
    mktime(&temp);
    this->year = temp.tm_year + 1900;
    this->month = temp.tm_mon + 1;
    this->day = temp.tm_mday;
    this->weekday = temp.tm_wday;
}

Date::Date(const Date& source) {
    this->year = source.year;
    this->month = source.month;
    this->day = source.day;
    this->weekday = source.weekday;
}

Date Date::Today() {
    time_t timer;
    struct tm *today;
    Date _today;
    time(&timer);
    today = localtime(&timer);
    _today.year = today->tm_year + 1900;
    _today.month = today->tm_mon + 1;
    _today.day = today->tm_mday;
    _today.weekday = today->tm_wday;
    
    return _today;
}

Date::operator char*() {
    static char buffer[9];
    sprintf(buffer, "%4d%02d%02d", this->year, this->month, this->day);
    return buffer;
}
/*
Date Date::YesterDay() {
    
}

Date& Date::operator--() {
    
}

Date Date::operator--(int) {
    
}

Date Date::Tomorrow() {
    
}

Date& Date::operator++() {
    
}

Date Date::operator++(int) {
    
}

Date Date::PreviousDate(UShort days) {
    
}

Date Date::operator-(UShort days) {
    
}

Date Date::NextDate(UShort days) {
    
}

Date Date::operator+(UShort days) {
    
}

bool Date::IsEquals(const Date& other) {
    
}

bool Date::operator==(const Date& other) {
    
}


bool Date::IsNotEquals(const Date& other) {
    
}

bool Date::operator!=(const Date& other) {
    
}

bool Date::IsGreaterThan(const Date& other) {
    
}

bool Date::operator>(const Date& other) {
    
}

bool Date::operator>=(const Date& other) {
    
}

bool Date::IsLesserThan(const Date& other) {
    
}

bool Date::operator<(const Date& other) {
    
}

bool Date::operator<=(const Date& other) {
    
}

Date& Date::operator=(const Date& source) {
    
}
 */
