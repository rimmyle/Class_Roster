#pragma once
#include <array>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

class roster
{
public:
    student *classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    
    // Add Function
    void add(
        string studentID,
        string firstName,
        string lastName,
        string email,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram);
        
    // Remove Function
    void remove(string studentID);
    
    // Print Functions
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    // Constructor
    roster();
    
    // Destructor Function
    ~roster();
};