#include <iostream>
#include <fstream>
//#include <windows.h>
#include <string>
#include <vector>
#include <sstream>
//#include "Member.h"
#include "Booking.h"
//#include "Manager.h"
#include <time.h>
#include <cstdlib>
using namespace std;

#define booking_file "BookingDB.txt"
#define user_file  "UserDB.txt"
#define col_delimiter '|'
#define line_delimiter '#'




struct user_session
{
 string userID;
 string passwd;

};


string NumberToString ( int Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

bool compareDate(string date) { 

	
 time_t now = time(0);
 tm *ltm = localtime(&now);

 ltm->tm_year=1900 + ltm->tm_year;
 ltm->tm_mon = 1 + ltm->tm_mon;
	

struct tm time;

time.tm_year = atoi(date.substr(6).c_str());
    time.tm_mon = atoi(date.substr(3, 2).c_str());
    time.tm_mday = atoi(date.substr(0, 2).c_str());


time_t temp = mktime(&time);

	if(time.tm_mon == ltm->tm_mon && time.tm_mday - ltm->tm_mday < 7 )
	{
		return true;
	}

	return false;
 
}

string EncryptInfo(string toEncrypt)
{	
	string output = toEncrypt;
	char key[4] = {'D','U','N','E'};
	
	for(int i = 0; i<toEncrypt.size();i++) 
		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
	
	return output;

}



void EncryptFile() 
{
 	fstream f(user_file, fstream::out|fstream::in);
 	 string s;
  	getline( f, s, '\0');
	f.close();
	fstream f2(user_file ,fstream::out|fstream::trunc);
	f2<<EncryptInfo(s);
	f2.close();
}

//DecryptInfo
string DecryptInfo (string ToDecrypt)
{
	EncryptInfo(ToDecrypt);
}
//NotificationUserBooking
void NotifyUserBooking(string name) 
{
	ifstream ifs(booking_file);
	string line;
	string f1,f2;
	
	vector<string>user_booklist;		
	
	time_t now = time(0);
 	tm *ltm = localtime(&now);	
	
	while(!ifs.eof())
	{	
		//check name
		getline(ifs,f1,col_delimiter);
		//check date
		getline(ifs,f2,col_delimiter);
		istringstream s(f1);
		s>>skipws>>f1;
		if(f1 == name) 
		{	
		//push back dates that are found
		 user_booklist.push_back(f2);
		}
		
	}
	
	//testing
	compareDate(user_booklist[0]);
	//compareDate(user_booklist[1]);	
	
	if(user_booklist.size() >= 1)
	{ 
	for (int i = 0; i<user_booklist.size();i++)
	{
	if(compareDate(user_booklist[i])){
		cout << "**Please be reminded that you have a booking on " << user_booklist[i] << "**" << endl;
		}
	}
	}//end of if
}

/*string ForgetPw(string usr_ID,string usr_DOB)
{
	string dob;
	string temppass;
	string temppass2;
	cout << "For verification purpose, please enter your Date of birth (ddmmyy): "
	cin >> dob;
	if (oldpass == usr_Pass)
	{
		cout << "Enter new password: ";
		cin >> temppass;
		cout << "Confirm new password: ";
		cin>>temppass2;
		if (temppass == temppass2)
		{
			ofstream f(user_file);
			if (f) {
			    f<<usr_ID + "|" + temppass + "|";
			return "Password changed successfully!\n";
		}
		else	
		{	return "Passwords do not match!\n";
		}}
	else
		return "Password is incorrect!\n";
	}
} */




string changePw(string usr_ID,string usr_Pass)
{

	string oldpass;
	string temppass;
	string temppass2;
	cout << "Enter old password: ";
	cin >> oldpass;
	if (oldpass == usr_Pass)
	{
		cout << "Enter new password: ";
		cin >> temppass;
		cout << "Confirm new password: ";
		cin>>temppass2;
		if (temppass == temppass2)
		{
			ofstream f(user_file);
			if (f) {
			    f<<usr_ID + "|" + temppass + "|";
			return "Password changed successfully!\n";
		}
		else	
		{	return "Passwords do not match!\n";
		}}
	else
		return "Password is incorrect!\n";
	}
	
}


int submenu (void)
{
while (1) 
{
	string usr_ID;
	string usr_Pass;
	int option;
	char chgpw;
		cout << "\n=============" << endl;
		cout << "Welcome back!" << endl;
		cout << "=============\n" << endl;
		cout << "Please select an option to proceed" << endl;
		cout << "1. Change Password" << endl;
		cout << "2. Make a booking" << endl;
		cout << "3. Profile" << endl;
		cout << "4. Log out\n" << endl;
		cout << "Option: ";
		cin >> option;
		if (option == 1) {
			cout << "Would you like to change password (y/n): ";
			cin >> chgpw;
			if (chgpw == 'y'){
			cout << changePw(usr_ID,usr_Pass);
		}	else if (chgpw == 'n')
		{
			return 0;
		}
		}
		else if (option == 2){
		}
		else if (option == 3){
		}
		else if (option == 4){
			return 0;
		}

		else {
			cout << "\nInvalid input! Please try again.\n";
			
}
}
}

bool ValidateUser(string usr_ID,string usr_Pass)
{
	cout << "Username: ";
	cin >> usr_ID;
	cout << "Password: ";
	cin >> usr_Pass;
	ifstream ifs(user_file);	
	
	string f1,f2;	
	
	while(!ifs.eof())	
	{
		getline(ifs,f1,col_delimiter);
		getline(ifs,f2,col_delimiter);
		istringstream s(f1);
		s>>skipws>>f1;
		
		if(f1 == usr_ID && f2 == usr_Pass) 
		{
		cout << "\nUser account authenticated.\n";
			NotifyUserBooking(usr_ID);
			submenu();
		return true;
		}
		else {
		//cout << "Wrong Username or Password, please try again!" << endl;
		}
	}

	return false;
	
	
}

bool checkDate(int month, int day, int year)
{
	bool temp = true;
    if ((month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) && ( day>31 || day<1) )
    {
        cout << "ERROR" << endl;
	temp = false;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day>30 || day<1) )
    {
        cout << "ERROR" << endl; 
	temp =  false;
    }
    else if ((month == 2) && (year % 4 == 0) && (day>29 || day<1))
    {
        cout << "ERROR" << endl; 
	temp =  false;

    }
    else if ((month = 2) && (year % 4 != 0) && (day>28 || day<1) )
    {
        cout << "ERROR" << endl; 
	temp =  false;
    }
    else if ((year < 1900) || (year > 2017))
    {
        cout << "ERROR" << endl;
	temp =  false;
    }
    else if ((month < 1) || (month > 12))
    {
        cout << "ERROR" << endl;
	temp =  false;
    }

  // if(month == 0 ) temp = false;
   
	return temp;
}


