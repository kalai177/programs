#include "Ticket.h"

class Seat
{
public:
    int seat_id;
    Ticket *ticket;
    static int uid_id;
    static int remaining_seats;
    static int totalseats;
    Seat()
    {
        this->seat_id = uid_id;

        uid_id += 1;
        this->ticket = NULL;
    }

    Seat(Ticket *ticket)
    {
        this->ticket = ticket;
        this->remaining_seats = this->totalseats - 1;
    }

    bool is_booked()
    {
        if (ticket == NULL)
            return false;
        return true;
    }
    void entertotalseats(int n){
         this->totalseats=n;
    }
    int seatnumber()
    {
        return seat_id;
    }
    Ticket *seat_details()
    {
        return ticket;
    }
};

int Seat::uid_id = 1;
int Seat::totalseats = 0;
int Seat::remaining_seats = 0;