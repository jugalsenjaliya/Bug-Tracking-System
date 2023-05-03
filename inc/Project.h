/*******************************************************************************
    Project         : Bug Tracking System
    File            : Project.h
    Date & Time     : 28 September 2022
    Author          : Jugal, Dimanshu, Dhrumil, Apoorva, Anjali
    Description     : This is project class file
*******************************************************************************/

#ifndef PROJECT_H
#define PROJECT_H

/* Project file Includes ----------------------------------------------------------*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <cstring>

#define FinePRO "../text/project.txt"
#define FileProjout "../text/projout.txt"
#define FileTEMP "../text/temp.txt"
#include "Employee.h"
using namespace std;

/* Class Declarations ----------------------------------------------------------*/
/*
 * brief : Project Class
 * It includes declaration of data members and member functions
 */
class Project : public Employee
{
    //project class data members
    private:       
        int ProjectID;
        int CreatedBy;
        string ProjectDescription;
        string CreateDate;
        int ProjectDuration;
        string Department;
        string Group;
        int count;
        fstream myFile;
        time_t my_time = time(NULL);

    //member functions of project class
    public:
        int choice;
        Project ();
        ~Project ();
        void projMenu(const Employee& e1);
        void projInput(Employee e1);
        void projModify(Employee e1);
        void projDel();
        int cmp(string ProjectID, string pid);
        void delete_line(const char *file_name, int n);
        void add_delete_line(const char *file_name, int n, Employee e1);
};
#endif