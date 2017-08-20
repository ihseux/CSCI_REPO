#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <limits>
#include <sstream>
#include "Member.h"

using namespace std;


bool MenuLoop = true;

//MainMenu choice 1
void registerMember() {



	cout << "====================================================\n";
	cout << "\t\tREGISTER ACCOUNT\n\n";
	cout << "Create Your Member ID: ";
	cin >> accountID;

	cout << "Create Your Password: ";
	cin >> password;

	cout << "Confirm Your Password: ";
	cin >> password2;
	while (!(password2 == password) ){
			cout << "Password do not match! Try Again: ";
			cin >> password2;
		}

	cout << "Enter Your First Name: ";
	cin >> Fname;

	cout << "Enter Your Last Name: ";
	cin >> Lname;

	cout << "Enter Your NRIC: ";
	cin >> nric;

	cout << "Enter Your DOB: ";
	while (! (cin >> dob) ){
		cout << "Enter a valid date! Try Again: ";
		cin.clear();
		cin.ignore(132, '\n');
	}

	cout << "Enter Your Email: ";
	cin >> email;

	cout << "Enter Your Membership Type: ";
	cin >> membershipType;
	cout << "====================================================\n";

	        ofstream myfile("member.txt",std::ios_base::app);                                  //Save file structure
		    //myfile.open("member.txt",std::ios_base::app);
	        myfile << "\n";
		    myfile << accountID << ",";
		    myfile << password << ",";
		    myfile << Fname << ",";
		    myfile << Lname << ",";
		    myfile << nric << ",";
		    myfile << dob << ",";
		    myfile << email << ",";
		    myfile << membershipType << "";
		    myfile.close();
		    cout << "Congratulations! Your account has been created!\n";
		    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
		    system("pause");

}

/*void saveFile(){
        ofstream myfile;                                  //Save file structure
	    myfile.open("member.txt");
	    myfile << accountID << "\n";
	    myfile << password << "\n";
	    myfile << name << "\n";
	    myfile << nric << "\n";
	    myfile << dob << "\n";
	    myfile << email << "\n";
	    myfile << membershipType << "\n";
	    myfile.close();
	    std::cin.get();


}*/

/*void login(){

	string line = ",";
	ifstream myfile("member.txt");
	//string accountID;
	//string password;
	string accountID1;
	string password1;

	    cout << "\t\t\t====================================================\n";
		cout << "\t\t\t\t\tLOGIN ACCOUNT\n\n";

		cout << "\t\t\t\tAccount ID: ";
		cin >> accountID1;

		cout <<  "\t\t\t\tPassword: ";
		cin >> password1;

		cout << "\t\t\t====================================================\n";

		bool found = false;

		while (getline(myfile,line)) {

		    stringstream File(line);
		    File >> accountID >> password;

		    if (accountID1 == accountID && password1 == password) {
		        cout << "\t\t\t\t\tLogin Successfully!" << endl;
		        system("pause");
		        found = true;
		        break;

		    }


		} if(!found) {
	        cout << "\t\t\t\t\tInvalid UserName And Password" << endl;
	        system("pause");
	    }

}*/

/*void Login(){

	string line = ",";
	ifstream myfile("member.txt");
	string accountID1;
	string password1;
	bool loginSuccess = false;

	do {
		        cout << "\t\t\t====================================================\n";
				cout << "\t\t\t\t\tLOGIN ACCOUNT\n\n";

				cout << "\t\t\t\tAccount ID: ";
				cin >> accountID1;

				cout <<  "\t\t\t\tPassword: ";
				cin >> password1;

				cout << "\t\t\t====================================================\n";

				if (accountID1 == "1" && password1 == "2") {
				cout << "\t\t\t\tLogin Successfully!" << endl;
			    system("pause");
			    loginSuccess = true;

				}
				else{
					cout << "\t\t\t\tInvalid UserName And Password" << endl;
					cout << "\t\t\t\tLogin Again." << endl;
					system("pause");


				}

	}while (!loginSuccess);



}*/


///////////////////////////////////////////////////////////////////////////////////
//Main Menu choice 2

//Inside Main Menu choice 2
//1.
void changeName(){
/*	ofstream outFile("member.txt");
	ifstream myFile("1.txt");

	string readLine;
	string search;
	string Fname;
	string Lname;

	cout<<"Enter Account ID: ";
	cin>>search;

	while(getline(myFile,readLine))
	{
	    if(readLine == search)
	    {
	        outFile<<readLine;
	        outFile<<endl;

	        cout << "Enter New First Name: ";
	        cin >> Fname;
	        cout << "Enter New Last Name: ";
	        cin >> Lname;

	        outFile << Fname << endl;
	        outFile << Lname << endl;
	    } else {
	        outFile << readLine << endl;
	    }

	}*/
}
/*void changePassword(){

}
void changeEmail(){

}

void changeBack(){


}*/

