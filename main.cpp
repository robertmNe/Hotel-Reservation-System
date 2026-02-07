#include <iostream>
#include "reservation_manager.h"
using namespace std;

int main() {
    cout << "=== Hotel Cplusplus Reservation System ===" << endl;
    
    Reservation_Manager manager;
    
    // Test Case 1: Successful reservation - Room 1, 2 nights (Mar 1-3)
    cout << "\n--- Test Case 1: Booking Room 1 for 2 nights (Mar 1-3) ---" << endl;
    Date checkIn1(3, 1, 2026);
    Date checkOut1(3, 3, 2026);
    Guest guest1(checkIn1, checkOut1, nullptr, 1, 0);
    guest1.addGuest(Information("John", "Doe", Date(5, 15, 1990)));
    
    Guest_Res_Request* req1 = new Guest_Res_Request(guest1, 2);
    int resID1 = manager.processReservation(req1);
    if (resID1 != -1) {
        cout << "Reservation successful! ID: " << resID1 << endl;
    } else {
        cout << "Reservation failed!" << endl;
    }
    
    // Test Case 2: Another successful reservation - Room 2, 4 nights (Mar 2-6)
    cout << "\n--- Test Case 2: Booking Room 2 for 4 nights (Mar 2-6) ---" << endl;
    Date checkIn2(3, 2, 2026);
    Date checkOut2(3, 6, 2026);
    Guest guest2(checkIn2, checkOut2, nullptr, 2, 0);
    guest2.addGuest(Information("Jane", "Smith", Date(8, 20, 1985)));
    
    Guest_Res_Request* req2 = new Guest_Res_Request(guest2, 4);
    int resID2 = manager.processReservation(req2);
    if (resID2 != -1) {
        cout << "Reservation successful! ID: " << resID2 << endl;
    } else {
        cout << "Reservation failed!" << endl;
    }
    
    // Test Case 3: Failed reservation - Room 1 already booked for Mar 2
    cout << "\n--- Test Case 3: Attempting to book Room 1 for Mar 2-4 (should fail) ---" << endl;
    Date checkIn3(3, 2, 2026);
    Date checkOut3(3, 4, 2026);
    Guest guest3(checkIn3, checkOut3, nullptr, 1, 0);
    guest3.addGuest(Information("Bob", "Johnson", Date(3, 10, 1992)));
    
    Guest_Res_Request* req3 = new Guest_Res_Request(guest3, 2);
    int resID3 = manager.processReservation(req3);
    if (resID3 != -1) {
        cout << "Reservation successful! ID: " << resID3 << endl;
    } else {
        cout << "Reservation failed! Room not available." << endl;
    }
    
    // Test Case 4: Multiple guests in one room - Room 5, 3 nights (Mar 3-6)
    cout << "\n--- Test Case 4: Booking Room 5 for 3 nights with 3 guests ---" << endl;
    Date checkIn4(3, 3, 2026);
    Date checkOut4(3, 6, 2026);
    Guest guest4(checkIn4, checkOut4, nullptr, 5, 0);
    guest4.addGuest(Information("Alice", "Brown", Date(1, 1, 1988)));
    guest4.addGuest(Information("Tom", "Brown", Date(2, 2, 1987)));
    guest4.addGuest(Information("Emma", "Brown", Date(6, 15, 2010)));
    
    Guest_Res_Request* req4 = new Guest_Res_Request(guest4, 3);
    int resID4 = manager.processReservation(req4);
    if (resID4 != -1) {
        cout << "Reservation successful! ID: " << resID4 << endl;
    } else {
        cout << "Reservation failed!" << endl;
    }
    
    // Display all reservations
    manager.printGrid();
    
    // Test Case 5: Get reservation details
    cout << "\n--- Test Case 5: Retrieving details for Reservation ID 2 ---" << endl;
    manager.getReservationDetails(2);
    
    // Test Case 6: Cancel a reservation
    cout << "\n--- Test Case 6: Cancelling Reservation ID 1 ---" << endl;
    manager.cancelReservation(1);
    manager.printGrid();
    
    // Test Case 7: Book the now-available room
    cout << "\n--- Test Case 7: Booking Room 1 for Mar 1-3 (should succeed now) ---" << endl;
    Date checkIn5(3, 1, 2026);
    Date checkOut5(3, 3, 2026);
    Guest guest5(checkIn5, checkOut5, nullptr, 1, 0);
    guest5.addGuest(Information("Mike", "Wilson", Date(7, 7, 1995)));
    
    Guest_Res_Request* req5 = new Guest_Res_Request(guest5, 2);
    int resID5 = manager.processReservation(req5);
    if (resID5 != -1) {
        cout << "Reservation successful! ID: " << resID5 << endl;
    } else {
        cout << "Reservation failed!" << endl;
    }
    
    manager.printGrid();
    
    // Test Case 8: Edge case - full week reservation
    cout << "\n--- Test Case 8: Booking Room 10 for all 7 nights ---" << endl;
    Date checkIn6(3, 1, 2026);
    Date checkOut6(3, 8, 2026);
    Guest guest6(checkIn6, checkOut6, nullptr, 10, 0);
    guest6.addGuest(Information("Sarah", "Davis", Date(4, 4, 1990)));
    
    Guest_Res_Request* req6 = new Guest_Res_Request(guest6, 7);
    int resID6 = manager.processReservation(req6);
    if (resID6 != -1) {
        cout << "Reservation successful! ID: " << resID6 << endl;
    } else {
        cout << "Reservation failed!" << endl;
    }
    
    // Test Case 9: Try to retrieve non-existent reservation
    cout << "\n--- Test Case 9: Retrieving details for non-existent Reservation ID 999 ---" << endl;
    manager.getReservationDetails(999);
    
    // Test Case 10: Try to cancel non-existent reservation
    cout << "\n--- Test Case 10: Cancelling non-existent Reservation ID 999 ---" << endl;
    manager.cancelReservation(999);
    
    // Final grid display
    manager.printGrid();
    
    cout << "\n=== End of Testing ===" << endl;
    
    return 0;
}
