#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date{

    private:

    // Member variables
    int month;
    int day;
    int year;

    public:

    // default constructor
    Date();
    // parameter constructor
    Date(int m, int d, int y);
    // copy constructor
    Date(const Date &other);

    // setters 
    void setMonth (int m);
    void setDay (int d);
    void setYear (int y);

    // getters
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Functions
    void printDate () const;
};

#endif
