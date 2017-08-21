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

bool compareDate(string date) { 

	
 time_t now = time(0);
 tm *ltm = localtime(&now);

 ltm->tm_year=1900 + ltm->tm_year;
 ltm->tm_mon = 1 + ltm->tm_mon;
// cout<<"now year:"<<ltm->tm_year<<endl;
// cout<<"now mon:"<<ltm->tm_mon<<endl;
	

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

//EncryptInfo used for encrypting users information
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
		cout<<"You have a booking on "<<user_booklist[i]<<endl;
		}
	}
	}//end of if
}
//ValidateUser

bool ValidateUser(string usr_ID,string usr_Pass)
{
	cout<<"ID:"<<usr_ID<<endl;
	cout<<"Pass:"<<usr_Pass<<endl;
	bool user_chk = false;
	bool pwd_chk = false;
	
 	//char t =data_delimiter; 

	bool temp = false;	
	ifstream ifs(user_file);	
	
	string f1,f2;	
	
	while(!ifs.eof())	{
	
	
		getline(ifs,f1,col_delimiter);
		getline(ifs,f2,col_delimiter);
		istringstream s(f1);
		s>>skipws>>f1;
		
		if(f1 == usr_ID && f2 == usr_Pass) 
		return true;
	
	}	

	return false;	
	
	
	
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

 vector<string> location_list;
	
 FILE * BookFile;
 FILE * UserFile;

 time_t now = time(0);
 tm *ltm = localtime(&now);

 //cout << "Year:"<<1900 + ltm->tm_year<<"\t";
 //cout << "Month:"<<1 + ltm->tm_mon<<"\t";
 //cout << "Day:"<<ltm->tm_mday<<"\t";
 //cout << "Time:"<<ltm->tm_hour<<":"<< ltm->tm_min<<":" << ltm-> tm_sec <<endl;	

if(ifstream(booking_file)) 
cout<<"Booking file loaded successfully\n";

if(ifstream(user_file))
cout<<"User file loaded successfully\n";


string usr_ID;
string usr_Pass;

 cur_User user;

 //user.userID = "TOM";
 //user.passwd = "password";
 while (1) 
{
	cout<<"Enter UserID:";
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

	
}
return 0;
}

//change password
//forget password
//register user
//make booking



