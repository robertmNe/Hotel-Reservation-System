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

    // default constructor
    Guest_Res_Request();

    // parameter constructor
    Guest_Res_Request (const Guest& v, int non);

    // destructor
    ~Guest_Res_Request();

    // setters
    void setReservationID (int rid);
    void setNumOfNights (int non);
    void setVisitors (const Guest& v);

    // getters
    int getReservationID() const;
    int getNumOfNights() const;
    Guest getVisitors() const;

    // print function
    void print() const;

};

#endif
