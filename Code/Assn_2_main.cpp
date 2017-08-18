#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;


struct user_session
{
 string userID;
 string passwd;

};

typedef struct user_session cur_User; //To represent current user 

void main (void)
{
 cur_User user;

 user.userID = "TOM";
 user.passwd = "password";
}

