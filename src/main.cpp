/*******************************************************************************
    Project         : Bug Tracking System
    File            : main.cpp
    Date & Time     : 28 September 2022
    Author          : Jugal, Dimanshu, Dhrumil, Apoorva, Anjali
    Description     : This is the main application file
*******************************************************************************/

/* Project Header file Includes ----------------------------------------------------------*/

#include "Employee.h"
#include "Project.h"
#include "Ticket.h"
#include "Report.h"

using namespace std;    

/*
 * Main fulnction
 */
int main()
{
    int choice;

    //Object creation
    Employee e;
    e.Login();

    Project p;
    Ticket t;
    Report r;

    while (true){
        cout << "\n\n-------------------------- BugTrack Menu---------------------------\n";
        cout << "1. Manage Projects\n";
        cout << "2. Manage Tickets\n";
        cout << "3. Reports\n";
        cout << "0. Quit\n";
        cout << "\nEnter your Choice: ";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            p.projMenu(e);            
            break;

        case 2:
            t.ticketMenu(e);
            break;
        case 3:
            r.ReportMenu();
            break;  
        case 0:
            exit(1);
            break;      
        default:
            cout << "\n**Enter Valid Choice**\n";
            break;
        }
    }
}