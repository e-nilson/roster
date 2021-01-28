#include <iostream>
#include "student.h"


//Parameterless constructor (sets to default value)
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
}

//Constructor
    Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;
}

//Destructor
    Student::~Student(){}

//Getters
    string Student::getStudentID() {return this->studentID;}
    string Student::getFirstName() {return this->firstName;}
    string Student::getLastName() {return this->lastName;}
    string Student::getEmailAddress() {return this->emailAddress;}
    int Student::getAge() {return this->age;}
    int* Student::getDaysInCourse() {return this->daysInCourse;}
    DegreeProgram Student::getDegreeProgram() {return this->degreeProgram;}

//Setters
    void Student::setStudentID(string studentID) {this->studentID = studentID;}
    void Student::setFirstName(string firstName) {this->firstName = firstName;}
    void Student::setLastName(string lastName) {this->lastName = lastName;}
    void Student::setEmailAddress(string emailAddress) {this->emailAddress = emailAddress;}
    void Student::setAge(int age) {this->age = age;}
    void Student::setDaysInCourse(int daysInCourse[])
        {
            for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
        }
    void Student::setDegreeProgram(DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram;}

//Print functions
void Student::printHeader()
{
    cout << left << setw(12) << "Student ID";
    cout << left << setw(12) << "First Name";
    cout << left << setw(12) << "Last Name";
    cout << left << setw(25) << "Email";
    cout << left << setw(7) << "Age";
    cout << left << setw(20) << "Days in Course 1";
    cout << left << setw(20) << "Days in Course 2";
    cout << left << setw(20) << "Days in Course 3";
    cout << left << setw(15) << "Degree Program";
    cout << endl;
}

void Student::print()
 {
    cout << left << setw(12) << this->studentID;
    cout << left << setw(12) << this->firstName;
    cout << left << setw(12) << this->lastName;
    cout << left << setw(25) << this->emailAddress;
    cout << left << setw(7) << this->age;
    cout << left << setw(20) << this->daysInCourse[0];
    cout << left << setw(20) << this->daysInCourse[1];
    cout << left << setw(20) << this->daysInCourse[2];
    cout << left << setw(15) << degreeProgramStrings[this->degreeProgram];
    cout << endl;
}
