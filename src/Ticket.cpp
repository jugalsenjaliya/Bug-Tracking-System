/*******************************************************************************
    Project         : Bug Tracking System
    File            : Ticket.cpp
    Date & Time     : 28 September 2022
    Author          : Jugal, Dimanshu, Dhrumil, Apoorva, Anjali
    Description     : This file includes Ticket member functions
*******************************************************************************/

#include "Ticket.h"
#include "Employee.h"

using namespace std;

Ticket :: Ticket ()
{
    ProjectID2 = 0 ;
    TicketID = 0 ;
    Assigned = 0 ;
    Estimated = 0 ;
    count  = 0;
    choice = 1;
}

/*
 * Function name : ticketMenu
 *  Description : Displaying Ticket Menu
 *  Parameter : e1
 *  Return type : None
 */
void Ticket :: ticketMenu(const Employee& e1)
{

    while (choice != 0)
    {
        cout << "\n-------------------------- Tickets Menu---------------------------\n";
        cout << "1. Add Ticket\n";
        cout << "2. Modify Ticket\n";
        cout << "3. Close Ticket\n";
        cout << "4. Add note to Ticket\n";
        cout << "5. Add code snippet to Ticket\n";
        cout << "0. Quit\n";

        cout << "\nEnter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        
        case 1:
            ticketInput(e1); 
            break;
        
        case 2:
            ticketModify(e1);
            break;
        
        case 3:
            ticketClose();
            break;
        
        case 4:
            ticketAdd();
            break;

        case 5:
            ticketCode();
            break; 

        case 0:
            return;       
        
        default:
            cout << "Enter Valid Choice\n";
            break;
        }
    }
}

/*
 *  Function name : ticketInput
 *  Description : Adding Tickets
 *  Parameter : e1
 *  Return type : None
 */
void Ticket :: ticketInput(Employee e1)
{
    myFile.open(TicketFILE,ios::app);
    if (myFile.is_open())
    {
        cout<< "Enter TicketID: ";
        cin >> TicketID;
        cout<< "Enter ProjectID: ";
        cin >> ProjectID2;
        cout << "Enter Priority: ";
        cin >> Priority;
        cout<<"Enter Created by: ";
        cout<< e1.EmployeeID<<endl;
        cout << "Enter Bug Decsription: ";
        cin >> BugDesc;
        
        cout<<"Enter Assigned to: ";
        cout<< e1.EmployeeID<<endl;
        cout << "Enter Close Date: ";
        cin >> Closed;
        cout << "Enter Status: ";
        cin >> Status;
        cout << "Enter Estimated Time: ";
        cin >> Estimated;
        
        cout<<"Create date: ";
        cout << ctime(&my_time);
        CreateDate1 = ctime(&my_time);
        
        string temp;
        string temp2 = ",";
        string temp7 = to_string(ProjectID2);
        string temp3 = to_string(e1.EmployeeID);
        string temp4 = to_string(TicketID);
        string temp5 = to_string(Estimated);

        temp = temp7 + temp2 + temp4 + temp2 + Priority + temp2 + temp3 + temp2 + BugDesc +temp2+ temp3 + temp2 + Closed + temp2 + Status + temp2 + temp5 + CreateDate1;
        myFile << temp;
        myFile.close();
    }
    else
    {
        cout<<"Couldn't open the file";
    }
}

/*
 *  Function name : ticketModify
 *  Description : Modifying Ticket details
 *  Parameter : e1
 *  Return type : None
 */
void Ticket :: ticketModify(Employee e1)
{
    string myText;
    ofstream out(TicketPRO);
   
    string pid;
    cout << "Enter TicketID to Modify: ";
    cin >> pid;

    myFile.open(TicketFILE,ios::in);
    count = 0;
    
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
        Ticket :: add_delete_line1(TicketFILE, count+1, e1);
    }
}

/*
 *  Function name : ticketClose
 *  Description : Closing Ticket
 *  Parameter : e1
 *  Return type : None
 */
void Ticket :: ticketClose()
{
    string myText;
    ofstream out(TicketPRO);

    string pid;
    cout << "Enter TicketID to Delete: ";
    cin >> pid;

    myFile.open(TicketFILE,ios::in);
     count = 0;
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
        Ticket :: delete_line1(TicketFILE, count+1);
    }
}

