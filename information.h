#ifndef INFORMATION_H
#define INFORMATION_H
#include "date.h"
#include <iostream>
#include <string>
using namespace std;

class Information{

    private:

    // Member variables
    char firstName[50];
    char lastName[50];
    Date dateOfBirth;       // From part A, using the date class

    public:

    // Default constructor
    Information();
    // Parameter constructor
    Information (const char* fn, const char* ln, Date dob);

    // Setters
    void setFirstName (const char* fn);
    void setLastName (const char* ln);
    void setDateOfBirth (Date dob);

    // Getters
    const char* getFirstName() const;
    const char* getLastName() const;
    Date getDateOfBirth() const;

    //Functions
    void printDateOfBirth() const;

};

#endif
