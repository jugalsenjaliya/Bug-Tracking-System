/*******************************************************************************
    Project         : Bug Tracking System
    File            : Report.h
    Date & Time     : 28 September 2022
    Author          : Jugal, Dimanshu, Dhrumil, Apoorva, Anjali
    Description     : This is Report class file
*******************************************************************************/

#ifndef REPOST_H
#define REPOST_H

/* Report file Includes ----------------------------------------------------------*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <cstring>
#include <bits/stdc++.h>
#include <cstdlib>

#define FILENAME "../text/file.txt"
#include "Employee.h"
using namespace std;

/* Class Declarations ----------------------------------------------------------*/
/*
 * brief : Report Class
 * It includes declaration of data members and member functions of class Report
 */
class Report : public Employee
{
    //Report class member functions
    public:
        int choice;
        Report ();
        ~Report ();
        void ReportMenu();
        void projecttxt(string filename);
};
#endif