/*
 * Function name : delete_line1
 * Description : delete_line1 function to close ticket
 * Parameters : file_name, n
 * Return type : None
 */ 

// Delete n-th line from given file
void Ticket ::  delete_line1(const char *file_name, int n)
{
    // open file in read mode or in mode
    ifstream is(file_name);
  
    // open file in write mode or out mode
    ofstream ofs;
    ofs.open("../text/temp.txt", ofstream::out);
  
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
    rename("../text/temp.txt", file_name);
}

/*
 * Function name : add_delete_line1
 * Description : add_delete_line1 function to modify ticket
 * Parameters : file_name, n, e1
 * Return type : None
 */ 
void Ticket ::  add_delete_line1(const char *file_name, int n, Employee e1)
{
    // open file in read mode or in mode
    fstream is(file_name);
  
    // open file in write mode or out mode
    ofstream ofs;
    ofs.open("../text/temp.txt", ofstream::out);
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

    cout<< "Enter TicketID: ";
    cin >> TicketID;
    cout<< "Enter ProjectID: ";
    cin >> ProjectID2;
    cout << "Enter Priority: ";
    cin >> Priority;
    cout<<"Enter Created by: ";
    cout<< e1.EmployeeID<<endl;
    cout << "Enter Bug Decsription: ";
    cin >> BugDesc;

    cout<<"Enter Assigned to: ";
    cout<< e1.EmployeeID<<endl;
    cout << "Enter Close Date: ";
    cin >> Closed;
    cout << "Enter Status: ";
    cin >> Status;
    cout << "Enter Estimated Time: ";
    cin >> Estimated;
    
    cout<<"Create date: ";
    cout << ctime(&my_time);
    CreateDate1 = ctime(&my_time);
    
    string temp;
    string temp2 = ",";
    string temp7 = to_string(ProjectID2);
    string temp3 = to_string(e1.EmployeeID);
    string temp4 = to_string(TicketID);
    string temp5 = to_string(Estimated);

    temp = temp7 + temp2 + temp4 + temp2 + Priority + temp2 + temp3 + temp2 + BugDesc +temp2+ temp3 + temp2 + Closed + temp2 + Status + temp2 + temp5 + CreateDate1;
    ofs << temp;

    remove(file_name);
  
    // rename the file
    rename("../text/temp.txt", file_name);

    // closing output file
    ofs.close();
  
    // closing input file
    is.close();
}

/*
 * Function name : cmp
 * Description : cmp function to compare ProjectID1 and pid
 * Parameters :  ProjectID1, pid
 */ 
int Ticket :: cmp(string ProjectID1, string pid)
{
    return ProjectID1.compare(pid);
}

/*
 * Function name : ticketAdd
 * Description : Adding note to Ticket
 * Parameters : e1
 * Return type : None
 */ 
