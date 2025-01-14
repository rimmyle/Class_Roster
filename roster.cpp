#include <iostream>
#include <array>
#include <string>
#include <iomanip>
#include <regex>
#include "degree.h"
#include "roster.h"
#include "student.h"
using namespace std;

void roster::add(
    string studentID,
    string firstName,
    string lastName,
    string emailAddress,
    int age,
    int daysInCourse1,
    int daysInCourse2,
    int daysInCourse3,
    DegreeProgram degreeProgram)
{
    array<int, 3> daysInCourse{daysInCourse1, daysInCourse2,
                                    daysInCourse3};
                                    
    size_t rosterSize = sizeof(classRosterArray)/sizeof(*classRosterArray);
    
    if (classRosterArray[0] == nullptr)
    {
        classRosterArray[0] = new student(studentID, firstName, lastName, emailAddress,
                                          age, daysInCourse, degreeProgram);
    }
    else if (classRosterArray[1] == nullptr)
    {
        classRosterArray[1] = new student(studentID, firstName, lastName, emailAddress,
                                          age, daysInCourse, degreeProgram);
    }
    else if (classRosterArray[2] == nullptr)
    {
        classRosterArray[2] = new student(studentID, firstName, lastName, emailAddress,
                                          age, daysInCourse, degreeProgram);
    }
    else if (classRosterArray[3] == nullptr)
    {
        classRosterArray[3] = new student(studentID, firstName, lastName, emailAddress,
                                          age, daysInCourse, degreeProgram);
    }
    else
    {
        classRosterArray[4] = new student(studentID, firstName, lastName, emailAddress,
                                          age, daysInCourse, degreeProgram);
    }
}

void roster::remove(string studentID)
{
    size_t rosterSize = sizeof(classRosterArray)/sizeof(*classRosterArray);
    for (size_t i = 0; i < rosterSize; i++)
    {
        if (classRosterArray[i])
        {
            string findID = classRosterArray[i]->getStudentID();
            if (studentID == findID)
            {
                cout << "Student " << findID << " removed." << endl;
                delete classRosterArray[i];
                classRosterArray[i] = nullptr;
            }
        }
        else
        {
            cout << "Error, StudentID not found." << endl;
        }
    }
    cout << endl;
}

// Print Functions
void roster::printAll()
{
    cout << "All Students: " << endl;
    for (int i = 0; i < sizeof(classRosterArray)/sizeof(*classRosterArray); i++)
    {
        if (classRosterArray[i])
        {
            classRosterArray[i]->print(printFunctionEnum::All);
            cout << endl;
        }
    }
}

void roster::printAverageDaysInCourse(string studentID)
{
    float average{};
    cout << studentID << " Average days in course:";
    for (size_t i = 0; i < sizeof(classRosterArray)/sizeof(*classRosterArray); i++)
    {
        if (studentID == classRosterArray[i]->getStudentID())
        {
            array<int, 3> averageDaysArray = classRosterArray[i] -> getDaysInCourse();
            for (size_t i = 0; i < sizeof(averageDaysArray) / sizeof(averageDaysArray[0]); i++)
            {
                average += averageDaysArray[i];
            }
            cout << setprecision(4) << average / 3 << endl;
        }
    }
    cout << endl;
}

void roster::printInvalidEmails()
{
    bool valid = true;
    const regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    for (int i = 0; i < sizeof(classRosterArray)/sizeof(*classRosterArray); i++)
    {
        if (!regex_match(classRosterArray[i]->getEmailAddress(), emailPattern))
        {
            cout << "Student " << classRosterArray[i] -> getStudentID() << " has an invalid E-mail Address: ";
            cout << classRosterArray[i]->getEmailAddress() << endl;
            cout << endl;
            bool valid = false;
        }
    }
    if (!valid)
    {
        cout << "All students have valid E-mail Addresses." << endl;
    }
    cout << endl;
}

void roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    bool inProgram = true;
    cout << degreeProgramPrint[(int)degreeProgram] << " Students:" << endl;
    for (int i = 0; i < sizeof(classRosterArray)/sizeof(*classRosterArray); i++)
    {
        
        if (degreeProgram == classRosterArray[i]->getDegreeProgram())
        {
            classRosterArray[i]->print(printFunctionEnum::All);
            bool inProgram = false;
        }
    }
    cout << endl;
    
    if (!inProgram)
    {
        cout << "There are no students in " << degreeProgramPrint[(int)degreeProgram] << endl;
        cout << endl;
    }
}

// Constructor
roster::roster()
{
    return;
}

// Destructor Function
roster::~roster()
{
}