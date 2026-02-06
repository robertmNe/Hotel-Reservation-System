#ifndef GUEST_H
#define GUEST_H
#include "date.h"
#include "information.h"
#include <iostream>
#include <string>
using namespace std;

class Guest{

    private:

    Date checkIn;
    Date checkOut;
    Information guestInfo[3];
    int roomNumber;
    int numOfGuest;

    public:
    // Default constructor
    Guest();
    // Parameter constructor
    Guest(Date ci, Date co, Information gi[], int rn, int nog);

    // Setters
    void setCheckIn (Date ci);
    void setCheckOut (Date co);
    void setGuestInfo (Information gi);
    void setRoomNumber (int rn);
    void setNumOfGuest (int nog);

    // Getters
    Date getCheckIn() const;
    Date getCheckOut() const;
    Information getGuestInfo() const;
    int getRoomNumber() const;
    int getNumOfGuest;

    //Functions
    void toString() const;

};

#endif
