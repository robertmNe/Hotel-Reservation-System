#ifndef GUEST_RES_REQUEST_H
#define GUEST_RES_REQUEST_H
#include "guest.h"
#include <iostream>
#include <string>
using namespace std;

class Guest_Res_Request{

    private:
    static int counter;
    int reservationID;
    int numOfNights;
    Guest visitors;

    public:

    // Default constructor
    Guest_Res_Request();
    // Parameter constructor
    Guest_Res_Request (int rid, int non, const Guest& v);

    // Setters
    void setReservationID (int rid);
    void setNumOfNights (int non);
    void setVisitors (Guest v);

    // Getters
    int getReservationID () const;
    int getNumOfNights () const;
    Guest getVisitors () const;

};

#endif