void Ticket :: ticketAdd()
{
    string myText;
    ofstream out(TicketPRO);
    string pid;
    cout << "Enter TicketID to Add Note: ";
    cin >> pid;

    myFile.open(TicketFILE,ios::in);
     count = 0;
    string ProjectID1;
    string TicketID1;
    string Priority1;
    string Created1;
    string BugDesc1;
    string CreateDate2;
    string Assigned1;
    string Closed1;
    string Status1;
    string Estimated1;
    
    if (myFile.is_open())            
    {
        while (getline(myFile,myText))
        {
            stringstream ss(myText);

            getline(ss, ProjectID1, ',');
            getline(ss, TicketID1, ',');
            getline(ss, Priority1, ',');
            getline(ss, Created1, ',');
            getline(ss, BugDesc1, ',');
            getline(ss, CreateDate2, ',');
            getline(ss, Assigned1, ',');
            getline(ss, Closed1, ',');
            getline(ss, Status1, ',');
            getline(ss, Estimated1, ',');
            
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
        Ticket :: add_line1(TicketFILE, count+1,  ProjectID1, TicketID1, Priority1, Created1, BugDesc1, CreateDate2, Assigned1, Closed1, Status1, Estimated1);
    }
}

/*
 * Function name : add_line1
 * Description : add_line1 function to add note in Ticket
 * Parameters : file_name, n, e1, ProjectID1, TicketID1, Priority1, Created1, BugDesc1, CreateDate2, Assigned1, Closed1, Status1, Estimated1
 * Return type : None
 */ 
void Ticket ::  add_line1(const char *file_name, int n,const string& ProjectID1,const string& TicketID1,const string& Priority1,const string& Created1,const string& BugDesc1,const string& CreateDate2,const string& Assigned1,const string& Closed1,const string& Status1,const string& Estimated1)
{
    // open file in read mode or in mode
    fstream is(file_name);
  
    // open file in write mode or out mode
    ofstream ofs;
    ofs.open("../text/temp.txt", ofstream::out);
  
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
    string note1;
    cout << "Enter Note to Add: ";
    cin >> note1;
        
    string temp;
    string temp2 = ",";
    string temp3 = "Note: ";
    string temp5 = "\n";
    string temp4 = temp3 + note1;
 
    temp = ProjectID1 + temp2 + TicketID1 + temp2 + Priority1 + temp2 + Created1 + temp2 + BugDesc1 + temp2 + CreateDate2 + temp2 + Assigned1 + temp2 + Closed1 + temp2 + Status1 + temp2 + Estimated1 + temp4 + temp5;

    ofs << temp;

    remove(file_name);
  
    // rename the file
    rename("../text/temp.txt", file_name);

    // closing output file
    ofs.close();
  
    // closing input file
    is.close();
}

/*
 * Function name : ticketCode
 * Description : Adding Code Snippet to Ticket
 * Parameters : e1
 * Return type : None
 */ 
void Ticket :: ticketCode()
{
    string myText;
    ofstream out(TicketPRO);

    string pid;
    cout << "Enter TicketID to Add Code Snippet: ";
    cin >> pid;

    myFile.open(TicketFILE,ios::in);
    count = 0;
    
    string ProjectID1;
    string TicketID1;
    string Priority1;
    string Created1;
    string BugDesc1;
    string CreateDate2;
    string Assigned1;
    string Closed1;
    string Status1;
    string Estimated1;
    
    if (myFile.is_open())            
    {
        while (getline(myFile,myText))
        {
            stringstream ss(myText);

            getline(ss, ProjectID1, ',');
            getline(ss, TicketID1, ',');
            getline(ss, Priority1, ',');
            getline(ss, Created1, ',');
            getline(ss, BugDesc1, ',');
            getline(ss, CreateDate2, ',');
            getline(ss, Assigned1, ',');
            getline(ss, Closed1, ',');
            getline(ss, Status1, ',');
            getline(ss, Estimated1, ',');
            
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
        Ticket :: add_line2(TicketFILE, count+1, ProjectID1, TicketID1, Priority1, Created1, BugDesc1, CreateDate2, Assigned1, Closed1, Status1, Estimated1);
    }
}

/*
 * Function name : add_line2
 * Description : add_line function for adding code snippet to Ticket
 * Parameters : file_name, n, e1, ProjectID1, TicketID1, Priority1, Created1, BugDesc1, CreateDate2, Assigned1, Closed1, Status1, Estimated1
 * Return type : None
 */ 
void Ticket ::  add_line2(const char *file_name, int n,const string& ProjectID1,const string& TicketID1,const string& Priority1,const string& Created1,const string& BugDesc1,const string& CreateDate2,const string& Assigned1,const string& Closed1,const string& Status1,const string& Estimated1)
{
    // open file in read mode or in mode
    fstream is(file_name);
  
    // open file in write mode or out mode
    ofstream ofs;
    ofs.open("../text/temp.txt", ofstream::out);
  
    // loop getting single characters
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        if (c == '\n')
        line_no++;
  
        if (line_no != n)
            ofs << c;
    }
    string note1;
    cout << "Enter Code Snippet to Add: ";
    getline(cin,note1);
        
    string temp;
    string temp2 = ",";
    string temp3 = ",Code: ";
    string temp5 = "\n";
    string temp4 = temp3 + note1;
 
    temp = ProjectID1 + temp2 + TicketID1 + temp2 + Priority1 + temp2 + Created1 + temp2 + BugDesc1 + temp2 + CreateDate2 + temp2 + Assigned1 + temp2 + Closed1 + temp2 + Status1 + temp2 + Estimated1 + temp4 + temp5;

    ofs << temp;

    remove(file_name);
  
    // rename the file
    rename("../text/temp.txt", file_name);

    // closing output file
    ofs.close();
  
    // closing input file
    is.close();
}

Ticket :: ~Ticket ()
{

}
