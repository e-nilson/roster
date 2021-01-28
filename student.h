#pragma once
#include <string>
#include <iomanip>
#include "degree.h"

using namespace std;

class Student
{
public:
    const static int daysArraySize = 3;

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[daysArraySize];
    DegreeProgram degreeProgram;
    
public:
//Constructor
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
    
//Destructor
    ~Student();
    
//Getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();
    
    
//Setters
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

//Print functions
    static void printHeader();
    void print();
};
