#include "Member.h"

Member::Member () 
{
}

void Member::BookingPreferences()
{
	pref->getBooking();
}
void Member::UpdateUserInfo()
{
	//switch case to update different info
	cout<<
}

void Member::setMembership(string a) 
{
	int temp = atoi(a);
	Membership = temp;
}
void Member::setDOB(string temp) 
{
	DOB = temp;
}

void Member::setDOB(int day, int month,int year)
{
	DOB+=to_string(day);
	DOB+=to_string(month);
	DOB+=to_string(year);
}

Member::~Member() 
{

}


