#include "date.h"
#include <iostream>
using namespace std;


// Default constructor with placeholder date
Date::Date() 
{
    month = 3;
    day = 1;
    year = 2026;
}

// Parameter constructor
Date::Date(int m, int d, int y) 
{
    month = m;
    day = d;
    year = y;
}
// Copy constructor
Date::Date(const Date &other)
{
    month = other.month;
    day = other.day;
    year = other.year;
}
// Destructor
Date::~Date(){}

// Setters
void Date::setMonth(int m) {
    month = m;
}

void Date::setDay(int d) {
    day = d;
}

void Date::setYear(int y) {
    year = y;
}

// Getters
int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

void Date::printDate() const {
    cout << month << "/" << day << "/" << year;
}
