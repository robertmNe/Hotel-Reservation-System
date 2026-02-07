#include "reservation_manager.h"
#include <iostream>
#include <iomanip>
using namespace std;

//constructor
Reservation_Manager::Reservation_Manager() : arrSize(0) {
    // Initialize the reservation grid to 0 (all spots empty)
    for (int i = 0; i < max_no_of_nights; i++) {
        for (int j = 0; j < no_of_rooms; j++) {
            reservationGrid[i][j] = 0;
        }
    }
}

//destructor
Reservation_Manager::~Reservation_Manager() {
    // Delete all dynamically allocated Guest_Res_Request objects
    for (int i = 0; i < arrSize; i++) {
        delete arr[i];
    }
}

//process a reservation req
int Reservation_Manager::processReservation(Guest_Res_Request* request) {
    Guest guests = request->getVisitors();
    int roomNum = guests.getRoomNumber();
    int checkInDay = guests.getCheckIn().getDay();
    int nights = request->getNumOfNights();
    
    //validates room number
    if (roomNum < 1 || roomNum > no_of_rooms) {
        delete request;
        return -1;
    }
    
    //check if room is available for all nights
    for (int night = checkInDay - 1; night < checkInDay - 1 + nights; night++) {
        //check bounds
        if (night < 0 || night >= max_no_of_nights) {
            delete request;
            return -1;
        }
        //checks if a room is already booked
        if (reservationGrid[night][roomNum - 1] != 0) {
            //if it isnt, deletes request
            delete request;
            return -1;
        }
    }
    
    //room is available, adds reservation
    int resID = request->getReservationID();
    
    //marks reservation in the grid 
    for (int night = checkInDay - 1; night < checkInDay - 1 + nights; night++) {
        reservationGrid[night][roomNum - 1] = resID;
    }
    
    //adds the req to array
    arr[arrSize++] = request;
    
    return resID;
}

//fetch details from a reservation ID
void Reservation_Manager::getReservationDetails(int resID) const {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i]->getReservationID() == resID) {
            cout << "\n=== Reservation Details ===" << endl;
            arr[i]->print();
            return;
        }
    }
    cout << "Reservation ID " << resID << " not found." << endl;
}

//cancel a reservation by ID 
void Reservation_Manager::cancelReservation(int resID) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i]->getReservationID() == resID) {
            //removes from grid
            Guest guests = arr[i]->getVisitors();
            int roomNum = guests.getRoomNumber();
            int checkInDay = guests.getCheckIn().getDay();
            int nights = arr[i]->getNumOfNights();
            
            //clear reservation from grid 
            for (int night = checkInDay - 1; night < checkInDay - 1 + nights; night++) {
                if (night >= 0 && night < max_no_of_nights) {
                    reservationGrid[night][roomNum - 1] = 0;
                }
            }
            
            //deletes the object
            delete arr[i];
            
            //shift elements in array left 
            for (int j = i; j < arrSize - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arrSize--;
            
            cout << "Reservation " << resID << " cancelled successfully." << endl;
            return;
        }
    }
    cout << "Reservation ID " << resID << " not found." << endl;
}

//print the grid 
void Reservation_Manager::printGrid() const {
    cout << "\n=== Reservation Grid ===" << endl;
    cout << "     ";
    
    //print room numbers
    for (int i = 1; i <= no_of_rooms; i++) {
        cout << setw(3) << i;
    }
    cout << endl;
    
    //prints each day 
    for (int i = 0; i < max_no_of_nights; i++) {
        cout << "Mar " << (i + 1) << " ";
        for (int j = 0; j < no_of_rooms; j++) {
            cout << setw(3) << reservationGrid[i][j];
        }
        cout << endl;
    }
}

//print function
void Reservation_Manager::print() const {
    printGrid();
}
