#pragma once

#include "student.h"

class Roster {

private: 
        int lastInd = -1;
        const static int numStudents = 5;

        Student* students[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };

public:
    Roster();

    Student** getStudent();

    void parse(string row);

    void add(string studID, string studFirstName, string studLastName, string studEmail, 
                    int studAge, int studNumDays1, int studNumDays2, int studNumDays3 )

    void printAll(); //Will display all students in the table
    void printByDegree();//Will print display student by specific degree type
    void printInvalidEmail();//Will display by invalid student ID
    void printAvgNumDays();//Will display average number of days left in course
    void removeStudById();//remove specified student by their ID            
}