#pragma once
#include "degree.h"
#include "roster.h"
#include "student.cpp"

void Roster::parse(string types) {
    DegreeProgram dt = DegreeProgram::UNDECIDED; 
    //Parse by last letter
    if (types.back() == 'K') {
        dt = DegreeProgram::NETWORK;
    }
    else if (types.back() == 'Y') {
        dt = DegreeProgram::SECURITY;
    }
    else if (types.back() == 'E') {
        dt = DegreeProgram::SOFTWARE;
    }

    string parsed[6]; //Create tokens

    //Create left and righthand side separated by commas
    int rhs = 0;
    int lhs = 0;
    for (int i = 0, i < 6; ++i) {
        rhs = types.find(",", lhs);
        parsed[i] = types.substr(lhs, rhs - lhs);
        lhs = rhs + 1;
    }
    //Parse data and convert string to integer
    add(parsed[0], parsed[1], parsed[2], stoi(parsed[3]), stoi(parsed[4]), stoi(parsed[5]), dt );
}

void Roster::add(string studID, string studFirstName, string studLastName, string studEmail, 
                    int studAge, int studNumDays1, int studNumDays2, int studNumDays3) {

      int numDaysArray[3] = {studNumDays1, studNumDays2, studNumDays3};
      students[++lastInd] = new Student(studID, studFirstName, studLastName, studEmail,
                                 studAge, numDaysArray, dt);    
      cout << "Student added to roster at row " << lastInd + 1 << endl;       
                    }

void Roster::printAll() {
    
    Student::printHeader(); //From Student class
    for (int i = 0; i <= Roster::lastInd; ++i) {
        Roster::students[i]->print(); //Students will be displayed 
    }
}                

void Roster::printByDegree(DegreeProgram dt){
        Student::printHeader();
        for (int i = 0; i <= Roster::lastInd; ++i) {
            if(Roster::students[i]->getDegreeType() == dt) {
                students[i]->print();
            }
        }
}

void Roster::printInvalidEmail() {
        bool found = false; //Assume that all emails are valid

        for (int i = 0; i <= Roster::lastInd; ++i) {

            //Get email and check it for proper format
            string email = Roster::getStudent()[i]->getEmail();
            if (id.find(' ') != string::npos || id.find("@") == string:npos || id.find(".") == string::npos){

            found = true; //invalid address found

            cout << email << " is invalid." << endl;// Print email that is invalid
            }
        } 

        if(!found) {
            cout << "None found" << endl; // prints if all emails are valid
        }
}

void Roster::printAvgNumDays(string studID) {

    for (int i = o; i <= Roster::lastInd; ++i) {
        
        if(students[i]->getId() == studID) {
            cout << studID << ":";
            cout << (students[i]->getDaysInCourse()[0] + students[i]->getDaysInCourse()[1]
             + students[i]->getDaysInCourse()[2]) / 3.0 << endl;
        }
    }
}

