#include "guest.h"
#include <iostream>
#include <string>
using namespace std;

// Default Constructor
Guest::Guest()
{
    roomNumber = 0;
    numOfGuest = 0;
}
// Parameter constructor
Guest::Guest (Date ci, Date co, Information gi[], int rn, int ng)
{
    checkIn = ci;
    checkOut = co;
    roomNumber = (rn >= 1 && rn <= 20) ? rn: 0;
    numOfGuest = (ng >= 0 && ng <= 4) ? ng : 0;

    for (int i = 0; i < numOfGuest && i<4; i++) {
        guestInfo[i] = gi[i];
    }
} 

// Destructor
Guest::~Guest() {}

// Setters
void Guest::setCheckIn(Date ci) {
    checkIn = ci;
}

void Guest::setCheckOut(Date co) {
    checkOut = co;
}

void Guest::setGuestInfo(Information gi) {
    if (numOfGuest < 4) {
        guestInfo[numOfGuest++] = gi;
    }
}

void Guest::addGuest(const Information& gi) {
    if (numOfGuest < 4) {
        guestInfo[numOfGuest++] = gi;
    }
}

void Guest::setRoomNumber(int rn) {
    if (rn >= 1 && rn <= 20) {
        roomNumber = rn;
    }
}

void Guest::setNumOfGuest(int nog) {
    if (nog >= 0 && nog <= 4) {
        numOfGuest = nog;
    }
}

// Getters
Date Guest::getCheckIn() const {
    return checkIn;
}

Date Guest::getCheckOut() const {
    return checkOut;
}

Information* Guest::getGuestInfo() {
    return guestInfo;
}

int Guest::getRoomNumber() const {
    return roomNumber;
}

int Guest::getNumOfGuest() const {
    return numOfGuest;
}

void Guest::toString()const {
    cout << "Room Number: " << roomNumber << endl;
    cout << "Check-in Date: ";
    checkIn.printDate();
    cout << endl;
    cout << "Check-out Date: ";
    checkOut.printDate();
    cout << endl;
    cout << "Number of Guests: " << numOfGuest << endl;
    for (int i = 0; i < numOfGuest; i++) {
        cout << "Guest " << (i + 1) << " - ";
        guestInfo[i].printInformation();
        cout << endl;
        }
}
