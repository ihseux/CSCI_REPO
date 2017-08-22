#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Manager.h"

using namespace std;


Manager::Manager()
{
    accountID = "";
    password = "";
    email = "";
    name = "";
    nric = "";
    facilityName = "";
    rates=0.0;
        //ctor
}

void Manager::ManagerMenu(string id)
{
    int choice;
    string quit;
    string facility;
    string update;
    bool success = false;

    do
    {
    cout << "===============================================" << endl;
    cout << "    Country Club Facilities Booking System" << endl;
    cout << "===============================================" << endl;
    cout << "Welcome, " << id << endl << endl;
    cout << "1) Create facility" << endl;
    cout << "2) Update facility" << endl;
    cout << "3) Delete facility" << endl;
    cout << "4) Generate report" << endl;
    cout << "5) Set Charging Rates" << endl;
    cout << "6) Log out" << endl;
    cout << "Please enter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "============================" << endl;
        cout << "      Create facility" << endl;
        cout << "============================" << endl;
        cout << "Please enter the facility name with no space: ";
        cin >> facility;

        success = createFacility(facility);
        if (success == true)
        {
            cout << facility << " has been created successfully!" << endl;
        }
        else
        {
            cout << "(Error)The facility has already exist!" << endl;
        }
    }
    else if (choice == 2)
    {

        cout << "============================" << endl;
        cout << "       Update facility" << endl;
        cout << "============================" << endl;

        cout << "Current facilities:" << endl;
        if (facilitiesList.size() == 0)
        {
            cout << "Currently there are no facility" << endl;
        }
        else
        {
            for (int i=0; i< facilitiesList.size(); i++)
            {
                cout << i+1 << ") " << facilitiesList.at(i) << endl;
            }
        }
        cout << "\nPlease enter the facility you want to update(enter 'q' to return to main menu): ";
        cin >> facility;
        if (facility == "q")
        {
            facility = "";
            cout << "Returning to main menu..." << endl;
        }
        else{
        cout << "\nPlease enter the new facility name: ";
        cin >> update;
        success = updateFacility(facility, update);
        if (success == true)
        {
            cout << "\nThe facility has been updated successfully!" << endl;
        }
        else
        {
            cout << "\n(Error)The facility does not exist!" << endl;
        }
        }
    }
    else if (choice == 3)
    {
        cout << "============================" << endl;
        cout << "       Delete facility" << endl;
        cout << "============================" << endl;

        cout << "Currently existing facilities:" << endl;
        if (facilitiesList.size() == 0)
        {
            cout << "Currently there are no facility" << endl;
        }
        else
        {
            for (int i=0; i< facilitiesList.size(); i++)
            {
                cout << i+1 << ") " << facilitiesList.at(i) << endl;
            }
        }

        cout << "Please enter the facility you want to delete(enter 'q' to return to main menu'): ";
        cin >> facility;
        if (facility == "q")
        {
            break;
            ManagerMenu(id);
        }
        success = deleteFacility(facility);
        if (success == true)
        {
            cout << "'" << facility << "' has been deleted successfully!" << endl;
        }
        else
        {
            cout << "(Error)The facility does not exist!" << endl;
        }
    }
    else if (choice == 4)
    {
        cout << "============================" << endl;
        cout << "       Generate Report" << endl;
        cout << "============================" << endl;
        generateReport();
        cout << "Please enter anything to return to main menu: ";
        cin >> quit;

    }

    else if (choice == 5)
    {
        string subChoice;
        float rates;
        do
        {
        cout << "============================" << endl;
        cout << "     Set Charging Rates" << endl;
        cout << "============================" << endl;
        cout << "Current rate: " << getRates() << endl;
        cout << "\na)Set rate" << "\nb)Return to main menu" << endl;
        cout << "\nPlease enter a choice: ";
        cin >> subChoice;

        if (subChoice == "a")
        {
            cout << "Please enter the rate: ";
            cin >> rates;
            setRates(rates);
            cout << "\nThe rate has successfully set to " << getRates() << endl;
        }

        else if (subChoice == "b")
        {
            cout << "\nReturning to main menu...." << endl;
        }
        else
        {
            cout << "(Error)You have input an invalid choice" << endl;
        }
        }while(subChoice != "b");

    }
        else if (choice < 1 || choice > 6)
        {
            cout << "(Error)You have entered an invalid choice." << endl;
        }
        else
        {
            break;
        }
    }while(choice != 6);

    cout << "\nLogged out successfully." << endl;
    cout << "Thank you for using Country Club Facilities Booking System. Hope to see you again." << endl;

}


