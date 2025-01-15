#pragma once
#include <array>
#include <string>
#include "degree.h"
using namespace std;

enum class printFunctionEnum
{
    StudentID,
    FirstName,
    LastName,
    EmailAddress,
    Age,
    DaysInCourse,
    DegreeProgram,
    All
};

static const std::string degreeProgramPrint[] = {"Security", "Network", "Software", "None"};

class student
{
private:
    string studentID, firstName, lastName, emailAddress;
    int age;
    array<int, 3> daysInCourse{0, 0, 0};
    DegreeProgram degreeProgram;
    void printDaysInCourseHelper();

public:
    // Accessor Functions
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    array<int, 3> getDaysInCourse() const;
    DegreeProgram getDegreeProgram() const;
    
    // Mutator Functions
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(array<int, 3> daysInCourse);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    // Constructor
    student(
        string studentID = "New",
        string firstName = "New",
        string lastName = "New",
        string emailAddress = "New",
        int age = 0,
        array<int, 3> daysInCourse = {0, 0, 0},
        DegreeProgram degreeProgram = DegreeProgram::None);
        
    // Print Function
    void print(printFunctionEnum printFunction);
    
    // Destructor Function
    ~student();
};