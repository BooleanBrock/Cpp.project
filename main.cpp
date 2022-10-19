#include <iostream>
#include <iomanip>
#include "roster.h"
//#include "student.h"
//#include "degree.h"
using std::cout;
int main(){

cout << "------------------------------------" << std::endl;
cout << "C867 Scripting and Programming" << std::endl;
cout << "Using C++" << std::endl;
//cout << enter student id << std::endl;
cout << "Wyatt Brock" << std::endl;
cout << "-------------------------------------" << std::endl;

//student data to be parsed and create student objects
string studentData[] =

{
"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Wyatt,Brock,wyattbrock7@gmail.com,26,12,25,30,SOFTWARE"
};


const int numStudents = 5;

Roster classRoster;//Creates roster default constructor and parses data
//Parse data, create student objects and add them to array 
for (int i = 0; i < numStudents; i++){
    classRoster.parse(studentData[i]);
}

//Shows all students
cout << std::endl << "Displaying all students:" << std::endl;
classRoster.printAll();

//Shows all invalid emails
cout << "Displaying students with invalid emails: " << std::endl << std::endl;
classRoster.printInvalidEmail();
cout << std::endl;

//Shows average number of days in course for each student.
cout << "Displaying average days in course for each student: " << std::endl << std::endl;
for (int i = 0; i < numStudents; i++) {
    
    classRoster.printAvgNumDays(classRoster.classRosterArray[i]->getId());
    cout << std::endl;
}

//Separates students by degree program
 
    cout << std::endl << "Displaying each student by degree program: " <<  std::endl;
    classRoster.printByDegree((DegreeProgram::SOFTWARE));
 

//Remove student
cout << "Removing student A3: " << std::endl;
classRoster.removeStudentById("A3");
cout << std::endl;

//Display new table without student A3
cout << "Displaying new student data table: " << std::endl;
classRoster.printAll();

//Attempt to remove student and will show that none were found
classRoster.removeStudentById("A3");
cout << std::endl;

cout << "Task complete. Destructor called upon exit." << std::endl;


return 0;
};





/*Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:

1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.

2.  Create an instance of the Roster class called classRoster.

3.  Add each student to classRoster.

4.  Convert the following pseudo code to complete the rest of the  main() function:

classRoster.printAll();

classRoster.printInvalidEmails();

 

//loop through classRosterArray and for each element:

classRoster.printAverageDaysInCourse(/*current_object's student id



Note: For the current_object's student id, use an accessor (i.e., getter) for the classRosterArray to access the student id.



classRoster.printByDegreeProgram(SOFTWARE);

classRoster.remove("A3");

classRoster.printAll();

classRoster.remove("A3");

//expected: the above line should print a message saying such a student with this ID was not found.

5.  Implement the destructor to release the memory that was allocated dynamically in Roster.*/