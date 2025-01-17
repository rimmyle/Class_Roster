#include <iostream>
#include <array>
#include <iomanip>
#include <map>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"
using namespace std;

roster parse(const string studentData[], size_t numStudents);

int main()
{
    // Header
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "C++" << endl;
    cout << "Student: 011389681 Rimmy Le" << endl;
    cout << endl;
         
    // Student Table
    const string studentData[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
         "A5,Rimmy,Le,rle21@wgu.edu,25, 1, 2, 3,SOFTWARE"};
         
    const size_t numStudents = sizeof(studentData) / sizeof(studentData[0]);
    
    // Populate classRoster
    roster classRoster = parse(studentData, numStudents);
    
    classRoster.printAll();
    classRoster.printInvalidEmails();
    
    for (int i = 0; i < numStudents; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    
    classRoster.printByDegreeProgram(DegreeProgram::Software);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
}

roster parse(const string studentData[], size_t numStudents)
{
    roster roster;
    for (size_t i = 0; i < numStudents; i++)
    {
        stringstream ss(studentData[i]);
        string word;
        
        getline(ss, word, ',');
        string studentID = word;
        
        getline(ss, word, ',');
        string firstName = word;
        
        getline(ss, word, ',');
        string lastName = word;
        
        getline(ss, word, ',');
        string emailAddress = word;
        
        getline(ss, word, ',');
        int age = stoi(word);
        
        getline(ss, word, ',');
        int daysInClass1 = stoi(word);
        
        getline(ss, word, ',');
        int daysInClass2 = stoi(word);
        
        getline(ss, word, ',');
        int daysInClass3 = stoi(word);
        
        map<string, int> key = {{"SECURITY", 0}, {"NETWORK", 1}, {"SOFTWARE", 2}};;
        
        DegreeProgram degreeProgram = DegreeProgram::None;
        getline(ss, word, ',');
        
        switch (key[word]) {
            case 0:
                degreeProgram = DegreeProgram::Security;
                break;
            case 1:
                degreeProgram = DegreeProgram::Network;
                break;
            case 2:
                degreeProgram = DegreeProgram::Software;
                break;
            default:
                break;
        }
        
        roster.add(studentID, firstName, lastName, emailAddress, age,
                   daysInClass1, daysInClass2, daysInClass3, degreeProgram);
    }
    return roster;
}