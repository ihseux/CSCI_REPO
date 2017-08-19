#include <iostream>
#include <fstream>
//#include <windows.h>
#include <string>
//#include <vector>

//#include "Member.h"
//#include "Booking.h"
//#include "Manager.h"
 
using namespace std;

#define booking_file "BookingDB.txt"
#define user_file  "UserDB.txt"
#define data_delimiter '|'
struct user_session
{
 string userID;
 string passwd;

};

//EncryptInfo used for encrypting users information
void EncryptInfo()
{
	ifstream ifs(user_file);
	string templine;
	
}
//DecryptInfo
void DecryptInfo ()
{

}
//NotificationUserBooking
void NotifyUserBooking() 
{

}
//ValidateUser

bool ValidateUser(string usr_ID,string usr_Pass)
{
	ifstream ifs(user_file);
	string tempuser;
	string temppass;
	
	//vector<string>user_list;
	
	
	
	//int colcount = 0;
	//int i =0;
	//string temp =ifs.find(data_delimiter);
	/*while(getline(ifs,templine))
	{
	cout<<templine<<"\n";
	cout<<"COL count:"<<colcount<<"\n";
	if(templine.compare(usr_ID) == 0 ){
	colcount+=1;
	}
 	if(templine.compare(usr_Pass) == 0){
	return true;
	}
	else {
	return false;
	}
	
	}*/

	while(ifs)
	{
	getline(ifs,tempuser,data_delimiter);
	getline(ifs,temppass,data_delimiter);
	
	cout<<tempuser<<"\n";	
	cout<<temppass<<"\n";
	if(usr_Pass == temppass && usr_ID == tempuser)
	return true;
	else 
	return false;
	}

}


/*bool ValidateUser (member* cur_User) 
{
	ifstream ifs(user_file);
	string templine;
	while(getline(ifs,templine,data_delimiter))
	{
	if(templine.compare(cur_User.getUserID()) && templine.compare(cur_User.getPassword())){
	return true;
	}
	else {
	return false;
	}
	}
	


}*/



typedef struct user_session cur_User; //To represent current user 

int main (void)
{
	
 FILE * BookFile;
 FILE * UserFile;
if(ifstream(booking_file)) cout<<"Booking file loaded successfully\n";
if(ifstream(user_file))cout<<"User file loaded successfully\n";


string usr_Id;
string usr_Pass;

 cur_User user;

 //user.userID = "TOM";
 //user.passwd = "password";
 while (1) 
{
	cout<<"Enter UserID:";
	cin>>usr_Id;

	cout<<"Enter Password:";
	cin>>usr_Pass;
	if(ValidateUser(usr_Id,usr_Pass) == true)
	{
		cout<<"User account has been validated\n";
	}
}
return 0;
}

//change password
//forget password
//register user
//make booking



