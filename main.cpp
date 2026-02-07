#include <iostream>
#include "reservation_manager.h"
using namespace std;

int main() {
    cout << "A1 Robert Negoescu, Smit Patel C++ Hotel Manager System" << endl;
    
    Reservation_Manager manager;
    
    //case 1 
    cout << "\n--- case 1: booking room 1 for 2 nights (Mar 1-3) ---" << endl;
    Date checkIn1(3, 1, 2026);
    Date checkOut1(3, 3, 2026);
    Guest guest1(checkIn1, checkOut1, nullptr, 1, 0);
    guest1.addGuest(Information("Mike", "Ross", Date(5, 15, 1992)));
    
    Guest_Res_Request* req1 = new Guest_Res_Request(guest1, 2);
    int resID1 = manager.processReservation(req1);
    if (resID1 != -1) {
        cout << "Reservation successful! ID: " << resID1 << endl;
    } else {
        cout << "Reservation failed!" << endl;
    }
    
    // case 2
    cout << "\n--- case 2: booking room 2 for 4 nights (Mar 2-6) ---" << endl;
    Date checkIn2(3, 2, 2026);
    Date checkOut2(3, 6, 2026);
    Guest guest2(checkIn2, checkOut2, nullptr, 2, 0);
    guest2.addGuest(Information("Bad", "Bunny", Date(8, 20, 2006)));
    
    Guest_Res_Request* req2 = new Guest_Res_Request(guest2, 4);
    int resID2 = manager.processReservation(req2);
    if (resID2 != -1) {
        cout << "Reservation successful! ID: " << resID2 << endl;
    } else {
        cout << "Reservation failed!" << endl;
    }
    
    // case 3
    cout << "\n--- case 3: booking Room 1 for Mar 2-4 , ts should fail ---" << endl;
    Date checkIn3(3, 2, 2026);
    Date checkOut3(3, 4, 2026);
    Guest guest3(checkIn3, checkOut3, nullptr, 1, 0);
    guest3.addGuest(Information("Lebron", "James", Date(3, 10, 1940)));
    
    Guest_Res_Request* req3 = new Guest_Res_Request(guest3, 2);
    int resID3 = manager.processReservation(req3);
    if (resID3 != -1) {
        cout << "Reservation successful! ID: " << resID3 << endl;
    } else {
        cout << "Reservation failed! Room not available." << endl;
    }
    
    // case 4
    cout << "\n--- case 4: booking room 5 for 3 nights with 3 guests ---" << endl;
    Date checkIn4(3, 3, 2026);
    Date checkOut4(3, 6, 2026);
    Guest guest4(checkIn4, checkOut4, nullptr, 5, 0);
    guest4.addGuest(Information("Iron", "Man", Date(1, 1, 1988)));
    guest4.addGuest(Information("Silver", "Man", Date(2, 2, 1988)));
    guest4.addGuest(Information("Gold", "Man", Date(3, 3, 1988)));
    
    Guest_Res_Request* req4 = new Guest_Res_Request(guest4, 3);
    int resID4 = manager.processReservation(req4);
    if (resID4 != -1) {
        cout << "Reservation successful! ID: " << resID4 << endl;
    } else {
        cout << "Reservation failed!" << endl;
    }
    
    // display all reservations
    manager.printGrid();
    
    // get reservation details
    cout << "\n--- retrieving details for reservation ID 2 ---" << endl;
    manager.getReservationDetails(2);
    
    // cancel a reservation
    cout << "\n--- cancelling reservation ID 1 ---" << endl;
    manager.cancelReservation(1);
    manager.printGrid();
    
    // case 5
    cout << "\n--- case 5: booking room 1 for Mar 1-3 , should work post-cancellation above ---" << endl;
    Date checkIn5(3, 1, 2026);
    Date checkOut5(3, 3, 2026);
    Guest guest5(checkIn5, checkOut5, nullptr, 1, 0);
    guest5.addGuest(Information("Midas", "Cabal", Date(7, 7, 1995)));
    
    Guest_Res_Request* req5 = new Guest_Res_Request(guest5, 2);
    int resID5 = manager.processReservation(req5);
    if (resID5 != -1) {
        cout << "Reservation successful! ID: " << resID5 << endl;
    } else {
        cout << "Reservation failed!" << endl;
    }
    
    manager.printGrid();
    
    // case 6
    cout << "\n--- case 6: booking room 10 for all 7 nights ---" << endl;
    Date checkIn6(3, 1, 2026);
    Date checkOut6(3, 8, 2026);
    Guest guest6(checkIn6, checkOut6, nullptr, 10, 0);
    guest6.addGuest(Information("Coach", "Mundy", Date(4, 4, 1990)));
    
    Guest_Res_Request* req6 = new Guest_Res_Request(guest6, 7);
    int resID6 = manager.processReservation(req6);
    if (resID6 != -1) {
        cout << "Reservation successful! ID: " << resID6 << endl;
    } else {
        cout << "Reservation failed!" << endl;
    }
    
    // case 7
    cout << "\n--- case 7: fetching details for non-existent reservation ID 999 ---" << endl;
    manager.getReservationDetails(999);
    
    // case 8
    cout << "\n--- case 8: cancelling non-existent reservation ID 999 ---" << endl;
    manager.cancelReservation(999);
    
    // final grid display
    manager.printGrid();
    
    cout << "\n=== done ===" << endl;
    
    return 0;
}
