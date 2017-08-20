// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include "Booking.h"


#define booking_file "BookingDB.txt"
#define data_delimiter "|"

using namespace entity;
using namespace std;

struct user_session
{
 string userID;
 string passwd;

};

typedef struct user_session cur_User;
cur_User user;

void Booking::CreateBooking(cur_User* member){
(*this)->setUserID(cur_User->getName());
}
void Booking::UpdateBooking(cur_User* member){
(*this)->setUserID(cur_User->getName());
}
void Booking::ChangeBooking(cur_User* member){
(*this)->setUserID(cur_User->getName());
}
void Booking::ViewBooking(cur_User* member){
(*this)->setUserID(cur_User->getName());
}
int main(void)
{
	

	return 0;
}



	