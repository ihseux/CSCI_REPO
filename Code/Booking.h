#include <time.h>
#include <iostream>
#include <string>

using namespace std;

class Booking{ 
private:
string UserID;
int Age;
string Location;
time_t Day;
time_t time_start;
time_t time_end;

void UpdateBooking();
public:
Booking GetBooking();
void CreateBooking(string name);

void ChangeBooking();
void ViewBooking();


//Accessors
string getLocation();
string getUserID();
int getAge();
};
