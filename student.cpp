#include <iostream>
#include <string>
using std::string;

#include "student.h"
#include "degree.h"

//Function definitions


//Default constructor
Student::Student(){
this->studentId = "";
this->firstName = "";
this->lastName = "";
this->email = "";
this->age = -1;
for(int i = 0; i < daysInCourse.size(); ++i){
    this->daysInCourse[i] = 0;
}
this->degreeType = DegreeProgram::UNDECIDED;

}


//Alt constructor
Student::Student(string studentId, string firstName, string lastName, string email, 
                        int age, int daysInCourse[], DegreeProgram degreeType); {
          this->studentId = studentId;
          this->firstName = firstName;
          this->lastName = lastName;
          this->email = email;
          this->age = age;
          for (int i = 0; i < daysInCourse.size(); ++i) this->daysInCourse[i] = daysInCourse[i];
          this->degreeType = degType;
                    }

//Accessor definitions
 string Student::getId(){
    return this->studentId;
 }                   
 string Student::getFirstName(){
    return this->firstName;
 }
 string Student::getLastName(){
    return this->lastName;
 }
 string Student::getEmail(){
    return this->email;
 }
 int Student::getAge(){
    return this->age;
 }
 const int* Student::getDaysInCourse(){
    return this->daysInCourse;
 }
 DegreeProgram Student::getDegreeType(){
    return this->degreeType;
 }

void Student::printTableHeader(){
    cout << "Student ID\t";
    cout << "First Name\t";
    cout << "Last Name\t";
    cout << "Email\t";
    cout << "Days in Course\t";
    cout << "Degree Type\t";
    cout << endl;
}

void Student::print(){
    //add function here!
    cout << this->studentId <<'\t';
    cout << this->firstName <<'\t';
    cout << this->lastName <<'\t';
    cout << this->email <<'\t';
    cout << this->age <<'\t';
    cout << this->daysInCourse[0] <<'\t';
    cout << this->daysInCourse[1] <<'\t';
    cout << this->daysInCourse[2] <<'\t';
    cout << degreeTypeStrings[(int)this->degreeType];
    cout << endl;
}
 


 //Mutator definitions
void Student::setId(string studentId){
    this->studentId = studentId;
 }
void Student::setFirstName(string firstName){
    this->firstName = firstName;
}
void Student::setLastName(string lastName){
    this->lastName = lastName;
}
void Student::setEmail(string email){
    this->email = email;
}
void Student::setAge(int age){
    this->age = age;
}
void Student::setDaysInCourse(const int daysInCourse[]){
    for (int i = 0; i < daysInCourse.size(); ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}
void Student::setDegreeType(DegreeProgram degreeType){
    this->degreeType = degreeType;
}


//Deconstructor
Student::~Student() {}