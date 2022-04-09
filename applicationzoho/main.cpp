#include <iostream>
#include "System.h"
using namespace std;
int main()
{

    System sys = System();

   /*

    // create new station;

    Station station = Station("tirupur");
    sys.addstations(&station);

    // create new train
   Train train  = Train("Ganga");
    sys.addtrains(&train);

    // create stationschedule

    Stationschedule ss = Stationschedule("tirupur", "5.30am", "5.50am");
    train.addschedule(&ss);

    sys.showstations();
    std::string stationn__name;
    cin >> stationn__name;
    sys.showtrains(stationn__name);

    cout << "enter user name";
    std::string username;
    cin >> username;
    int age;
    cin >> age;

    Person p = Person(username, age);

    Ticket ticket = Ticket(&p);

    Seat seat = Seat(&ticket);

    train.addseats(&seat);

    int ticketid = ticket.returnid();
    cout << "Ticket number is" << ticketid << endl;

    int seatnum = seat.seatnumber();

    cout << "Your seat number is" << seatnum << endl;

    cout << "Person name:" << p.name << " Age:" << p.age;


*/





   bool admin;


   cout<<"If you are an admin press 1:" ;
   cin>>admin;

  if(admin==1){
     cout<<"You are an admin now:"<<endl;
     cout<<"Your functions are:"<<endl;
     cout<<"1.Creating a new station \"CODE:1\""<<endl;

     int createnewstation;
     cin>>createnewstation;
     if(createnewstation==1){
           cout<<"Enter no of stations you want to create:";
           int n;
           cin>>n;
           for(int i=0;i<n;i++){
            string s;
            cout<<"Enter the station name:";
            cin>>s;
            Station station = Station(s);
            sys.addstations(&station);
           }
     }
            
     cout<<"2.Creating a new train \"CODE:2\""<<endl;
     int createnewtrain;
     cin>>createnewtrain;

     if(createnewtrain==2){

         cout<<"Enter the number of trains you want ot create:";
         int n;
         cin>>n ;
         for(int j=0;j<n;j++){
            cout<<"Enter the train name:";
            string s;
            cin>>s;
            Train train  = Train(s);
            sys.addtrains(&train);

            cout<<"3.Creating a new stationschedule \"CODE:3\""<<endl;


            int createschedule;
            cin>>createschedule;
            if(createschedule==3){
                cout<<"enter no of stations you want to create:";
                int no_of_stations;
                cin>>no_of_stations;
                for(int k=0; k<no_of_stations;k++){
                string stationname,reachtime,goingtime;
                cout<<"Enter the stationame,reachtime,goingtime:";
                  cin>>stationname>>reachtime>>goingtime;
                 Stationschedule ss = Stationschedule(stationname,reachtime,goingtime);
                 train.addschedule(&ss);

                }

            }

            cout<<"Create seats for the train \"CODE 4\":";

            int createseats;
            cin>>createseats;
            if(createseats==4){
                cout<<"Enter no of seats you want ot create:";
                int noofseats;
                cin>>noofseats;
                Seat createseat;
                createseat.entertotalseats(noofseats);
                for(int x=0;x<noofseats;x++){
                Seat makeseat=Seat();
                }
            }



         }
     }

  bool passenger;
  cout<<"If you are a passenger press 1:";
  cin>>passenger;
  if(passenger==1){
    
    cout<<"The available stations list are:";
    sys.showstations();

    cout<<"Enter the station you want to go:";
    string gostation;
    cin>>gostation;
    cout<<"Here is the list of trains that go by this way:";
    sys.showtrains(gostation);
    
   
    cout<<"Would you like to book a ticket: if yes press 1:";
    bool bookticket;
    cin>>bookticket;
  if(bookticket==1){
    cout<<"Which train would you like to book a ticket:";
    string wanttrain;
    cin>>wanttrain;
    bool isseatsthere=1;
    sys.checkavailableseats_train(wanttrain,&isseatsthere);
    if(isseatsthere==1){
      
       
        
    }

    


  }


     
    


  }



  }

   

  







    return 0;
}