#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student
{

public: 
        const static int daysCourseArrSize = 3;

private:
        string studentId;
        string firstName;
        string lastName;
        string email;
        int age;
        int daysInCourse[daysCourseArrSize]; //days in course will be an array of size 3
        DegreeProgram degType;

public:

    Student(); //empty constructor
    Student(string ID, string fName, string lName, string email, int age, int daysInCoure[]);

    string GetID();
    string GetFName()
    string GetAuthor();

}