void Manager::setName(string a)
{
    name = a;
}


void Manager::setPassword(string a)
{
    password = a;
}


bool Manager::createFacility(string a)
{
    bool createOK = true;
    for (int i=0; i<facilitiesList.size(); i++)
    {
        if (facilitiesList.at(i) == a)
        {
            createOK = false;
            break;
        }
    }
    if (createOK == true)
    {
        facilitiesList.push_back(a);
        return createOK;
    }
    else
    {
        return createOK;
    }
}

bool Manager::updateFacility(string a, string b)
{
    bool updateOK = false;
    for (int i=0; i<facilitiesList.size(); i++)
    {
        if (facilitiesList[i] == a)
        {
            facilitiesList.at(i) = b;
            updateOK = true;
            break;
        }
    }
    return updateOK;
}

bool Manager::deleteFacility(string a)
{
    bool deleteOK = false;
    for (int i=0; i<facilitiesList.size(); i++)
    {
        if (facilitiesList[i] == a)
        {
            facilitiesList.erase(facilitiesList.begin()+i);
            deleteOK = true;
            break;
        }
    }
    return deleteOK;
}

float Manager::getRates()
{
    return rates;
}

string Manager::getMID()
{
    return accountID;
}

string Manager::getMP()
{
    return password;
}


string Manager::getEmail()
{
    return email;
}

string Manager::getNRIC()
{
    return nric;
}

void Manager::generateReport()
{
    string inputLine;
    int duplicate=1;
    //int linesOfDate=0;
    int dateOfBooking[100];
    int dateCounter[10];
    int i=0; //to store the date data in different element of array in "dateOfBooking"
    int j=0; //to store the counter data in different element of array in "dateCounter"
    int temp;
    char* convertLine;
    fstream filestream;
    //vector<int>booking;
    set<int>mySet;
    pair<set<int>::iterator, bool> ret;
    char * DOB;
    int value;

    filestream.open("BookingDB.txt", fstream::in);


    while(getline(filestream, inputLine))
    {
        convertLine = (char*)inputLine.c_str();
        DOB = strtok(convertLine, " |");
        DOB = strtok(NULL, " |");
        value = atoi(DOB);
        dateOfBooking[i] = value;
        i++;
        ret = mySet.insert(value);
    }

    /*while(getline(filestream, inputLine))
    {
        convertLine = (char*)inputLine.c_str();
        DOB = strtok(convertLine, " |");
        DOB = strtok(NULL, " |");
        value = atoi(DOB);
        //while (p != mySet.end())
        for (set<int, less<int> >::iterator p = mySet.begin(); p < mySet.end(); ++p)
        {
            if (value == *p)
            {
                counter++;
                break;
            }
        }
    }*/

    filestream.close();

    set<int, less<int> >::iterator p = mySet.begin();



    for (int a=0; a<i; a++)
    {
        for (int b=0; b<i-1; b++)
        {
            if (dateOfBooking[b] > dateOfBooking[b+1])
            {
                temp = dateOfBooking[b+1];
                dateOfBooking[b+1] = dateOfBooking[b];
                dateOfBooking[b] = temp;
            }
        }
    }


    for (int a=0; a<i; a++)
    {
        if (dateOfBooking[a] == dateOfBooking[a+1])
        {
            duplicate++;
        }
        else if (dateOfBooking[a] != dateOfBooking[a+1])
        {
            dateCounter[j] = duplicate;
            duplicate = 1;
            j++;
        }
    }


    cout << "Summary report for the week: " << endl;
    cout << "Dates: \t\t\t\t\tNumber of bookings" << endl;

    int report=0;
    while(p != mySet.end())
    {
        cout << report+1 << ") " << *p << "\t\t\t\t" << dateCounter[report] << endl;
        p++;
        report++;
    }
        delete dateOfBooking,dateCounter, mySet;
}

void Manager::setRates(float a)
{
    rates = a;
}

Manager::~Manager()
{
    //dtor
}
