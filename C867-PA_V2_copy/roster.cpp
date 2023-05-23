//
//  roster.cpp
//  C867-PA
//
//  Created by muhammad chambers on 1/28/23.
//

#include "roster.hpp"
#include <iostream>

Roster::Roster() {
    //Zero Args Constructor
    this->arraySize = 5; //Keeps track of the size of the classRosterArray[]
};

void Roster::setClassRosterArrayWithStudentDataArray(const string STUDENTDATA[]) {
    int parsedStudentDataArraySize = 9;
    string parsedStudentDataArr[parsedStudentDataArraySize];

    //Loops through the STUDENTDATA array to pull each set of students information to the pass into a string
    for(int studentDataTableIndex = 0; studentDataTableIndex < 5; studentDataTableIndex++) {
        string parsedStudentDataStr = this->parseStudentDataTable(STUDENTDATA, studentDataTableIndex);
        
        /*
             Loops through the string holding the set of the student data from the data table array,
             then parses it and places each value inside of an array.
         */
        for(int studentDataArrIndex = 0; studentDataArrIndex < parsedStudentDataArraySize; studentDataArrIndex++) {
            parsedStudentDataArr[studentDataArrIndex] = this->parseStudentDataStr(parsedStudentDataStr, studentDataArrIndex);
        }
        
        //Uses the indexs from the array holding each piece of student data and passed it into the Student constructor to create a Student object
        this->add(parsedStudentDataArr[0], parsedStudentDataArr[1], parsedStudentDataArr[2], parsedStudentDataArr[3], stoi(parsedStudentDataArr[4]), stoi(parsedStudentDataArr[5]), stoi(parsedStudentDataArr[6]), stoi(parsedStudentDataArr[7]), this->convertStrToDegreeProgramEnum(parsedStudentDataArr[8]));
    };
};

Student* Roster::getClassRosterArray() {
    return *classRosterArray;
};

//Returns the specified set of student data at the index to then be parsed
string Roster::parseStudentDataTable(const string studentData[], int index) {
    return studentData[index];
};

//Parses the set of student data, stores it in an array, and returns the value at the specified array index
string Roster::parseStudentDataStr(string studentDataStr, int index) {
    const int ZERO = 0;
    const int ONE = 1;
    int arraySizeForLoop = 0;
    string parsedStudentDataValues[9];
    
    /*
     Overview of code:
        1. Loops through each character in the studentDataStr to find commas ','
        2. If a comma is found, it will find the length of the substring by using the counter index value and the first index
            passing them into the substring method, and assinging the substring to the parsedStudentDataValues[] array index
        3. The substring that was added to the array will be erased using the erase method
        4. Lastly, reset the loops counter back to zero
     
        5. If the array has reached its capacity -1, the last stubstring will be calculated and added to the array, then break out the loop.
     */
    for(int counter = ZERO; counter < studentDataStr.length(); counter++) {

        //Compares each character in the string to find the first comma ','. 
        if(studentDataStr[counter] == ',') {
            
            //Obtains each value in the string seperated by a comma, creates a substring, and assigns the substring to the array
            parsedStudentDataValues[arraySizeForLoop] = studentDataStr.substr(ZERO, counter);
            
            //Erases the substring that was added to the array
            studentDataStr.erase(ZERO, (counter + ONE)); //Added one to include the comma
            
            arraySizeForLoop++; //Increases the array index by +1 for the next substring
            
            /*
                Have to reset the loops counter back to zero after adding each substring to the array.
                Otherwise, the loop will possibly reach the max iterations and stop
                prior to obtaining all substrings and adding to the array.
             */
            counter = ZERO;
        }
        
        /*
            Note: The search above will stop right before the last index because there will be no more commas ','.
            So, added the check below to see if the array has reached it to find the last substring and assign it
            to the last index of the array, then break the loop.
         
            If I didn't have the check below then the loop would keep going until it can't which is a waste since
            it won't be possible for it to obtain the last element for the array.
         */
        if(arraySizeForLoop == size(parsedStudentDataValues) - ONE) {
            parsedStudentDataValues[size(parsedStudentDataValues) - ONE] = studentDataStr.substr(ZERO, size(parsedStudentDataValues) - ONE);
            break;
        }
    };
    
    //Returns the student value at the specified index
    return parsedStudentDataValues[index];
};

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

    //Converts the 3 variables for daysInCourse into an array to be passed into the Student class constructor
    int daysInCourses[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    //Creates a new student object with the inputted parameters from the add method
    Student *studentData = new Student(studentId, firstName, lastName, emailAddress, age, daysInCourses, degreeProgram);
    
    for(int index = 0; index < 5; index++) {
        
        /*
            Checks to see if the element in the Student pointer classRosterArray is empty.
            If it is empty then the Student object will be added at that index of the array.
            Afterwards, the loop will stop.
         */
        if(this->classRosterArray[index] == nullptr) {
            this->classRosterArray[index] = studentData; //The index variable changes the index of the pointer array for each student object
            break;
        }
    };
};

