#include <iostream>
#include <array>
#include <string>
#include <iomanip>
#include "degree.h"
#include "student.h"
using namespace std;

// Accessor Functions
string student::getStudentID() const
{
    return studentID;
}
string student::getFirstName() const
{
    return firstName;
}
string student::getLastName() const
{
    return lastName;
}
string student::getEmailAddress() const
{
    return emailAddress;
}
int student::getAge() const
{
    return age;
}
array<int, 3> student::getDaysInCourse() const
{
    return daysInCourse;
}
DegreeProgram student::getDegreeProgram() const
{
    return degreeProgram;
}

// Mutator Functions
void setStudentID(string studentID)
{
    studentID = studentID;
}
void setFirstName(string firstName)
{
    firstName = firstName;
}
void setLastName(string lastName)
{
    lastName = lastName;
}
void setEmailAddress(string emailAddress)
{
    emailAddress = emailAddress;
}
void setAge(int age)
{
    age = age;
}
void setDaysInCourse(array<int, 3> daysInCourse)
{
    daysInCourse = daysInCourse;
}
void setDegreeProgram(DegreeProgram degreeProgram)
{
    degreeProgram = degreeProgram;
}

// Constructor
student::student(
    string studentID,
    string firstName,
    string lastName,
    string emailAddress,
    int age,
    array<int, 3> daysInCourse,
    DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->degreeProgram = degreeProgram;
    this->daysInCourse = daysInCourse;
    return;
}

// Private Helper Functions
void student::printDaysInCourseHelper() 
{
    cout << "\t daysInCourse: {" << daysInCourse[0];
        for (int i = 1; i < 3; i++)
        {
            cout <<  "," << daysInCourse[i];
        }
        cout << "}" << endl;
}

// Print Functions
void student::print(printFunctionEnum printFunction)
{
    switch (printFunction)
    {
    case printFunctionEnum::StudentID:
        cout << "Student ID: " << studentID << endl;
        break;
        
    case printFunctionEnum::FirstName:
        cout << "First Name: " << firstName << endl;
        break;
        
    case printFunctionEnum::LastName:
        cout << "Last Name: " << lastName << endl;
        break;
        
    case printFunctionEnum::EmailAddress:
        cout << "Email: " << emailAddress << endl;
        break;
        
    case printFunctionEnum::Age:
        cout << "Age" << age << endl;
        break;
        
    case printFunctionEnum::DaysInCourse:
            printDaysInCourseHelper();
        break;
        
    case printFunctionEnum::DegreeProgram:
        cout << "Degree Program: " << degreeProgramPrint[(int)degreeProgram] << endl;
        break;
        
    case printFunctionEnum::All:
        cout << studentID;
        cout << "\t First Name: " << firstName;
        cout << "\t Last Name: " << lastName;
        cout << "\t Age" << age;
        cout << "\t Email: " << emailAddress;
        
        printDaysInCourseHelper();
        cout << " Degree Program: " << degreeProgramPrint[(int)degreeProgram] << endl;
        break;
        
    default:
        break;
    }
    cout << endl;
}

// Destructor Function
student::~student()
{
}