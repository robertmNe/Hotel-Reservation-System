#include "reservation_manager.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor
Reservation_Manager::Reservation_Manager() : arrSize(0) {
    // Initialize the reservation grid to 0 (all spots empty)
    for (int i = 0; i < max_no_of_nights; i++) {
        for (int j = 0; j < no_of_rooms; j++) {
            reservationGrid[i][j] = 0;
        }
    }
}

// Destructor
Reservation_Manager::~Reservation_Manager() {
    // Delete all dynamically allocated Guest_Res_Request objects
    for (int i = 0; i < arrSize; i++) {
        delete arr[i];
    }
}

// Process a reservation request
int Reservation_Manager::processReservation(Guest_Res_Request* request) {
    Guest guests = request->getVisitors();
    int roomNum = guests.getRoomNumber();
    int checkInDay = guests.getCheckIn().getDay();
    int nights = request->getNumOfNights();
    
    // Validate room number
    if (roomNum < 1 || roomNum > no_of_rooms) {
        delete request;
        return -1;
    }
    
    // Check if room is available for all nights
    for (int night = checkInDay - 1; night < checkInDay - 1 + nights; night++) {
        // Check bounds
        if (night < 0 || night >= max_no_of_nights) {
            delete request;
            return -1;
        }
        // Check if room is already booked
        if (reservationGrid[night][roomNum - 1] != 0) {
            // Room not available, delete request
            delete request;
            return -1;
        }
    }
    
    // Room is available for all nights, add reservation
    int resID = request->getReservationID();
    
    // Mark the room as reserved in the grid
    for (int night = checkInDay - 1; night < checkInDay - 1 + nights; night++) {
        reservationGrid[night][roomNum - 1] = resID;
    }
    
    // Add request to the array
    arr[arrSize++] = request;
    
    return resID;
}

// Get reservation details by ID
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

// Cancel a reservation by ID
void Reservation_Manager::cancelReservation(int resID) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i]->getReservationID() == resID) {
            // Remove from grid
            Guest guests = arr[i]->getVisitors();
            int roomNum = guests.getRoomNumber();
            int checkInDay = guests.getCheckIn().getDay();
            int nights = arr[i]->getNumOfNights();
            
            // Clear the reservation from the grid
            for (int night = checkInDay - 1; night < checkInDay - 1 + nights; night++) {
                if (night >= 0 && night < max_no_of_nights) {
                    reservationGrid[night][roomNum - 1] = 0;
                }
            }
            
            // Delete the object
            delete arr[i];
            
            // Shift remaining elements left in the array
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

// Print the reservation grid
void Reservation_Manager::printGrid() const {
    cout << "\n=== Reservation Grid ===" << endl;
    cout << "     ";
    
    // Print room numbers header
    for (int i = 1; i <= no_of_rooms; i++) {
        cout << setw(3) << i;
    }
    cout << endl;
    
    // Print each day (March 1 to March 7)
    for (int i = 0; i < max_no_of_nights; i++) {
        cout << "Mar " << (i + 1) << " ";
        for (int j = 0; j < no_of_rooms; j++) {
            cout << setw(3) << reservationGrid[i][j];
        }
        cout << endl;
    }
}

// Print function
void Reservation_Manager::print() const {
    printGrid();
}
