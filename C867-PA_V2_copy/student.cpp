//
//  student.cpp
//  C867-PA
//
//  Created by muhammad chambers on 1/28/23.
//

#include "student.hpp"
#include <iostream>

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int numberOfDaysToComplete3Courses[], DegreeProgram degreeProgram) {
  
    //Calls the setter methods to set the values for the Student Object via the paramteres passed into the constructor
    setStudentId(studentId);
    setFirstName(firstName);
    setLastName(lastName);
    setEmailAddress(emailAddress);
    setAge(age);
    setNumberOfDaysToComplete3Courses(numberOfDaysToComplete3Courses);
    setDegreeProgram(degreeProgram);
};

void Student::setStudentId(string studentId) {
    this->studentId = studentId;
};

void Student::setAge(int age) {
    this->age = age;
};

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
};

void Student::setLastName(string lastName) {
    this->lastName = lastName;
};

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
};

void Student::setNumberOfDaysToComplete3Courses(int numberOfDaysToComplete3Courses[]) {
   
    for(int i = 0; i < size(this->numberOfDaysToComplete3Courses); i++) {
        this->numberOfDaysToComplete3Courses[i] = numberOfDaysToComplete3Courses[i];
    };
};

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
};

string Student::getStudentId() {
    return this->studentId;
};

int Student::getAge() {
    return this->age;
};

string Student::getFirstName() {
    return this->firstName;
};

string Student::getLastName() {
    return this->lastName;
};

string Student::getEmailAddress() {
    return this->emailAddress;
};

string Student::getNumberOfDaysToComplete3Courses() {
    string strNumOfDaysToCompleteCourses;
    
    //Loops through the string to add a comma to seperate the number of days to complete 3 courses
    for(int i = 0; i < 3; i++) {
        strNumOfDaysToCompleteCourses.append(to_string(this->numberOfDaysToComplete3Courses[i]));
        
        //Check is to only add the comma ',' for every element except the last one which is 2 because (num1 = [0], num2 = [1], num3 = [2])
        if(i != 2){
            strNumOfDaysToCompleteCourses.append(",");
        }
    };
    
    return strNumOfDaysToCompleteCourses;
};

string Student::getDegreeProgram() {
    string strDegreeProgram;
    
    switch (this->degreeProgram) {
        case DegreeProgram::SOFTWARE:
            strDegreeProgram = "SOFTWARE";
            break;
        case DegreeProgram::NETWORK:
            strDegreeProgram = "NETWORK";
            break;
        case DegreeProgram::SECURTIY:
            strDegreeProgram = "SECURITY";
            break;
    }
    
    return strDegreeProgram;
};

//Note: Need to fix this to use cout instead to output
string Student::print() {
   return this->getStudentId() + '\t' + this->getFirstName() + '\t' + this->getLastName() + '\t' + to_string(this->getAge()) + '\t' + '{' + this->getNumberOfDaysToComplete3Courses() + '}' + '\t' + this->getDegreeProgram();
};


