#include "Station.h"
#include "Seat.h"
#include "Stationschedule.h"
#include <string>
#include <vector>

class Train
{

public:
    int train_id;
    static int uid_train;
    std::string train_name;
    vector<Seat *> seats;
    vector<Stationschedule *> stationssched;

    Train(std::string name)
    {
        this->train_id = uid_train;
        uid_train += 1;
        this->train_name = name;
    }

    void addseats(Seat *seat)
    {
        seats.push_back(seat);
    }
    void addschedule(Stationschedule *station)
    {
        stationssched.push_back(station);
    }

    void deleteseats(int id)
    {
        for (int i = 0; i < seats.size(); i++)
        {
            Seat *seat = this->seats[i];
            if (seat->seat_id == id)
            {
                seats.erase(seats.begin() + i);
            }
        }
    }

    void checkavailableseats(Seat *inputseat,bool **isseatthere){
           int tseats=inputseat->totalseats;
           int aseats=inputseat->remaining_seats+1;
           int startseat=tseats-aseats;

           if(aseats==0){
               cout<<"no seats available:";
               isseatthere=0;

           }
           cout<<"Available number of seats:"<<aseats<<endl;
           cout<<"Book seats from "<<startseat <<"to"<<tseats<<endl;
    }
};

int Train::uid_train=0;