#include <string>
class Station
{
public:
    int station_id;
    std::string station_name;
    static int uid_station;

    Station(std::string name)
    {
        this->station_id = uid_station;
        uid_station += 1;
        this->station_name = name;
    }
};
int Station::uid_station=0;