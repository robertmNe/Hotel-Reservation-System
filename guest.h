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
    Information storeInfo[3];
    int roomNumber;

    public:
    // Default constructor
    Guest();
    // Parameter constructor
    Guest (Date ci, Date co, Information si, int rn);

    // Setters
    void setCheckIn (Date ci);
    void setCheckOut (Date co);
    void setStoreInfo (Information si);
    void setRoomNumber (int rn);

    // Getters
    Date getCheckIn() const;
    Date getCheckOut() const;
    Information getStoreInfo() const;
    int getRoomNumber() const;

    //Functions
    void toString() const;

};

#endif

