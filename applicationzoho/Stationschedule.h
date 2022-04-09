#include <string>

class Stationschedule
{
public:
    int station_id;
    int id;
    static int uid_stationschedule;
    std::string station_name;
    std::string arrival_time;
    std::string departure_time;

    Stationschedule(std::string stationname, std::string starttime, std::string endtime)
    {
        this->id = uid_stationschedule;
        this->station_id = id;
        this->station_name = stationname;
        this->arrival_time = starttime;
        this->departure_time = endtime;
        uid_stationschedule += 1;
    }
};
int Stationschedule::uid_stationschedule=0;
