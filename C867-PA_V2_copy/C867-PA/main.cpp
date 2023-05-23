//
//  main.cpp
//  C867-PA
//
//  Created by muhammad chambers on 1/28/23.
//

#include <iostream>
#include "student.hpp"
#include "roster.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
     const string STUDENTDATA[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_19990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_Lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Muhammad,Chambers,mcha581@wgu.edu,23,10,15,5,SOFTWARE"
    };
    


   
    Roster rs;
    rs.setClassRosterArrayWithStudentDataArray(STUDENTDATA);
    rs.printAll();
    cout << endl;
    rs.printAverageDaysInCourse("A3");
    





  

    


    return 0;
}
