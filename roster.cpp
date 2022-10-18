
#include "degree.h"
#include "roster.h"
#include "student.cpp"
#include <string>

using namespace std;


void Roster::parse(string studentInfo) {
    DegreeProgram dt = DegreeProgram::UNDECIDED; 
    //Parse by last letter
    if (studentInfo.back() == 'K') {
        dt = DegreeProgram::NETWORK;
    }
    else if (studentInfo.back() == 'Y') {
        dt = DegreeProgram::SECURITY;
    }
    else if (studentInfo.back() == 'E') {
        dt = DegreeProgram::SOFTWARE;
    }

    string parsed[9]; //Create tokens

    //Create left and righthand side separated by commas
    int rhs = 0;
    int lhs = 0;
    for (int i = 0; i < 9; i++) {
        rhs = studentInfo.find(",", lhs);
        parsed[i] = studentInfo.substr(lhs, rhs - lhs);
        lhs = rhs + 1;
    }
    
    add(parsed[0], parsed[1], parsed[2], (parsed[3]), stoi(parsed[4]), stoi(parsed[5]), stoi(parsed[6]), stoi(parsed[7]), dt );
}

void Roster::add(string studID, string studFirstName, string studLastName, string studEmail, 
                    int studAge, int studNumDays1, int studNumDays2, int studNumDays3, DegreeProgram dt) {

      int numDaysArray[3] = {studNumDays1, studNumDays2, studNumDays3};
      classRosterArray[++lastInd] = new Student(studID, studFirstName, studLastName, studEmail,
                                 studAge, numDaysArray, dt);    
      cout << "Student added to roster at row " << lastInd + 1 << endl;       
                    }

void Roster::printAll() {
    
    Student::printTableHeader(); //From Student class
    for (int i = 0; i <= Roster::lastInd; i++) {
        Roster::classRosterArray[i]->print(); //Students will be displayed 
    }
}                

void Roster::printByDegree(DegreeProgram dt){
        Student::printTableHeader();
        for (int i = 0; i <= Roster::lastInd; i++) {
            if(Roster::classRosterArray[i]->getDegreeType() == dt) {
                classRosterArray[i]->print();
            }
        }
}

void Roster::printInvalidEmail() {
        bool found = false; //Assume that all emails are valid

        for (int i = 0; i <= Roster::lastInd; i++) {

            //Get email and check it for proper format
            string email = Roster::classRosterArray[i]->getEmail();
            if (email.find(' ') != string::npos || email.find("@") == string::npos || email.find(".") == string::npos){

            found = true; //invalid address found

            cout << email << " is invalid." << endl;// Print email that is invalid
            }
        } 

        if(!found) {
            cout << "None found" << endl; // prints if all emails are valid
        }
}

void Roster::printAvgNumDays(string studID) {

    for (int i = 0; i <= Roster::lastInd; i++) {
        
        if(classRosterArray[i]->getId() == studID) {
            cout << studID << ":";
            cout << (classRosterArray[i]->getDaysInCourse()[0] 
             + classRosterArray[i]->getDaysInCourse()[1]
             + classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << endl;
        }
    }
}

void Roster::removeStudentById(string studID){
        
        bool found = false;//Assume student is not found

        for(int i = 0; i <= Roster::lastInd; i++) {

        if(classRosterArray[i]->getId() == studID) {
            //Student found
            found = true; 
            //Swap student out with last one
            Student* temp = classRosterArray[i];
            classRosterArray[i] = classRosterArray[numStudents - 1];
            classRosterArray[numStudents - 1] = temp;
            //The student will not appear again as lastInd is decremented 
            Roster::lastInd--;

        }
        }
    if (found) {
        cout << "Student " << studID << " removed." << endl;
    }
    else cout << "Student " << studID << " not found" << endl;
}

    Roster::~Roster(){

    for (int i = 0; i < numStudents; i++) {
        //Anonounce destruction of each student
        cout << "Destructor called for " << classRosterArray[i]->getId() << endl;
        delete classRosterArray[i]; // Destroy each student record
        classRosterArray[i] = nullptr;//After destruction, set each student pointer to null
    }
}