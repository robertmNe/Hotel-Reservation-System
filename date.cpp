#include "date.h"
#include <iostream>
using namespace std;


// Default constructor with placeholder date
Date::Date() : month(3), day(1), year(2026){}

// Parametric constructor
Date::Date(int m, int d, int y) : month(m), day(d), year(y){}

// Copy constructor
Date::Date (const Date &other) : month(other.month), day(other.day), year(other.day){}

// Destructor
Date::~Date(){}

void Date::printDate() const {
    cout << month << "/" << day << "/" << year;
}
