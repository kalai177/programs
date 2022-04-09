#include "Train.h"
#include <string>
#include <vector>

class System
{
public:
    vector<Train *> trains;
    vector<Station *> stations;

    void addtrains(Train *train)
    {
        trains.push_back(train);
    }
    void addstations(Station *station)
    {
        stations.push_back(station);
    }

    void showstations()
    {
        for (int i = 0; i < stations.size(); i++)
        {
            Station *s = this->stations[i];
            cout << s->station_name;
        }
    }

    void showtrains(std::string stationname)
    {
        for (int i = 0; i < trains.size(); i++)
        {
            Train *t = this->trains[i];
            for (int j = 0; j < t->stationssched.size(); j++)
            {
                Stationschedule *s = t->stationssched[j];
                if (s->station_name == stationname)
                {
                    cout << t->train_name;
                }
            }
        }
    }

    void bookticket(string username, int age, string trainname)
    {

        Person p1 = Person(username, age);
        Ticket t1 = Ticket(&p1);
        Seat s1 = Seat(&t1);

        for (int i = 0; i < trains.size(); i++)
        {
            Train *t = this->trains[i];
            if (t->train_name == trainname)
            {
                t->addseats(&s1);
            }
        }
    }

    void checkavailableseats_train(string trainpeer, bool *isseatsthere)
    {
        for (int i = 0; i < trains.size(); i++)
        {
            Train *traintitle = trains[i];
            if (traintitle->train_name == trainpeer)
            {

                int size = traintitle->seats.size();

                for (int j = 0; j < size; j++)
                {

                    Seat *seat_decode = traintitle->seats[j];
                    if (*seat_decode->ticket == NULL)
                    {

                        traintitle->checkavailableseats(seat_decode, &isseatsthere);
                        break;
                    }
                }
            }
        }
    }
};
