#include "guest.h"
#include <iostream>
#include <string>
using namespace std;

// Default Constructor
Guest::Guest()
{
    roomNumber = 0;
    numOfGuest = 0;
}
// Parameter constructor
Guest::Guest (Date ci, Date co, Information gi[], int rn, int ng)
{
    checkIn = ci;
    checkOut = co;
    roomNumber = (rn >= 1 && rn <= 20) ? rn: 0;

    for (int i = 0; i < numOfGuest; i++) {
        guestInfo[i] = gi[i];
    }
} 

void Guest::toString()const {
    // still to be done...
}