void Roster::printAll() {
    for(int i = 0; i < this->arraySize; i++) {
        
        /*
             Checks if the element in the Student pointer array, classRosterArray, is not NULL.
             If it is not NULL then the print method in the Student class will be called for the object.
         
            Note: Without this NULL check if the method tries printing data for elements in the array which may be NULL,
                which will cause issues.
         */
        if(this->classRosterArray[i] != nullptr){
           cout << this->classRosterArray[i]->print() << endl;
        }
    };
};

void Roster::printAverageDaysInCourse(string studentId) {
    int averageDaysInCourse = 0;
    
    for(int i = 0; i < this->arraySize; i++) {
        
        //First conditional statement checks to ensure the element at index[i] is not NULL
        if(this->classRosterArray[i] != nullptr) {
            
            /*
                Second conditional compares to see if any student id in the Student pointer array matches the student id passed as an argument.
                If it does then it will call the a method that parses the string to convert it into an integer to get the average and returns it.
             */
            if(this->classRosterArray[i]->getStudentId() == studentId) {
                averageDaysInCourse = this->getAvgFromNumberOfDaysToComplete3CoursesStr(this->classRosterArray[i]->getNumberOfDaysToComplete3Courses());
            }
        }
    };
    
    //Note: Just need to output the info now
    cout << "Student ID: " << studentId << ", average days in course is: " << averageDaysInCourse << endl;
};

int Roster::getAvgFromNumberOfDaysToComplete3CoursesStr(string numberOfDaysToComplete3Courses) {
    int loopIndex = 0;
    int indexList[2];
    int strLengths[3];
    int count = 0;
        
    for(int i = loopIndex; i < size(numberOfDaysToComplete3Courses); i++) {
        int searchIndex = 0;
        int lengthOfSubStr = 0;
        
        /*
            Searches each element in the string to find the index the index location of the commas.
            The comma ',' index lcoations will be used in an equation to find the length of the string.
            The comma ',' index and the string length will be used to call the substring method to seperate the numbers.
         */
        if(numberOfDaysToComplete3Courses[i] == ',') {
            searchIndex = i;
            
            //Stores the indexes for the commas ',' in an array to be used in the substring method
            indexList[count] = i;
            
            //Finds the length of the string and stores it in an array to be used in the substring method
            lengthOfSubStr = searchIndex - loopIndex;
            strLengths[count] = lengthOfSubStr;
            count++;
            
            loopIndex = searchIndex + 1; //Note: Had to +1 so that the loop does not start on the index of the comma ','
        }
    }
    
    strLengths[2] = ((int) size(numberOfDaysToComplete3Courses) - indexList[1]) - 1; //Note: to subtract by one to get the accurate length for the last substring
    
    /*
         Gets the substring for each course completion date by using the substring method and setting the start index and string length parameters.
         Then stores the string number for each course in a variable which is converted to an integer to be used
     */
    int course1Days = stoi(numberOfDaysToComplete3Courses.substr(0,strLengths[0]));
    int course2Days = stoi(numberOfDaysToComplete3Courses.substr((indexList[0] + 1),strLengths[1]));
    int course3Days = stoi(numberOfDaysToComplete3Courses.substr((indexList[1] + 1),strLengths[2]));
    
    return (course1Days + course2Days + course3Days) / 3;
};

DegreeProgram Roster::convertStrToDegreeProgramEnum(string degreeProgramStr) {
    DegreeProgram degreeProgram;
    
    //Converts the string for the degreeProgram into the DegreeProgram Enum
    if(degreeProgramStr == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    } else if (degreeProgramStr == "SECURITY") {
        degreeProgram = DegreeProgram::SECURTIY;
    } else {
        degreeProgram = DegreeProgram::NETWORK;
    }
    return degreeProgram;
};


























void Roster::remove(string studentId) {
    for(int index = 0; index < this->arraySize; index++) {
        //If studentId is found in the array then it will 
        if(this->getClassRosterArray()[index].getStudentId() == studentId){
            
            for(int j = 0; j < this->arraySize; j++){
                //Loop will skip this iteration if the index is the same as the studentId to remove
                if(j == index){
                    continue;
                }
               // this->setClassRosterArrayWithStudentObject(this->getClassRosterArray()[index]);
                //Need to design a way to create a new array and copy over the values
            };
        }
    };
    
    this->arraySize--;
};



