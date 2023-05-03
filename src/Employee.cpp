/*******************************************************************************
    Project         : Bug Tracking System
    File            : Employee.cpp
    Date & Time     : 28 September 2022
    Author          : Jugal, Dimanshu, Dhrumil, Apoorva, Anjali
    Description     : This file includes employee member function
*******************************************************************************/


#include "Employee.h"

using namespace std;

/*
 * Default Constructor 
 */
Employee :: Employee ()
{
    EmployeeID = 0 ;
    MobileNumber = 0 ;
}

/*
 *  Function name : Login
 *  Description : Validates employee id and password
 *  Parameter : None
 *  Return type : None
 */
void Employee :: Login()
{
    string myText;
    string empid;
    string password;

    //Reads the data from file
    ifstream myReadFile(FileName, ios::in);
    int emId;
    string pass;
    int count = 3;

    while (count--)
    {
        //Taking Employee ID and password from user
        cout << "\nEnter EmployeeID: ";
        cin >> emId;
        cout << "Enter Password: ";
        cin >>pass;
        int flag=0;
        
        while (getline(myReadFile,myText))
        {
            stringstream ss(myText);
            getline(ss, empid, ',');
            EmployeeID = stoi(empid);
            getline(ss, password, ',');

            //validation
            if ((EmployeeID == emId) && (password == pass))
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
        }
        if (flag == 0)
        {
            cout << "\n**Invalid EmployeeID Or Password**\n";
        }
        else
        {
            cout << "\n\n----Logged In---\n";
            return ;
        }
    }
    cout << "\n**Reached Maxinum attempts**\n";
    exit(1);
}

Employee :: ~Employee ()
{
    
}
