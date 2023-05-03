/*******************************************************************************
    Project         : Bug Tracking System
    File            : Report.cpp
    Date & Time     : 28 September 2022
    Author          : Jugal, Dimanshu, Dhrumil, Apoorva, Anjali
    Description     : This file includes Report member functions
*******************************************************************************/

#include "Report.h"
#include "Employee.h"

using namespace std;

Report :: Report()
{
    choice = 1;
}

/*
 *  Function name : ReportMenu
 *  Description : Displaying Report Menu
 *  Parameter : None
 *  Return type : None
 */
void Report :: ReportMenu()
{
    while (choice != 0)
    {
        cout << "\n\n-------------------------- Reports Menu---------------------------\n";
        cout << "1. Employee Data\n";
        cout << "2. Project Data\n";
        cout << "3. Tickets Raised\n";
        cout << "0. Quit\n";

        cout << "\nEnter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            projecttxt (FILENAME); 
            break;
        
        case 2:
            projecttxt (FILENAME);
            break;
        
        case 3:
            projecttxt (FILENAME);
            break;
 
        case 0: 
            return;        
         
        default: 
            cout << "\n**Enter Valid Choice**\n";
            break;
        }
    }
}

/*
 *  Function name : projecttxt
 *  Description : implementation of report menu
 *  Parameter : filename
 *  Return type : None
 */
void Report :: projecttxt (string filename)
{
    fstream input(filename, ios::in | ios::out);
    string line;
    vector<string> lines;

    while (getline(input, line))
        lines.push_back(line);

    sort (lines.begin(), lines.end(), [](const string& a, const string& b) {
        int wordStartPositionA = 0, wordStartPositionB = 0;//The start of each word in the string

        for (int i = 0; i < 2; i++)//looking for the third word in 1st sentence
            wordStartPositionA = a.find_first_of(' ', wordStartPositionA + 1);

        for (int i = 0; i < 2; i++)//looking for the third word in 2nd sentence
            wordStartPositionB = b.find_first_of(' ', wordStartPositionB + 1);
        
        //Getting where our word ends:
        int wordEndPositionA = a.find_first_of(' ', wordStartPositionA + 1);
        int wordEndPositionB = b.find_first_of(' ', wordStartPositionB + 1);

        //Getting the desired word
        string resultA = a.substr(wordStartPositionA + 1, a.length() - wordEndPositionA - 1);
        string resultB = b.substr(wordStartPositionB + 1, b.length() - wordEndPositionB - 1);

        return resultA < resultB;
    });
    for_each(lines.begin(), lines.end(), [](const string& s) {
        cout << s << endl; });
    return ;
}

Report :: ~Report ()
{
    
}