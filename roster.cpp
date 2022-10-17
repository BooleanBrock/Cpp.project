#pragma once
#include "degree.h"

void Repo::parse(string types) {
    DegreeProgram dt = DegreeProgram::UNDECIDED;
    if (types.back() == 'K') {
        dt = DegreeProgram::NETWORK;
    }
    else if (types.back() == 'Y') {
        dt = DegreeProgram::SECURITY;
    }
    else if (types.back() == 'E') {
        dt = DegreeProgram::SOFTWARE;
    }

    string parsed[6]; 
    int rhs = 0;
    int lhs = 0;
    for (int i = 0, i < 6; ++i) {
        rhs = types.find(",", lhs);
        parsed[i] = types.substr(lhs, rhs - lhs);
        lhs = rhs + 1;
    }

    add(parsed[0], parsed[1], parsed[2], stoi(parsed[3]), stoi(parsed[4]), stoi(parsed[5]), dt );
}

void Repo::add(string studID, string studFirstName, string studLastName, string studEmail, 
                    int studAge, int studNumDays1, int studNumDays2, int studNumDays3) {

      int numDaysArray[3] = {studNumDays1, studNumDays2, studNumDays3};
      students[++lastInd] = new Student(studID, studFirstName, studLastName, studEmail,
                                 studAge, numDaysArray, dt);    
      cout << "Student added to roster at row " << lastInd + 1 << endl;       
                    }