void RegisterUser()
{
	string usrID;
	string passwd;
	string name;
	string nric;
	int month;
	int day;
	int year;
	string dob;
	string membertype;
	string tempday,tempmonth,tempyear;
	
bool validdob = false;

		cout << "Welcome to Country Club Facilities Booking System! Please proceed on with registering with us. Be rest assured that all information will be kept confidential with us." << endl;
		cout << "Enter your preferred Username: ";
		getline(cin,usrID);
		cout << "Enter you Password: ";
		cin >> passwd;
		cout << "Enter your Name: ";
		cin >> name; 
		cout << "Enter your NRIC: ";
		cin >> nric;
		do{
		cout << "Enter your Date of Birth (dd): ";
		cin >> day;
		cout << "Enter your Date of Birth (mm): ";
		cin >> month;
		cout << "Enter your Date of Birth (yyyy): ";
		cin >> year;}
		while(!checkDate(month,day,year));
		
		if (day < 10){
		dob.append ("0");
		}
		tempday=NumberToString(day);
		if (month < 10){
		dob.append ("0");
		}
		tempmonth=NumberToString(month);
		tempyear=NumberToString(year);
		dob.append(tempday);
		dob.append(tempmonth);
		dob.append(tempyear);	
		

		ofstream f(user_file,  fstream::app);
		if (f) 
			f<<usrID + "|" + passwd + "|" + name + "|" + nric + "|" + dob + "|" + "default" + "|" << endl;
		
		cout << "\nCountry Club Member registration completed successfully!\n\n";
}


typedef struct user_session cur_User; //To represent current user 

int main (void)
{

vector<string> location_list;
	
FILE * BookFile;
FILE * UserFile;

time_t now = time(0);
tm *ltm = localtime(&now);

	if(ifstream(booking_file)) 
	cout << "\nBooking file loaded successfully\n";

	if(ifstream(user_file))
	cout << "User file loaded successfully\n";


	string usr_ID;
	string usr_Pass;
	cur_User user;

while (1) 
{

	int option;
		cout << "\n===============================" << endl;
		cout << "Country Club Facilities Booking" << endl;
		cout << "===============================\n" << endl;
		cout << "Please select an option to proceed." << endl;
		cout << "1. Member Log In" << endl;
		cout << "2. Register as new Member" << endl;
		cout << "3. Exit\n" << endl;
		cout << "Option: ";
		cin >> option;
		if (option == 1){
			//while user is logged in do these ()
			ValidateUser(usr_ID, usr_Pass);
		}
		else if (option == 2){
			RegisterUser();
		}
		else if (option == 3)
			break;
		else{
			cout << "\nInvalid input! Please try again." << endl;
		}

	/*cout<<"Enter UserID:";
	cin>>usr_ID;

	cout<<"Enter Password:";
	cin>>usr_Pass;
	if(ValidateUser(usr_ID,usr_Pass) == true)
	{
		cout<<"User account has been validated\n";
		//cout<<"UserID Encrypted is :"<<EncryptInfo(usr_ID);
		//cout<<"\nUserID is:"<<DecryptInfo(usr_ID));
		//EncryptFile();
	 NotifyUserBooking(usr_ID);
	}
*/
	
}
return 0;
}