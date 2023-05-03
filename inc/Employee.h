/*******************************************************************************
    Project         : Bug Tracking System
    File            : Employee.h
    Date & Time     : 28 September 2022
    Author          : Jugal, Dimanshu, Dhrumil, Apoorva, Anjali
    Description     : This class file validates the employee credentials
*******************************************************************************/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

/* Employee file Includes ----------------------------------------------------------*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#define FileName "../text/file.txt"
using namespace std;

/* Class Declarations ----------------------------------------------------------*/
/*
 * brief : Employee class
 * It includes declaration of data members and member functions
 */
class Employee
{
    //data members of class employee
    private: 
        string EmployeePassword;
        string EmployeeName;
        string Department;
        int MobileNumber;
        string email;
        string SkypeID;

    public:
        int EmployeeID;
        Employee ();
        ~Employee ();
        //member function of class employee
        //validating employee id and password using login function
        void Login();
};

#endif