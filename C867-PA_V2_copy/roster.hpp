//
//  roster.hpp
//  C867-PA
//
//  Created by muhammad chambers on 1/28/23.
//

#ifndef roster_hpp
#define roster_hpp

#include <stdio.h>
#include <string>
#include "degree.h"
#include "student.hpp"

using namespace std;


class Roster {
public:
    //Constructor
    Roster();
    
    //Setter Methods
    void setClassRosterArrayWithStudentDataArray(const string STUDENTDATA[]);

    //Getter Methods
    Student* getClassRosterArray();
    
    //Methods
    void printAll();
    void printInvalidEmails();
    void remove(string studentId);
    void printAverageDaysInCourse(string studentId);
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    string parseStudentDataTable(const string studentData[], int index);
    string parseStudentDataStr(string parsedStudentDataStr, int index);
    int getAvgFromNumberOfDaysToComplete3CoursesStr(string numberOfDaysToComplete3Courses);
    DegreeProgram convertStrToDegreeProgramEnum(string degreeProgramStr);
    
    
private:
    int arraySize; //Track the size of the classRosterArray pointer
    Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
};

#endif /* roster_hpp */
