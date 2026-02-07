#include "information.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Information::Information() :
    dateOfBirth()
{
    firstName[0] = '\0';
    lastName[0] = '\0';
}
// Parameter constructor
Information::Information(const char* fn, const char* ln, Date dob) : dateOfBirth(dob)
{
    // Copying the first and last names onto the arrays
    int i = 0;

    // Copy first name
    while (fn[i] != '\0' && i < 49) {
        firstName[i] = fn[i];
        i++;
    }
    firstName[i] = '\0';

    // Copy last name
    i = 0;
    while (ln[i] != '\0' && i < 49) {
        lastName[i] = ln[i];
        i++;
    }
    lastName[i] = '\0';
}

// Destructor
Information::~Information() {}

// Setters
void Information::setFirstName(const char* fn) {
    int i = 0;
    while (fn[i] != '\0' && i < 49) {
        firstName[i] = fn[i];
        i++;
    }
    firstName[i] = '\0';
}

void Information::setLastName(const char* ln) {
    int i = 0;
    while (ln[i] != '\0' && i < 49) {
        lastName[i] = ln[i];
        i++;
    }
    lastName[i] = '\0';
}

void Information::setDateOfBirth(Date dob) {
    dateOfBirth = dob;
}

// Getters
const char* Information::getFirstName() const {
    return firstName;
}

const char* Information::getLastName() const {
    return lastName;
}

Date Information::getDateOfBirth() const {
    return dateOfBirth;
}

void Information::printInformation()const {
    cout << firstName << " " << lastName << ", Date of birth: ";
    dateOfBirth.printDate();
}
