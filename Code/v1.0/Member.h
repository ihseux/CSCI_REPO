#include <time.h>
#include <iostream>
#include <string>
#include "Booking.h"


using namespace std;

#ifndef MEMBER_H
#define MEMBER_H

enum MembershipType
{
BRONZE,SLIVER,GOLD,PLATINUM
};

class Member
{
private:
string AccountID;
string Password;

string Name;
string NRIC;
string DOB;
MembershipType Membership;
Booking *pref;

void BookingPreferences();
void UpdateUserInfo();
public:
//Accessor
string getAccountID (void){return AccountID;}
string getPassword (void){return Password;}

string getName (void){return Name;}
string getNRIC (void){return NRIC;}
string getDOB (void){return DOB;}

MembershipType getMembership(void){return Membership;}
//Mutators
void setDOB (string temp);
void setDOB (int day,int month, int year);

void setMembership (string a);


void setAccountID (string AccountID)
{
(*this).AccountID = AccountID;
}
void setPassword (string Password)
{
(*this).Password = Password;
}

void setName (string Name)
{
(*this).Name = Name;
}
void setNRIC (string NRIC)
{
(*this).NRIC = NRIC;
}

};

#endif
