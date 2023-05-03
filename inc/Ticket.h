/*******************************************************************************
    Project         : Bug Tracking System
    File            : Ticket.h
    Date & Time     : 28 September 2022
    Author          : Jugal, Dimanshu, Dhrumil, Apoorva, Anjali
    Description     : This is Ticket class header file 
*******************************************************************************/

#ifndef TICKET_H
#define TICKET_H

/* Ticket file Includes ----------------------------------------------------------*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <cstring>
#include "Employee.h"
#include "Project.h"
#define TicketFILE "../text/tickets.txt"
#define TicketPRO "../text/projout.txt"
using namespace std;

/* Class Declarations ----------------------------------------------------------*/
/*
 * brief : Ticket class
 * It includes declaration of data members and member functions
 */
class Ticket : public Employee
{
    //data members of Ticket class
    private:
        int ProjectID2;
        int TicketID;
        string Priority;
        string BugDesc;
        string CreateDate1;
        int Assigned;
        string Closed;
        string Status;
        int Estimated;
        string Note;
        string Code;
        
        int count=0;
        fstream myFile;
        time_t my_time = time(NULL);
        
    //Member function declarations of Ticket Class
    public:
       int choice;
        Ticket();
        virtual ~Ticket();
        void ticketClose();
        void ticketAdd();
        void ticketCode();
        int cmp(string ProjectID, string pid);
        void ticketMenu(const Employee& e1);
        void ticketInput(Employee e1);
        void ticketModify(Employee e1);
        void delete_line1(const char *file_name, int n);
        void add_delete_line1(const char *file_name, int n, Employee e1);

        void add_line1(const char *file_name, int n,const string& ProjectID1,const string& TicketID1,const string& Priority1,const string& Created1,const string& BugDesc1,const string& CreateDate2,const string& Assigned1,const string& Closed1,const string& Status1,const string& Estimated1);

        void add_line2(const char *file_name, int n,const string& ProjectID1,const string& TicketID1,const string& Priority1,const string& Created1,const string& BugDesc1,const string& CreateDate2,const string& Assigned1,const string& Closed1,const string& Status1,const string& Estimated1);
};
#endif