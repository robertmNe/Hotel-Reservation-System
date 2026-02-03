#include "information.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Information::Information():
dateOfBirth()
{
    firstName[0] = '\0';
    lastName[0] = '\0';
}
// Parameter constructor
Information::Information(const char* fn, const char* ln, Date dob)
{
    dateOfBirth = dob;

    // Copying the first and last names onto the arrays
    int i = 0;

    for (i = 0; fn[1]!= '\0' && fn[1]<49; i++) {
       firstName[i] = fn[i];
    }
    firstName[i] = '\0';

    for (i = 0; ln[1]!= '\0' && ln[1]<49; i++) {
       lastName[i] = fn[i];
    }
    lastName[i] = '\0';
}

void Information::printInformation()const{
    cout << firstName << " " << lastName << ", Date of birth: ";
    dateOfBirth.printDate();
}
