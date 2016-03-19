//
//  Student.cpp
//  StudentDatabase
//
//  Created by Brett Meyer on 2/29/16.
//  Copyright © 2016 BDM. All rights reserved.
//

#include <stdio.h>
#include "Student.h"
using namespace std;

Student::Student(int id, int numCourses)
{
    studentID = id;
    nCourses = numCourses;
    gpa = 0;
    vector <Coursetype> Courses;
}
//TODO: Calculate the GPA from the letter grades given in CourseType
float Student::getGPA()
{
    
    return gpa;
}

int Student::getNumCourses()
{
    return nCourses;
}

int Student::getId()
{
    return studentID;
}

//TODO: figure out total GPA * credits
void Student::addStudentCourseInfo(int cNumber, int cCredits, char * g)
{
    Coursetype c;
    c.courseNum = cNumber;
    c.credits = cCredits;
    c.grade = g;
    transform(c.grade.begin(), c.grade.end(), c.grade.begin(), toupper);
    if(c.grade.compare("A")==0)
    {
        
    }
    else if (c.grade.compare("AB")==0)
    {
        
    }
    else if (c.grade.compare("B")==0)
    {
        
    }
    else if (c.grade.compare("BC")==0)
    {
        
    }
    else if (c.grade.compare("C")==0)
    {
        
    }
    else if (c.grade.compare("D")==0)
    {
        
    }
    else
    {
    
    }

    Courses.push_back(c);
}

bool Student::tookCourse(int courseNumber)
{
    return false;
}
