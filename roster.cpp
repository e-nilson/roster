#include <iostream>
#include "roster.h"

   void Roster::parse(string studentData)
{
    DegreeProgram degreeProgram;
        if (studentData.at(1) == '1') degreeProgram = SECURITY;
            else if (studentData.at(1) == '2') degreeProgram = NETWORK;
            else if (studentData.at(1) == '3') degreeProgram = SOFTWARE;
            else if (studentData.at(1) == '4') degreeProgram = SECURITY;
            else if (studentData.at(1) == '5') degreeProgram = SOFTWARE;
            else degreeProgram = SOFTWARE;
        
    int rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
    
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stod(studentData.substr(lhs, rhs - lhs));
    
    int daysInCourse[3];
    for (int i = 0; i < 3; i++)
    {
        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        daysInCourse[i] = stod(studentData.substr(lhs, rhs - lhs));
    }
        add(studentID, firstName, lastName, emailAddress, age, daysInCourse[0], daysInCourse[1], daysInCourse[2], degreeProgram);
}
 
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

void Roster::printInvalidEmails()
{
    bool invalid_email_found = false;

    for (int i=0; i<=this->lastIndex;i++)
    {
        string email = this->classRosterArray[i]->getEmailAddress();
        if ((email.find('@') == string::npos) || (email.find('.') == string::npos) || (email.find(' ') != string::npos))
            {
            invalid_email_found = true;

            cout << "Student with ID " << this->classRosterArray[i]->getStudentID() << " has an invalid email: " << this->classRosterArray[i]->getEmailAddress() << endl;
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    bool student_found = false;

    for (int i = 0; i <= this->lastIndex; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == studentID)
        {
            student_found = true;
            int* daysInCourse = classRosterArray[i]->getDaysInCourse();
            cout << "On average, it took student " << studentID << " " << (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3 << " days to complete their courses." << endl;
        }
    }

   if (!student_found) {
        cout << "Student ID " << studentID << " was not found.";
    
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= this->lastIndex; i++)
    {
        if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram)
        {
            this->classRosterArray[i]->print();
        }
    }
}

void Roster::remove(string studentID)
{
    bool success = false;

    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            success = true;
            if (i < numStudents - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray [numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }

    if (success)
    {
        cout << studentID << " REMOVED FROM ROSTER." << endl;
    }
    else cout << "STUDENT WITH ID " << studentID << " WAS NOT FOUND." << endl << endl;
}
