//
//  student.hpp
//  C867-PA
//
//  Created by muhammad chambers on 1/28/23.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include <string>
#include "degree.h"

using namespace std;


class Student {
public:
    //Constructor
    Student(string studentId, string firstName, string lastName, string emailAddress, int age, int numberOfDaysToComplete3Courses[], DegreeProgram degreeProgram);
    
    //Setter Methods
    void setStudentId(string studentId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setAge(int age);
    void setEmailAddress(string emailAddress);
    void setNumberOfDaysToComplete3Courses(int numberOfDaysToComplete3Courses[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    //Getter Methods
    int getAge();
    string getStudentId();
    string getNumberOfDaysToComplete3Courses();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    string getDegreeProgram();
    
    //Methods
    string print();

private:
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int numberOfDaysToComplete3Courses[3];
    int age;
    DegreeProgram degreeProgram;
};


#endif /* student_hpp */