void updateAccount(){
	int updateAccount;

	 cout << "\n====================================================\n";
	 cout << "\t\tUPDATE ACCOUNT INFO\n";
	 cout << "====================================================\n";
	 cout <<       "\t\t1. Update New Name\n";
	 cout <<       "\t\t2. Update New Account Password \n";
	 cout <<       "\t\t3. Update New Email\n";
	 cout <<       "\t\t4. Back\n";
	 cout << "====================================================\n";
	 cout <<       "\t\tSelect an option: ";
	 cin  >> updateAccount;

	 while (cin.fail())
	 		              {cin.clear();
	 		               cin.ignore();
	 		                cout << "\t\tPlease enter a valid option> ";
	 		                cin >> updateAccount;


}
	 switch (updateAccount){


	 		                case 1:
	 		                	changeName();
	 		                    break;

	 		                case 2:

	 		                    break;

	 		                case 3:

	 		                    break;

	 		                case 4:
	 		                	break;


	 		                default:
	 		                    cout << "\t\tEnter a valid option: ";
	 		                    cin >> updateAccount;

	 		            };
	 		        };


//2.
/*void bookFacility(){


}

//3.
void viewbookingRec(){


}
//4.
void viewcurrentBooking(){


}
//5.
void viewmemberRank(){


}

//6.
void logOut(){



}*/

//Main Menu choice 2
void loginPage() {

	int loginPage;

	        cout << "\n====================================================\n";
		    cout << "\t\tYOU ARE LOGGED IN! \n";
		    cout << "====================================================\n";
		    cout <<       "\t\t1. Update Account Info\n";
		    cout <<       "\t\t2. Book a Facility \n";
		    cout <<       "\t\t3. View My Booking Recommendation\n";
		    cout <<       "\t\t4. View Current Booking\n";
		    cout <<       "\t\t5. View Membership Ranking\n";
		    cout <<       "\t\t6. Logout\n";
		    cout << "====================================================\n";
		    cout <<       "\t\tSelect an option: ";
		    cin  >> loginPage;


		    //Prevents user from entering invalid option
		        while (cin.fail())
		              {cin.clear();
		               cin.ignore();
		                cout << "\t\tPlease enter a valid option> ";
		                cin >> loginPage;
}




switch (loginPage){


		                case 1:
		                	updateAccount();
		                    break;

		                case 2:

		                    break;

		                case 3:

		                    break;

		                case 4:

		                   break;

		                case 5:

		                   break;

		                case 6:

      	                   break;

		                default:
		                    cout << "\t\tEnter a valid option: ";
		                    cin >> loginPage;

		            };
		        };


////////////////////////////////////////////////////////////////////////////////

//Main Menu choice 3

void forgotPassword(){



}



// Main Menu choice 4
void exit(){
  MenuLoop = false;
  cout << "\n\t\tYou have successfully quit!";

  //system ("cls");
  //exit (0);
 };

void mainmenu(){

	//bool repeat = true;
	//while(repeat = true) {
	int mainmenu;

	system ("cls");

    cout << "\n====================================================\n";
    cout << "Welcome to COUNTRY CLUB FACILITY BOOKING SYSTEM. \n";
    cout << "====================================================\n";
    cout <<       "\t\t1. Register \n";
    cout <<       "\t\t2. Login Account\n";
    cout <<       "\t\t3. Forgot Password\n";
    cout <<       "\t\t4. Exit\n";
    cout << "====================================================\n";
    cout <<       "\t\tSelect an option: ";
    cin >> mainmenu;

    //Prevents user from entering invalid option
    while (cin.fail())
          {cin.clear();
           cin.ignore();
            cout << "\t\tPlease enter a valid option> ";
            cin >> mainmenu;

            }


 switch (mainmenu){


        case 1:
            registerMember();
            break;

        case 2:
            loginPage();
            break;

        case 3:

            break;

        case 4:
           exit();
           break;

        default:
            cout << "\t\tEnter a valid option: ";
            cin >> mainmenu;

    };
};

//}

int main() {

	    mainmenu();                                  //Homepage Screen
	    while (MenuLoop == true){mainmenu();};     //Main menu loop

	  //  return 0;
}




