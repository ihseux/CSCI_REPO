#include <time.h>
#include <iostream>
#include <string>

using namespace std;
#ifndef BOOKING_H
#define BOOKING_H

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

//Mutators
void setLocation(string location)
{(*this).Location = location;}

void setUserID(string userID) 
{(*this).UserID = UserID;}



//Accessors
string getLocation();
string getUserID();
int getAge(string name);
};

#endif
