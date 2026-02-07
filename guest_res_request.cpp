#include "guest_res_request.h"
#include <iostream>
#include <string>
using namespace std;

int Guest_Res_Request::counter = 0;

// default constructor
Guest_Res_Request::Guest_Res_Request() : visitors()
{
    
    reservationID = ++counter;
    numOfNights = 0;
}

// parameter constructor
Guest_Res_Request::Guest_Res_Request(const Guest& v, int non) : visitors(v)
{
    reservationID = ++counter;
    numOfNights = non;
}

// destructor
Guest_Res_Request::~Guest_Res_Request() {}

// setters
void Guest_Res_Request::setReservationID(int rid) {
    reservationID = rid;
}

void Guest_Res_Request::setNumOfNights(int non) {
    numOfNights = non;
}

void Guest_Res_Request::setVisitors(const Guest& v) {
    visitors = v;
}

// getters
int Guest_Res_Request::getReservationID() const {
    return reservationID;
}

int Guest_Res_Request::getNumOfNights() const {
    return numOfNights;
}

Guest Guest_Res_Request::getVisitors() const {
    return visitors;
}

// print function
void Guest_Res_Request::print() const {
    cout << "Reservation ID: " << reservationID << endl;
    cout << "Number of Nights: " << numOfNights << endl;
    visitors.toString();
}
