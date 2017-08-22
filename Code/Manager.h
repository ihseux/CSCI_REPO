#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Manager
{
    private:
        string accountID;
        string password;
        string email;
        string name;
        string nric;
        string facilityName;
        float rates;
        vector<string> facilitiesList;


    public:
        Manager();
        string getMID();
        string getMP();
        string getEmail();
        string getNRIC();
        float getRates();
        void setRates(float);
        void ManagerMenu(string);
        void setID(string);
        void setName(string);
        void setPassword(string);
        bool createFacility(string);
        bool updateFacility(string, string);
        bool deleteFacility(string);
        void generateReport();

        virtual ~Manager();

    protected:
};

#endif // MANAGER_H
