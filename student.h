
#ifndef STUDENT_HEADER
#define STUDENT_HEADER
#include <iostream>
#include <iomanip>
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
        DegreeProgram degreeType;

public:

    Student(); //Default constructor, no parameters

    Student(string studentId, string firstName, string lastName, string email, 
                        int age, int daysInCourse[], DegreeProgram degreeType);

    ~Student(); //Destructor

//Accessors
        string getId();
        string getFirstName();
        string getLastName();
        string getEmail();
        int getAge();
        const int* getDaysInCourse();
        DegreeProgram getDegreeType();

        
        void print();

//Mutators
        void setId(string ID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmail(string email);
        void setAge(int age);
        void setDaysInCourse(const int* daysInCourse);
        void setDegreeType(DegreeProgram degreeType);
};

#endif

/* 
a.  an accessor (i.e., getter) for each instance variable from part D1

b.  a mutator (i.e., setter) for each instance variable from part D1

c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.

d.  constructor using all of the input parameters provided in the table

e.  print() to print specific student data 
*/