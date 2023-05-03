/*******************************************************************************
    Project         : Bug Tracking System
    File            : Project.cpp
    Date & Time     : 28 September 2022
    Author          : Jugal, Dimanshu, Dhrumil, Apoorva, Anjali
    Description     : This file includes Project member functions
*******************************************************************************/

#include "Project.h"
#include "Employee.h"
using namespace std;

Project ::  Project ()
{
    ProjectID = 0;
    CreatedBy = 0;
    ProjectDuration = 0;
    choice = 1;
    count = 0;
}

/*
 * Function name : projMenu
 *  Description : Displaying Project Menu
 *  Parameter : e1
 *  Return type : None
 */    
void Project :: projMenu(const Employee& e1)
{
    while (choice != 0)
    {
        cout << "\n\n-------------------------- Projects Menu---------------------------\n";
        cout << "1. Add Project\n";
        cout << "2. Modify Project\n";
        cout << "3. Delete Project\n";
        cout << "0. Quit\n";

        cout << "\nEnter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            projInput(e1); 
            break;
        
        case 2:
            projModify(e1);
            break;
        
        case 3:
            projDel();
            break;
        case 0:
            return;
        
        default:
            break;
        }
    }
}

/*
 * Function name : projInput
 * Description : Add project details
 * Parameter : e1
 * Return type : None
 */ 
void Project :: projInput(Employee e1)
{
    myFile.open(FinePRO,ios::app);
    if (myFile.is_open())
    {
        cout<<"\nEnter ProjectID: ";
        cin>> ProjectID;
        cout<<"Enter Created by: ";
        cout<< e1.EmployeeID<<endl;
        cout<<"Enter Duration: ";
        cin>> ProjectDuration;
        cout<<"Enter Department: ";
        cin>> Department;
        cout<<"Enter Group: ";
        cin>> Group;
        cout<<"Create Date: ";
        cout << ctime(&my_time);
        CreateDate = ctime(&my_time);
        
        string temp;
        string temp2 = ",";
        string temp3 = to_string(e1.EmployeeID);
        string temp4 = to_string(ProjectID);
        string temp5 = to_string(ProjectDuration);

        temp = temp4 + temp2 + temp3 +temp2 + temp5 + temp2 + Department + temp2 + Group+temp2 + CreateDate;
        myFile << temp;
        myFile.close();
    }
    else
    {
        cout<<"\n**Couldn't open the file**\n";
    }
}

/*
 * Function name : projModify
 * Description : Modify project details
 * Parameter : e1
 * Return type : None
 */ 
void Project :: projModify(Employee e1)
{
    string myText;
    string pid;
    cout << "Enter ProjectID to Modify: ";
    cin >> pid;
    count = 0;
    int empID;
    string emp;
    myFile.open(FinePRO,ios::in); 
    if (myFile.is_open())            
    {
        while (getline(myFile,myText))
        {
            string ProjectID1;
            stringstream ss(myText);
            getline(ss, ProjectID1, ',');
            getline(ss, emp, ',');
            empID = stoi(emp);      
            int res = 0;
            int res1 = 0;
            res = cmp(ProjectID1, pid);
            res1 = (empID == e1.EmployeeID);
            if(res1 == false){
                cout<< "\n**Access Denied**\n";
                return;
            }
            if (res == 0 )
            {
                break;
            }
            else
            {
                count++;
            }
        }
        Project :: add_delete_line(FinePRO, count+1, e1);
    }
}

/*
 * Function name : projDel
 * Description : Delete project details
 * Parameter : e1
 * Return type : None
 */ 
void Project :: projDel()
{
    string myText;
    ofstream out(FileProjout);
    count = 0;
    string pid;
    cout << "Enter ProjectID to Delete: ";
    cin >> pid;

    myFile.open(FinePRO,ios::in);
    
    if (myFile.is_open())            
    {
        while (getline(myFile,myText))
        {
            string ProjectID1;
            stringstream ss(myText);

            getline(ss, ProjectID1, ',');
            int res = 0;
            res = cmp(ProjectID1, pid);
            if (res == 0)
            {
                break;
            }
            else
            {
                count++;
            }

        }
        Project :: delete_line(FinePRO, count+1);
    }
}

/*
 * Function name : delete_line
 * Description : delete_line function to delete project
 * Parameters : file_name, n
 * Return type : None
 */ 

// Delete n-th line from given file
void Project ::  delete_line(const char *file_name, int n)
{
    // open file in read mode or in mode
    ifstream is(file_name);
  
    // open file in write mode or out mode
    ofstream ofs;
    ofs.open(FileTEMP, ofstream::out);
  
    // loop getting single characters
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        // if a newline character
        if (c == '\n')
        line_no++;
  
        // file content not to be deleted
        if (line_no != n)
            ofs << c;
    }
  
    // closing output file
    ofs.close();
  
    // closing input file
    is.close();
  
    // remove the original file
    remove(file_name);
  
    // rename the file
    rename(FileTEMP, file_name);
}

/*
 *  Function name : add_delete_line
 *  Description :add_delete_line function to modify project
 *  Parameters : file_name, n, e1
 *  Return type : None
 */ 

void Project ::  add_delete_line(const char *file_name, int n, Employee e1)
{
    // open file in read mode or in mode
    fstream is(file_name);
  
    // open file in write mode or out mode
    ofstream ofs;
    ofs.open(FileTEMP, ofstream::out);
  
    // loop getting single characters
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        // if a newline character
        if (c == '\n')
        line_no++;
  
        // file content not to be deleted
        if (line_no != n)
            ofs << c;
    }    

    // time_t my_time = time(NULL);

    cout<<"Enter ProjectID:";
    cin>> ProjectID;
    cout<<"Enter Created by: ";
    cout<< e1.EmployeeID<<endl;
    cout<<"EnterDuration: ";
    cin>> ProjectDuration;
    cout<<"EnterDepartment: ";
    cin>> Department;
    cout<<"Enter Group: ";
    cin>> Group;
    cout<<"Create date: ";
    cout << ctime(&my_time);
    CreateDate = ctime(&my_time);
    
    string temp;
    string temp2 = ",";
    string temp3 = to_string(e1.EmployeeID);
    string temp4 = to_string(ProjectID);
    string temp5 = to_string(ProjectDuration);
    string temp6 = "\n";

    temp = temp4 + temp2 + temp3 +temp2 + temp5+temp2 + Department+temp2 + Group+temp2 + CreateDate+temp6;
    ofs << temp;

    remove(file_name);
  
    // rename the file
    rename(FileTEMP, file_name);

    // closing output file
    ofs.close();
  
    // closing input file
    is.close();
}

/*
 * Function name : cmp
 * Description : cmp function to compare ProjectID and pid
 * Parameters :  ProjectID, pid
 * Return type : Integer
 */ 
int Project :: cmp(string ProjectID, string pid)
{
    return ProjectID.compare(pid);
}

Project :: ~Project ()
 {
    
 }