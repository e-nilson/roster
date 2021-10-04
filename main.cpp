#include <iostream>
#include "roster.h"

int main()
{    
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Coded in C++" << endl;
    cout << "Name: Erik Nilson" << endl;
    cout << endl;
    cout << endl;
    
    Roster classRoster;
    
    const int numStudents = 5;
    
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Erik,Nilson,enilso1@wgu.edu,33,23,56,30,SOFTWARE"
    };
    
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    
    cout << "DISPLAYING ALL STUDENTS:" << endl;
    cout << "------------------------" << endl << endl;
    classRoster.printAll();
    cout << endl << endl;
    
    cout << "DISPLAYING STUDENTS WITH INVALID EMAILS:" << endl;
    cout << "----------------------------------------" << endl << endl;
    classRoster.printInvalidEmails();
    cout << endl << endl;

    cout << "DISPLAYING AVERAGE DAYS IN COURSE:" << endl;
    cout << "----------------------------------" << endl << endl;
    for (int i = 0; i < classRoster.numStudents; i++)
     {
         classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl << endl;
    
    cout << "THESE STUDENTS ARE IN THE SOFTWARE PROGRAM:" << endl;
    cout << "-------------------------------------------" << endl << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl << endl;
    
    cout << "REMOVING STUDENT ID A3." << endl << endl << endl;
    classRoster.remove("A3");
    cout << endl << endl;

    cout << "DISPLAYING ALL STUDENTS:" << endl;
    cout << "------------------------" << endl << endl;
    classRoster.printAll();
    cout << endl << endl;
    
    cout << "STUDENT WITH ID A3 REMOVED." << endl << endl << endl;
    classRoster.remove("A3");
    cout << endl;
 
    return 0;
}
