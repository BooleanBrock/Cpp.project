
#ifndef STUDENT_HEADER
#define STUDENT_HEADER
#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
using std::string;

//Student function declarations
class Student
{

public: 
//Days to complete course is always 3 integers
        const static int daysCourseArrSize = 3;

private:
//All private info that is not to be accessible by user
        string studentId;
        string firstName;
        string lastName;
        string email;
        int age;
        int daysInCourse[daysCourseArrSize]; //days in course will be an array of size 3
        DegreeProgram degreeType;

public:

    Student(); //Default constructor, no parameters

    //Alt constructor that accepts student info as arguments to parameters
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

