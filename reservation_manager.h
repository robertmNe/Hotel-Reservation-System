#ifndef reservation_manager_h
#define reservation_manager_h

#include "guest_res_request.h"
#include <iostream>
using namespace std;

class reservation_manager {
    
    private:
        
        static const int max_no_of_nights = 7;
        static const int no_of_rooms = 20;
        Guest_Res_Request* arr[1000];
        int arrSize;
        int reservationGrid[max_no_of_nights][no_of_rooms];
        
    public:
    
        Reservation_Manager();
        
        ~Reservation_Manager();
        
        int processReservation(Guest_Res_Request* request);
        
        void getReservationDetails(int resID) const;
        
        void cancelReservation(int resID);
        
        void printGrid() const;
        
        void print() const;
        
};

#endif