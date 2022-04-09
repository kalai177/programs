#include "Person.h"
using namespace std;
class Ticket
{
public:
    int ticket_id;
    static int uid;
    Person *person;

    Ticket(Person *person)
    {
        this->ticket_id = uid;
        uid+=1;
        this->person = person;
    }

    int returnid()
    {
        return ticket_id;
    }
    Person *username()
    {
        return person;
    }
};

int Ticket::uid=0;