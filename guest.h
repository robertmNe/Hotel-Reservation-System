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
    Information guestInfo[4];
    int roomNumber;
    int numOfGuest;

    public:

    // default constructor
    Guest();

    // parameter constructor
    Guest(Date ci, Date co, Information gi[], int rn, int nog);

    // destructor
    ~Guest();

    // setters
    void setCheckIn (Date ci);
    void setCheckOut (Date co);
    void setGuestInfo (Information gi);
    void addGuest(const Information& gi);
    void setRoomNumber (int rn);
    void setNumOfGuest (int nog);

    // getters
    Date getCheckIn() const;
    Date getCheckOut() const;
    Information* getGuestInfo();
    int getRoomNumber() const;
    int getNumOfGuest() const;

    // functions
    void toString() const;

};

#endif
